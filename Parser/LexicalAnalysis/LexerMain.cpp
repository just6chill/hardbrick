//
// Created by justi on 03.05.2021.
//
#include <string>
#include "LexicalAnalysis.h"

namespace Parser {

    LexicalAnalysis::LexicalAnalysis(std::string_view filename) {
        Main(filename);
    }

    int LexicalAnalysis::Main(std::string_view filename) {
        ReadFile(filename);
        PreTokenize();
        Tokenize();
        Assign();

        return 0;
    }
}
