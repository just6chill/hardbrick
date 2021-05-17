//
// Created by justi on 03.05.2021.
//
#include <string>
#include <tuple>
#include <vector>
#include "LexicalAnalysis.h"

namespace Analysis {

    LexicalAnalysis::LexicalAnalysis(std::string_view filename) {
        file.open(filename.data());
    }

    int LexicalAnalysis::Run() {

        //the vector to store the types of the chars. (parallel to Code)
        std::vector<int> Table;
        //the vector to store the chars of the code (parallel to Table)
        std::vector<char> Code;

        ReadFile(Code);
        PreTokenize(Code, Table);
        Tokenize(Code, Table);
        SpaceHandle();
        Assign();

        return 0;
    }

    std::tuple<std::vector<std::vector<char>>, std::vector<int>> LexicalAnalysis::GetState() {
        return {Tokens, Types};
    }

    LexicalAnalysis::~LexicalAnalysis() {
        file.close();
    }
}


