//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_PARSER_H
#define ADDRESS_IPV6_PARSER_H


#include "Parser.h"

class IPv6_Parser : public Parser {
public:
    uint32_t blockFromString(std::string &string);

    std::vector<bool> asBits(const uint32_t data[4]);

    std::string asString(const uint32_t data[4]);
};


#endif //ADDRESS_IPV6_PARSER_H
