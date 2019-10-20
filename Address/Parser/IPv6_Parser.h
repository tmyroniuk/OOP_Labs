//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_PARSER_H
#define ADDRESS_IPV6_PARSER_H


#include "Parser.h"

class IPv6_Parser : public Parser {
public:
    uint32_t block_from_string(std::string&);
    std::vector<bool> as_bits(const uint32_t[4]);
    std::string as_string(const uint32_t[4]);
};


#endif //ADDRESS_IPV6_PARSER_H
