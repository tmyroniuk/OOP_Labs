//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_PARSER_H
#define ADDRESS_IPV4_PARSER_H


#include "Parser.h"

class IPv4_Parser : Parser {
public:
    uint32_t data_from_string(const std::string&);
    std::vector<bool> as_bits(uint32_t);
    std::string as_string(uint32_t);
};


#endif //ADDRESS_IPV4_PARSER_H
