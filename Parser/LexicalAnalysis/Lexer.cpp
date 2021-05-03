//
// Created by justi on 01.05.2021.
//
#include <iostream>
#include <string>
#include <vector>
#include "LexicalAnalysis.h"

namespace Parser {

    int LexicalAnalysis::Tokenize(std::vector<char> &Code, std::vector<int> &Table) {

        std::string Temp;
        bool flag = true;
        int tokencounter = 0;
        int counter = 0;
        int code;

        for (const char &c : Code){
            repeat:
            if (flag){
                code = Table[counter];
                Temp.clear();
            }
            flag = false;
            if ((code == Table[counter]) && (code == 4)) {
                Temp.push_back(c);
            } else {
                std::vector<char> increase;
                Tokens.push_back(increase);
                Tokens[tokencounter].clear();
                for (char Temp_C : Temp) {
                    Tokens[tokencounter].push_back(Temp_C);
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