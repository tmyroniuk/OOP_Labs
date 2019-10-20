//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_PARSER_H
#define ADDRESS_MAC_PARSER_H


#include "Parser.h"

class MAC_Parser : Parser {
public:
    uint16_t blockFromString(std::string &string);

    std::vector<bool> asBits(const uint16_t data[3]);

    std::string asString(const uint16_t data[3]);
};


#endif //ADDRESS_MAC_PARSER_H
