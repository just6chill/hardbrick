#include "Analysis/LexicalAnalysis/LexicalAnalysis.h"
#include "Analysis/SyntaxAnalysis/SyntaxAnalysis.h"

int main(int argc, char *argv[]) {

    Analysis::LexicalAnalysis Lexer(argv[1]);
    Lexer.Run();
    auto [Tokens, Types] = Lexer.GetState();

    Analysis::SyntaxAnalysis Syntax(Tokens, Types);
    Syntax.Run();
    std::tie(Tokens, Types) = Syntax.GetState();

    return 0;
}
