#include <iostream>
#include <string>
#include <fstream>
#include <istream>
// #include <windows.h>
#include <sstream> 

#include "config.h"
#include "language.h"
// std::string get_line_n(const std::string& filename, size_t n){
//     std::ifstream f(filename);
//     std::string line;
//     while (std::getline(f, line) && n-- > 0);
//     f.close();
//     return line;
// }
// std::string get_word_n(std::string str , int n, char sep){
//     std::string temp;
//     std::stringstream ss(str);
//     int i = 0;
//     while(std::getline(ss, temp, sep)){
//         i++;
//         if(n == i)
//             return temp;
//     }
//     return "ERROR_STR";
// }
std::string splitting (std::string* a, int  m){
        std::string rec;
        int len = (*a).length();
        for (unsigned short i = m; i<len; i++)
            rec += (*a)[i];
        for (unsigned short i = 0; i<(len-m); i++)
            (*a).pop_back();
    return rec;
}

int main(){
    /*Windows setting*/
    // SetConsoleCP(2251);
    // SetConsoleOutputCP(2251);

    /*initializing the configuration*/
    const unsigned int N = len_tape;
    const unsigned int OO = 10000;      //very big number

    /*variables*/
    std::string command;                //the current command
    char* cell = new char[N];           //the array of cells (this is a numeric data type / was "cell: array of shortint")
    std::string program1;               //the current program
    char* str = new char[OO];           //to fstream
    unsigned short cycle;               //len current program
    char command_program;               //the current command of the executable program
    unsigned short current_cell = 0;    //the current cell
    signed short nesting = 0;           //to control the nesting of cycles
    unsigned short  n;                  //the program cycle number
    std::string name;                   //file name
    bool flag_dbg = 0;                  //debugging mode flag
    bool* cell_dbg = new bool[N];       //recording visits to tape cells

    /*menu*/
    std::cout << txt_menu;

    /*command line*/
    while (true){
        for (unsigned short i = 0; i<N; i++)
            cell[i] = 0;
        std::cin >> command;
        if (command == "new"){ //creating a new program
            std::cout << txt_new;
            std::cin.getline(str, 1);
            str[0] = 0;
            std::cin.getline(str, OO, '!');
            program1 = str;
        }
        if (command == "open"){
            std::cout << txt_open;
            std::cin >> name;
            std::ifstream f (name);
            f.getline(str, OO, '\0');
            f.close();
            program1 = str;
            std::cout << program1 << std::endl;
        }
        if (command == "sev"){
            std::cout << txt_open;
            std::cin >> name;
            std::ofstream f;
            f.open(name);
            f << program1 << std::endl;
            f.close();
        }
        if (command == "edit"){
            std::cout << txt_edit;
            std::cout << program1 << std::endl;
            while (true){
                std::cin >> command;
                if (command == "del"){
                    std::cin >> n;
                    if (n <= program1.length()){
                        std::string a = splitting (&program1, n);
                        program1.pop_back();
                        program1 += a;
                    };
                }
                if (command == "in"){
                    std::cin >> n;
                    std::cin >> command_program;
                    if (n <= program1.length()+1){
                        if (n <= program1.length()){
                            std::string a = splitting (&program1, n-1);
                            program1 += command_program;
                            program1 += a;
                        }
                        else program1 += command_program;
                    };
                }
                if (command == "re"){
                    std::cin >> n;
                    std::cin >> command_program;
                    if (n <= program1.length()){
                        program1[n-1] = command_program;
                    };
                }
                if (command == "end"){
                    break;
                }
                std::cout << program1 << std::endl;
            }
        }
        if (command == "run" || command == "debug"){
            n = 0;
            cycle = program1.length();
            if (command == "debug"){
                std::cout << txt_debug;
                flag_dbg = 1;
                for(unsigned short i = 0; i<N; i++)
                    cell_dbg[i] = false;
            }
            /*program execution*/
            do{
                if (flag_dbg){
                    cell_dbg[current_cell] = true;
                    std::cout << txt_debug_1 << program1[n] << " , " << n << std::endl;
                    std::cout << txt_debug_2 << current_cell << std::endl;
                    for (unsigned short i = 0; i<N; i++)
                        if (cell_dbg[i])
                            std::cout << "cell[" << i << "] = " << int(cell[i]) << txt_debug_3 << cell[i] << " " << std::endl;
                    std::cout << std::endl;
                    std::cin >> command;
                    if (command == "break"){
                        flag_dbg = false;
                        break;
                    }
                }
                command_program = program1[n];
                if (command_program == '>'){
                    if (current_cell == N-1)
                        current_cell = 0;
                    else current_cell++;
                }
                if (command_program == '<'){
                    if (current_cell == 0)
                        current_cell = N-1;
                    else current_cell--;
                }
                if (command_program == '+')
                    cell[current_cell]++;
                if (command_program == '-')
                    cell[current_cell]--;
                if (command_program == '['){
                    nesting++;
                    if (cell[current_cell] == 0)
                        do{
                            n++;
                            command_program = program1[n];
                            if (command_program == ']')
                                nesting--;
                            if (command_program == '[')
                                nesting++;
                            if (nesting == 0)
                                break;
                        } while (!(n == cycle));
                }
                if (command_program == ']'){
                    nesting--;
                    if (cell[current_cell] != 0)
                        do{
                            n--;
                            command_program = program1[n];
                            if (command_program == ']')
                                nesting--;
                            if (command_program == '[')
                                nesting++;
                            if (nesting == 0)
                                break;
                        } while (!(n == 1));
                }
                if (command_program == '.')
                    std::cout << cell[current_cell];
                if (command_program == ',')
                    std::cin >> cell[current_cell];
                n++;
            } while (!(n == cycle));
            std::cout << std::endl;
        }
        if (command == "info"){
            std::string info;
            std::ifstream f ("info");
            f.getline(str, OO, '\0');
            f.close();
            info = str;
            std::cout << info << std::endl;
        }
        if (command == "menu"){
            std::cout << txt_menu;
        };
        if (command == "setting"){
            std::cout << txt_setting;
            while (true){
                std::cin >> command;
                if (command == "language"){
                    std::cout << txt_setting_1;
                    std::cin >> command;
                    if (command == "ru" || command == "en")
                        1;
                    else 
                        std::cout << txt_warming;
                };
                if (command == "end"){
                    break;
                };
            };
        };
        if (command == "exit")
            break;
    }
    delete[] cell_dbg;
    delete[] cell;
    delete[] str;
    return 0;
}

