//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_PARSER_H
#define ADDRESS_PARSER_H


#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

//contain methods to parse address in string form
class Parser {
protected:
    //convert <data> in bit array with <bits> size
    std::vector<bool> intToBits(uint32_t data, uint8_t bits);

    //convert hex number in string to uint32
    uint32_t hexToInt(const std::string &data);

    //convert uint32 to hex in string
    std::string intToHex(uint32_t data);
};


#endif //ADDRESS_PARSER_H
