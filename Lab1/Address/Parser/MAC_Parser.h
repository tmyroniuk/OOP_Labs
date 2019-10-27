//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_PARSER_H
#define ADDRESS_MAC_PARSER_H


#include "Parser.h"

//contain methods to parse MAC address
class MAC_Parser : Parser {
public:
    //convert block ff:ff to uint16
    uint16_t blockFromString(std::string &string);

    //convert 48 bit data to bit vector
    std::vector<bool> asBits(const uint16_t data[3]);

    //convert 48 bit data to string in MAC form
    std::string asString(const uint16_t data[3]);
};


#endif //ADDRESS_MAC_PARSER_H
