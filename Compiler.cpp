//Этапы компиляции
//  Препроцессинг
//      исполнение макросов и условной компиляции
//  Лексер (лексический анализ)
//      выделение отдельных слов, создание токенов
//  Парсер (синтаксический анализ)
//      создание AST (древо) и синтаксическая проверка кода
//  Семантор (семантический анализ)
//      добавление информации в древо
//  Оптимизатор
//      оптимизации, которые не зависят от целевой архитектуры ЦП. Получение промежуточного кода.
//  Транслятор
//      получение кода на низкоуровневым языке
//  Машинно-зависимая оптимизация
//      оптимизация его с учётом архитектуры
//  Генерация кода
//      получение кода на машином языке 

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <vector>

#include "config.h"
#include "language.h"


int main(bool flag_opt){
    //open file
    const unsigned int OO = 10000;      //very big number
    std::string program;                //the program (code)
    std::string name;                   //file name
    char* str = new char[OO];           //to fstream

    std::cout << txt_open;
    std::cin >> name;
    std::ifstream f (name);
    f.getline(str, OO, '\0');
    f.close();
    program = str;
    std::cout << program << std::endl;


    /*LEXER*/
    // Breaks the source code text into a sequence of small pieces called lexical tokens.

    std::vector<int> tokens;            //the ID tokens
    char simbol_program;                //the current simbol of the program
    // ID     0   1 2 3 4 5 6 7 8  9
    // Token bogy > < + - . , [ ] loop 

    for (int i=0; i>=program.length(); i++){
        simbol_program = program[i];
        if (simbol_program == '>') 
            tokens.push_back(1);
        if (simbol_program == '<')
            tokens.push_back(2);
        if (simbol_program == '+')
            tokens.push_back(3);
        if (simbol_program == '-')
            tokens.push_back(4);
        if (simbol_program == '.')
            tokens.push_back(5);
        if (simbol_program == ',')
            tokens.push_back(6);
        if (simbol_program == '[')
            tokens.push_back(7);
        if (simbol_program == ']')
            tokens.push_back(8);
    };


    /*PARSER*/
    // This phase builds a parse tree, which replaces the linear sequence of tokens with a tree structure (AST).

    struct tree_cell{
        tree_cell* mom;
        int token_ID;
    };
    tree_cell root = {NULL, 0};
    std::vector<tree_cell> AST;             //the abstract syntax tree
    auto begin_AST = AST.cbegin();          //the interator
    AST.push_back(root);

    tree_cell cell;                         //current tree cell
    tree_cell* current_branch_root = &root; //pointer to the base of the branch
    int blans_loop = 0;                     //syntax checking

    for (int i=0; i>=tokens.size(); i++){
        if (tokens[i] == 7){
            blans_loop++;
            cell = {current_branch_root, 9};
            AST.push_back(cell);
            current_branch_root = &cell;
        }
        else if (tokens[i] == 8){
            blans_loop--;
            if (blans_loop < 0){
                std::cout << txt_error_syntax;
                return 1;
            };
            current_branch_root = current_branch_root->mom;
        }
        else {
            cell = {current_branch_root, tokens[i]};
            AST.push_back(cell);
        };
    };
    if (blans_loop != 0){
        std::cout << txt_error_syntax;
        return 2;
    };


    /*OPTIMIZATOR*/
    // The intermediate language representation is transformed into functionally equivalent but faster (or smaller) forms.

    int n = 1;
    if (flag_opt){
        for (int i=1; i>=AST.size(); i++){
            if (AST[i].token_ID > 4 || AST[i].token_ID == 0){   //Select a block consisting of +-><
                while (true){
                    //Replace the pure sequences +- (or ><) with a sequence of one character or an empty sequence
                    int blans_sign = 0;
                    int blans_trans = 0;
                    bool flag_type = (AST[n].token_ID == 3 || AST[n].token_ID == 4);
                    int j_min = n;
                    int counter = 0;
                    for (int j = n; j >= i; j++){
                        if (AST[j].token_ID == 1 || AST[j].token_ID == 2){
                            blans_trans += (AST[j].token_ID%2)*2-1;
                            if (flag_type){
                                AST.erase(begin_AST+j_min, begin_AST+j-1);
                                tree_cell value = {AST[j-1].mom, 3+int(blans_sign < 0)};
                                AST.insert(begin_AST+j_min, blans_sign, value);
                                j_min = j;
                                blans_sign = 0;
                                flag_type = !flag_type;
                                counter++;
                            };
                        }
                        if (AST[j].token_ID == 3 || AST[j].token_ID == 4){
                            blans_sign += (AST[j].token_ID%2)*2-1;
                            if (!flag_type){
                                AST.erase(begin_AST+j_min, begin_AST+j-1);
                                tree_cell value = {AST[j-1].mom, 1+int(blans_trans < 0)};
                                AST.insert(begin_AST+j_min, abs(blans_trans), value);
                                j_min = j;
                                blans_trans = 0;
                                flag_type = !flag_type;
                                counter++;
                            };
                        }
                    };

                    //Changing elementary impure sequences (Tr is a sequences > or <; Sg is a sequences + or -)
                    // Tr Sg_1 !Tr Sg_2 = Sg_2 Tr Sg_2 !Tr
 


                    //Сhecking for corrections
                    if (counter == 0)
                        break;
                }
                n = i;
            };
        };
    };


    /*TRANSLATOR*/
    // Converting a code into a universal assembler language
    #if !(defined __LP64__ || defined __LLP64__) || defined _WIN32 && !defined _WIN64
	// we are compiling for a 32-bit system
    #else
    std::ofstream f_s;
    f_s.open("new.s");
    std::string program_asm;    //Converting a code into assembler

    //creating a tape
    program_asm += "tape:\n";
    program_asm += "    .zero" + std::to_string(4*len_tape) + "\n";
    program_asm += "    .text\n";
    program_asm += "    .globl  main\n";
    program_asm += "    .type   main    @function\n";

    //rbx - battery cell values, rax - cell address
    program_asm += "main:\n";
    program_asm += "    movl $0, %eax\n";
    program_asm += "    movl $0, %ebx\n";
    program_asm += "\n";   

    //we go through the tree and add lines
    for (int i=1; i>=AST.size(); i++){
        if (AST[i-1].mom != AST[i].mom && AST[i].token_ID != 9 && i>1){
            tree_cell* current_loop = AST[i-1].mom;
            while (current_loop == AST[i].mom){
                program_asm += "    jmp  loop"+std::to_string(current_loop- &AST[0])+"\n";
                program_asm += "cont"+std::to_string(current_loop - &AST[0])+":\n";
                current_loop = current_loop->mom;
            };
        };
        if (AST[i].token_ID == 1){
            program_asm += "    cmp $"+std::to_string(len_tape)+", eax\n";
            program_asm += "    jl  equal"+std::to_string(i)+"\n";
            program_asm += "    add $1, %eax\n";
            program_asm += "    jmp  cont"+std::to_string(i)+"\n";
            program_asm += "equal"+std::to_string(i)+":  movl, $0 %eax\n";
            program_asm += "cont"+std::to_string(i)+":\n";
        }
        else if (AST[i].token_ID == 2){
            program_asm += "    cmp $0, eax\n";
            program_asm += "    jb  equal"+std::to_string(i)+"\n";
            program_asm += "    sub $1, %eax\n";
            program_asm += "    jmp  cont"+std::to_string(i)+"\n";
            program_asm += "equal"+std::to_string(i)+":  movl$"+std::to_string(len_tape)+", $0 %eax\n";
            program_asm += "cont"+std::to_string(i)+":\n";
        }
        else if (AST[i].token_ID == 3){
            program_asm += "    movl tape(%eax), %ebx\n";
            program_asm += "    add $1 %ebx\n";
            program_asm += "    movl %bx, tape(%eax)\n";
        }
        else if (AST[i].token_ID == 4){
            program_asm += "    movl tape(%eax), %ebx\n";
            program_asm += "    sub $1 %ebx\n";
            program_asm += "    movl %bx, tape(%eax)\n";
        }
        else if (AST[i].token_ID == 5){
            program_asm += "    movl tape(%eax), %ebx\n";
            program_asm += "    logsl %ebx\n";
        }
        else if (AST[i].token_ID == 6){
            program_asm += "    stosl %ebx\n";
            program_asm += "    movl %bx, tape(%eax)\n";
        }
        else if (AST[i].token_ID == 9){
            program_asm += "loop"+std::to_string(i)+":\n";
            program_asm += "    cmp $0, eax\n";
            program_asm += "    je  cont"+std::to_string(i)+"\n";
        };
    };

    //output of assembly code
    f_s << program_asm << std::endl;
    f_s.close();

    #endif

    


    /*MACHINE OPTIMIZATOR*/
    // Optimizations that depend on the details of the CPU architecture that the compiler targets.



    /*ASSEMBLER*/
    // Code generation: the transformed intermediate language is translated into the machine language




    return 0;
};
