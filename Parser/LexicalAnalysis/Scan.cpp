//
// Created by justi on 25.04.2021.
//

#include "LexicalAnalysis.h"
#include <string>

enum {zero, op, symbol, bracket, letter, digit};

namespace Parser {

    int LexicalAnalysis::ReadFile(std::vector<char> &Code) {

        std::string line;

        //read the file line by line
        while (std::getline(file, line)) {
            TokenizeLine(line, Code);
        }
        return 0;
    }

    int LexicalAnalysis::TokenizeLine(std::string &line, std::vector<char> &Code) {

        //remove newline char from the line
        //and end string there
        for (int j = 0; line[j] != '\0'; ++j) {
            if (line[j] == '\n') {
                line[j] = '\0';
            }
        }

        //loop through the line and assign values to Code vector
        for (char c : line) {
            Code.push_back(c);
        }

        return 0;
    }

    int LexicalAnalysis::PreTokenize(std::vector<char> &Code, std::vector<int> &Table) {

        std::string operators = "+-*/=";
        std::string symbols = "#'\"$%&!/\\:.,;";
        std::string brackets = "(){}[]";

        //check which type the char of the actual index is and
        //assign its type to the Table vector at a parallel index
        for (auto c = Code.cbegin(); c != Code.cend(); ++c) {
            for (auto o : operators) {
                if (*c == o) {
                    Table.push_back(op);
                }
            }
            for (auto s : symbols) {
                if (*c == s) {
                    Table.push_back(symbol);
                }
            }
            for (auto b : brackets) {
                if (*c == b) {
                    Table.push_back(bracket);
                }
            }

            if (*c == ' '){
                Table.push_back(symbol);
            }
            if (std::isalpha(*c)) {
                Table.push_back(letter);
            } else if (std::isdigit(*c)) {
                Table.push_back(digit);
            }
        }
        return 0;
    }

}