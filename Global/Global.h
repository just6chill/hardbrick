//
// Created by justi on 26.04.2021.
//

#ifndef FIRST_GLOBAL_H
#define FIRST_GLOBAL_H

#include <vector>

namespace Global {
    //the vector to store the types of the chars. (parallel to Code)
    extern std::vector<int> Table;

    //the vector to store the chars of the code (parallel to Table)
    extern std::vector<char> Code;

    extern std::vector<std::vector<char>> Tokens;
}

#endif //FIRST_GLOBAL_H
