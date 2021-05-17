//
// Created by justi on 17.05.2021.
//
#include <utility>
#include <vector>
#include <tuple>
#include <iostream>
#include "SyntaxAnalysis.h"
namespace Analysis {

    SyntaxAnalysis::SyntaxAnalysis(std::vector<std::vector<char>> Tokens_State, std::vector<int> Types_State) {
        Tokens = std::move(Tokens_State);
        Types = std::move(Types_State);
    }

    int SyntaxAnalysis::Run() {

        //print the thing out yeah
        int counter = 0;
        for (auto &row : Tokens) {
            std::cout << std::endl;

            switch (Types[counter]) {
                case 0: std::cout << "operator  "; break;
                case 1: std::cout << "symbol    "; break;
                case 2: std::cout << "bracket   "; break;
                case 3: std::cout << "space     "; break;
                case 4: std::cout << "number    "; break;
                case 5: std::cout << "identifier"; break;
                case 10: std::cout << "string    "; break;
                case 20: std::cout << "keyword   "; break;
            }
            std::cout << ": ";
            counter++;
            for (auto &col : row) {
                std::cout << col;
            }
        }

        return 0;
    }

    std::tuple<std::vector<std::vector<char>>, std::vector<int>> SyntaxAnalysis::GetState() {

        return {Tokens, Types};
    }
}
