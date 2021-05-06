#include "Parser/LexicalAnalysis/LexicalAnalysis.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Parser::LexicalAnalysis Lexer(argv[1]);
    Lexer.Run();
    auto [Tokens, Types] = Lexer.GetState();


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
        }
        std::cout << ": ";
        counter++;
        for (auto &col : row) {
            std::cout << col;
        }
    }

    return 0;
}
