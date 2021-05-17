//
// Created by justi on 25.04.2021.
//

#ifndef LEXICAL_ANALYSIS
#define LEXICAL_ANALYSIS

#include <string>
#include <fstream>
#include <vector>
#include <tuple>

namespace Analysis {

    /**********************************
     * class for the Lexical Analysis *
     * of the entire code             *
     **********************************/
    class LexicalAnalysis{
    public:
        //main function of the class
        int Run();
        //constructor
        LexicalAnalysis(std::string_view filename);
        //destructor
        ~LexicalAnalysis();
        //get method to return the state
        std::tuple<std::vector<std::vector<char>>, std::vector<int>> GetState();

    private:
        /*******************
         * Class Functions *
         *******************/

        //read the file line by line
        int ReadFile(std::vector<char> &Code);
        //assign each line to the code vector
        int TokenizeLine(std::string &line, std::vector<char> &Code);
        //tokenize the code vector by assign char types
        int PreTokenize(std::vector<char> &Code, std::vector<int> &Table);
        //tokenize types
        int Tokenize(std::vector<char> &Code, std::vector<int> &Table);
        //Handle Space and empty vectors
        int SpaceHandle();
        //assign types
        int Assign();

        /*******************
         * Class Variables *
         *******************/

        //the file
        std::ifstream file;

        //final tokens
        std::vector<std::vector<char>> Tokens;
        std::vector<int> Types;

    };

}
#endif //LEXICAL_ANALYSIS
