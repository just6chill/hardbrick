//
// Created by justi on 25.04.2021.
//

#ifndef FIRST_LEXICALANALYSIS_H
#define FIRST_LEXICALANALYSIS_H

#include <string>

namespace Lexer {
    class Lex{
    public:
        Lex(std::string_view filename);

    private:
        int ReadFile(std::string_view filename);
        char Tokenize(std::string &line);
    };

}
#endif //FIRST_LEXICALANALYSIS_H
