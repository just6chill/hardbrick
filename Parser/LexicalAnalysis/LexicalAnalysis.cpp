//
// Created by justi on 01.05.2021.
//
#include <iostream>
#include <string>
#include <vector>
#include "LexicalAnalysis.h"
#include "../../Global/Global.h"

namespace Global{
    std::vector<std::vector<char>> Tokens;
}

namespace Parser {

    int LexicalAnalysis::Tokenize() {

        std::string Temp;
        bool flag = true;
        int tokencounter = 0;
        int counter = 0;
        int code;

        for (const char &c : Global::Code){
            repeat:
            if (flag){
                code = Global::Table[counter];
                Temp.clear();
            }
            flag = false;
            if (code == Global::Table[counter]) {
                Temp.push_back(c);
            } else {
                std::vector<char> increase;
                Global::Tokens.push_back(increase);
                Global::Tokens[tokencounter].clear();
                for (char Temp_C : Temp) {
                    Global::Tokens[tokencounter].push_back(Temp_C);
                }
                tokencounter++;
                flag = true;
                goto repeat;
            }
            counter++;
        }
        return 0;
    }

    int LexicalAnalysis::Assign() {
        return 0;
    }
}