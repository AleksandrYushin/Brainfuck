#include "config.h"

#ifdef language_ru
#define txt_menu "Это компилятор Brainfuck. Есть следующие команды\nnew     создание новой программы\nopen    открытие программы\nsev     сохранение открытой программы\nedit    редактирование открытой программы\nrun     запуск открытой программы\ndebug   запуск открытой программы в режиме отладки\ninfo    синтаксис языка\nmenu    выход в меню\nsetting настройки конфигурации\nexit    выход из программы\n"
#define txt_new "Ведите новую программу. Символ '!' оканчивает ввод\n"
#define txt_open "Ведите название файла\n"
#define txt_edit "in - вставить, del - удалить, re - изменить, end - закончить. При ведении in, del, re сначало водить номер символа.\n"
#define txt_debug "В режиме отладки. break - прекращение исполнения, y - шаг.\n"
#define txt_debug_1 "Команда программы и её номер:"
#define txt_debug_2 "Текущая ячейка:"
#define txt_debug_3 ", как символ:"
#define txt_setting "Настройки компилятора: language - изменить язык, config - изменить параметры компилятора, end - закончить.\n"
#define txt_setting_1 "Выберете язык: en - english, ru - русский.\n"
#define txt_warming "Неверная команда.\n"
#define txt_error_syntax "Нарушено закрытие циклов.\n"
#endif

#ifdef language_en
#define txt_menu "This is the Brainfuck compiler. There are the following commands\nnew     creating a new program\nopen     opening a program\nsev     saving an open program\nedit     editing an open program\nrun     launching an open program\ndebug     launching an open program in debug mode\ninfo     language syntax\nmenu     exiting the menu\nsetting     configuration settings\nexit     exiting the program\n"
#define txt_new "Run a new program. The '!' character ends the input\n"
#define txt_open "Enter the file name\n"
#define txt_edit "in - insert, del - delete, re - replace, end - finish. When doing in, del, re, first enter the character number.\n"
#define txt_debug "In debugging mode. break - termination of execution, y - step.\n"
#define txt_debug_1 "Program command and its number:"
#define txt_debug_2 "Current cell:"
#define txt_debug_3 ", как символ:"
#define txt_setting "Настройки компилятора: language - изменить язык, config - изменить параметры компилятора, end - закончить.\n"
#define txt_setting_1 "Выберете язык: en - english, ru - русский.\n"
#define txt_warming "Неверная команда.\n"
#define txt_error_syntax "Нарушено закрытие циклов.\n"
#endif 