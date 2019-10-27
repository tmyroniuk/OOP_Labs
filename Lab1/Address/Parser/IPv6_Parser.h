//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_PARSER_H
#define ADDRESS_IPV6_PARSER_H


#include "Parser.h"

//contain methods to parse IPv6 address
class IPv6_Parser : public Parser {
public:
    //convert string block ffff:ffff to uint32
    uint32_t blockFromString(std::string &string);

    //convert 128 bit data to bit vector
    std::vector<bool> asBits(const uint32_t data[4]);

    //convert 128 bit data to string in IPv6 form
    std::string asString(const uint32_t data[4]);
};


#endif //ADDRESS_IPV6_PARSER_H
