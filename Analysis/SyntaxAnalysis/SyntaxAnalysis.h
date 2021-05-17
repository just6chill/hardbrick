//
// Created by justi on 17.05.2021.
//

#ifndef HARDBRICK_SYNTAXANALYSIS_H
#define HARDBRICK_SYNTAXANALYSIS_H

namespace Analysis {

    class SyntaxAnalysis{

    public:
        SyntaxAnalysis(std::vector<std::vector<char>> Tokens_State, std::vector<int> Types_State);
        int Run();
        std::tuple<std::vector<std::vector<char>>, std::vector<int>> GetState();

    private:
        std::vector<std::vector<char>> Tokens;
        std::vector<int> Types;
    };
}


#endif //HARDBRICK_SYNTAXANALYSIS_H
