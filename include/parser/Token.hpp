//
// Created by Canh Minh Do on 2024/11/10.
//

#ifndef QRAT_TOKEN_HPP
#define QRAT_TOKEN_HPP

#include "utility/StringTable.hpp"

class Token {
public:
    void tokenize(const char *tokenString, int lineNumber);
private:
    static StringTable stringTable;
    int codeNr;
    int lineNr;
};

#endif//QRAT_TOKEN_HPP
