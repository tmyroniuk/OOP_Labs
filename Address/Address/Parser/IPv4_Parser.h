//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_PARSER_H
#define ADDRESS_IPV4_PARSER_H


#include "Parser.h"

class IPv4_Parser : Parser {
public:
    uint32_t dataFromString(const std::string &string);

    std::vector<bool> asBits(uint32_t data);

    std::string asString(uint32_t data);
};


#endif //ADDRESS_IPV4_PARSER_H
