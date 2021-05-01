//
// Created by justi on 25.04.2021.
//

#ifndef FIRST_LEXICALANALYSIS_H
#define FIRST_LEXICALANALYSIS_H

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
        int TokenizeCode();
    };

}
#endif //FIRST_LEXICALANALYSIS_H
