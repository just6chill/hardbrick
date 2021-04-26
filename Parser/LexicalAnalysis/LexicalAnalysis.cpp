//
// Created by justi on 25.04.2021.
//

#include "LexicalAnalysis.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


int Table[100];
int TableCounter = 0;

namespace Lexer{

    Lex::Lex(std::string_view file) {
        ReadFile(file);
    }

    int Lex::ReadFile(std::string_view filename) {

        std::ifstream file(filename.data());
        std::string line;
        while (std::getline(file, line)) {
            Tokenize(line);
        }
        return 0;
    }

    char Lex::Tokenize(std::string &line) {

        std::cout << "we here" << std::endl;

        char keywords[10][10] = {"num", "func", "if", "else", "print", "loop", "while", "\0"};


        //1
        char operators[] = {'\n', '+', '-', '*', '/', '=', '\0'};

        //2
        char symbols[] = {'.', ',', ';', ' ', '\0'};

        //3
        char brackets[] = {'{', '}', '(', ')', '\0'};

        //4 = letter 5= digit

        for (const char c : line) {
            for (const char o : operators) {
                if (c == o) {
                    Table[TableCounter] = 1;
                }
            }
            for (const char s : symbols) {
                if (c == s) {
                    Table[TableCounter] = 2;
                }
            }
            for (const char b : brackets) {
                if (c == b) {
                    Table[TableCounter] = 3;
                }
            }
            if (std::isalpha(c)) {
                Table[TableCounter] = 4;
            } else if (std::isdigit(c)) {
                Table[TableCounter] = 5;
            }

            TableCounter++;
        }

        std::cout << "the line is" << std::endl << line << std::endl;

        std::cout << "types:" << std::endl;
        std::cout << line << std::endl;

        for (const int n : Table) {

            switch (n) {
                case 1: std::cout << "o"; break;
                case 2: std::cout << "s"; break;
                case 3: std::cout << "b"; break;
                case 4: std::cout << "c"; break;
                case 5: std::cout << "n"; break;
            }
        }

        return 0;
    }
}