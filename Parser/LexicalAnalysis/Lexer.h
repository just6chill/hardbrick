//
// Created by justi on 25.04.2021.
//

#ifndef FIRST_PRELEXER_H
#define FIRST_LEXER_H

#include <string>

namespace Lexer {

    /**********************************
     * class for the Lexical Analysis *
     * of the entire code             *
     **********************************/
    class Lex{
    public:
        /************************************
         * constructor to call the Function *
         * in charge to Tokenize and type   *
         * the code                         *
         * @param filename                  *
         ************************************/
        Lex(std::string_view filename);

    private:
        //read the file line by line
        int ReadFile(std::string_view filename);
        //assign each line to the code vector
        int TokenizeLine(std::string &line);
        //tokenize the code vector by assign char types
        int PreTokenizeCode();
        int MainLexer();
    };

}
#endif //FIRST_PRELEXER_H
