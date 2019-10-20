//
// Created by tmyro on 13.10.2019.
//

#ifndef LAB1_IPV6_CIDR_H
#define LAB1_IPV6_CIDR_H


#include "IPv6.h"

class IPv6_CIDR : IPv6 {
    uint8_t mask;
public:
    IPv6_CIDR(uint8_t*, uint8_t);
    std::string asString();
};


#endif //LAB1_IPV6_CIDR_H
