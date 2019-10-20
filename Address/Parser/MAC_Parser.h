//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_PARSER_H
#define ADDRESS_MAC_PARSER_H


#include "Parser.h"

class MAC_Parser : Parser {
public:
    uint16_t block_from_string(std::string&);
    std::vector<bool> as_bits(const uint16_t[3]);
    std::string as_string(const uint16_t[3]);
};


#endif //ADDRESS_MAC_PARSER_H
