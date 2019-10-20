//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_H
#define ADDRESS_MAC_H


#include "IPv6.h"
#include "Parser/MAC_Parser.h"

class MAC : public Address{
private:
    static MAC_Parser parser;
    uint16_t data[3];
public:
    MAC();
    MAC(const MAC&);
    explicit MAC(std::string);
    std::vector<bool> as_bits();
    std::string as_string();
    IPv6 as_IPv6();
};


#endif //ADDRESS_MAC_H
