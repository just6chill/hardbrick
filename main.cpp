#include "Parser/LexicalAnalysis/LexicalAnalysis.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Parser::LexicalAnalysis Lexer(argv[1]);
    Lexer.Run();
    auto [Tokens, Types] = Lexer.GetState();

    for (auto &row : Tokens) {
        std::cout << std::endl;

        for (auto &col : row) {
            std::cout << col;
        }
    }

    return 0;
}
