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
    std::vector<bool> int_to_bits(uint32_t, uint32_t);
    uint32_t hex_to_int(const std::string&);
    std::string int_to_hex(uint32_t);
};


#endif //ADDRESS_PARSER_H
