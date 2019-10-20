//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_IPV4_H
#define ADDRESS_IPV4_H

#include "IPv6.h"
#include "Parser/IPv4_Parser.h"

class IPv4 : public Address{
private:
    uint32_t data;
    static IPv4_Parser parser;
public:
    IPv4();
    IPv4(const IPv4&);
    explicit IPv4(const std::string&);
    std::uint32_t as_uint32();
    std::vector<bool> as_bits();
    std::string as_string();
    IPv6 as_IPv6() override;
};


#endif //ADDRESS_IPV4_H
