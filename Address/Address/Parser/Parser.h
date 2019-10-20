//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_PARSER_H
#define ADDRESS_PARSER_H


#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

class Parser {
protected:
    std::vector<bool> intToBits(uint32_t data, uint32_t bits);

    uint32_t hexToInt(const std::string &data);

    std::string intToHex(uint32_t data);
};


#endif //ADDRESS_PARSER_H
