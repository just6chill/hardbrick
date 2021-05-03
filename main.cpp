#include "Parser/LexicalAnalysis/LexicalAnalysis.h"
#include "Global/Global.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Parser::LexicalAnalysis code(argv[1]);

    for (auto &row : Global::Tokens) {
        std::cout << std::endl;
        for (auto &col : row) {
            std::cout << col;
        }
    }
    return 0;
}
