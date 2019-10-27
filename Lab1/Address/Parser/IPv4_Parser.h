//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_PARSER_H
#define ADDRESS_IPV4_PARSER_H


#include "Parser.h"

//contain methods to parse IPv4 address
class IPv4_Parser : Parser {
public:
    //convert string block 999.999.999.999 to uint32
    uint32_t dataFromString(const std::string &string);

    //convert 32 bit data to bit array
    std::vector<bool> asBits(uint32_t data);

    //convert 32 bit data to string in IPv4 form
    std::string asString(uint32_t data);
};


#endif //ADDRESS_IPV4_PARSER_H
