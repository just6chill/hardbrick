//
// Created by justi on 25.04.2021.
//

#ifndef FIRST_PRELEXER_H
#define FIRST_LEXER_H

#include <string>

namespace Parser {

    /**********************************
     * class for the Lexical Analysis *
     * of the entire code             *
     **********************************/
    class LexicalAnalysis{
    public:
        /************************************
         * constructor to call the Function *
         * in charge to Tokenize and type   *
         * the code                         *
         * @param filename                  *
         ************************************/
        LexicalAnalysis(std::string_view filename);

    private:
        int Main(std::string_view filename);
        //read the file line by line
        int ReadFile(std::string_view filename);
        //assign each line to the code vector
        int TokenizeLine(std::string &line);
        //tokenize the code vector by assign char types
        int PreTokenize();
        //tokenize types
        int Tokenize();
        //assign types
        int Assign();
    };

}
#endif //FIRST_PRELEXER_H
