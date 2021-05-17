//
// Created by justi on 01.05.2021.
//
#include <string>
#include <vector>
#include "LexicalAnalysis.h"

namespace Analysis {

    int LexicalAnalysis::Tokenize(std::vector<char> &Code, std::vector<int> &Table) {

        std::string Temp;
        int tokencounter = 0;
        int counter = 0;

        for (const char &c : Code) {

            if ((Table[counter] != 4) && (Table[counter] != 5) && (Table[counter] != 10)) {
                std::vector<char> increase;
                Tokens.push_back(increase);
                for (char Temp_C : Temp) {
                    Tokens[tokencounter].push_back(Temp_C);
                }
                tokencounter++;
                Temp.clear();
                Tokens.push_back(increase);
                Tokens[tokencounter].push_back(c);
                tokencounter++;
            } else {
                Temp.push_back(c);
            }
            counter++;
        }
        return 0;
    }

    int LexicalAnalysis::SpaceHandle() {

       for(std::size_t i = 0; i < Tokens.size(); ++i) {

           auto it = Tokens.begin() + i;
           auto index = it->begin();
           if (Tokens[i].size() == 0) {
               Tokens.erase(it);
           }
       }

       bool flag = false;

       for(std::size_t i = 0; i < Tokens.size(); ++i) {

           auto it = Tokens.begin() + i;
           auto index = it->begin() + 0;


               if (*index == ' ') {
                   Tokens.erase(it);
                   i--;
               }

       }

       return 0;
    }

    int LexicalAnalysis::Assign() {

        std::string operators = "+-*/=";
        std::string symbols = "#'$%&!/\\:.,;";
        std::string brackets = "(){}[]";

        for (auto &row : Tokens) {

            if (row[0] == '\"') {
                Types.push_back(10);
            }
            for (auto o : operators) {
                if (row[0] == o) {
                    Types.push_back(0);
                }
            }
            for (auto s : symbols) {
                if (row[0] == s) {
                    Types.push_back(1);
                }
            }
            for (auto b : brackets) {
                if (row[0] == b) {
                    Types.push_back(2);
                }
            }

            if (row[0] == ' '){
                Types.push_back(3);
            } else if (std::isdigit(row[0])) {
                Types.push_back(4);
            } else if (std::isalpha(row[0])) {
                Types.push_back(5);
            }
        }

        std::vector<std::string> Keywords = {"for", "foreach", "while", "bit", "num", "great", "char", "string", "return"};
        int counter = 0;
        for(const auto& line : Tokens){
            std::string Temp;

            for (auto c : line) {
                Temp.push_back(c);
            }

            for (const auto& keyword : Keywords) {
                if (keyword == Temp) {
                    Types[counter] = 20;
                    break;
                }
            }

            counter++;
        }

        return 0;
    }
}