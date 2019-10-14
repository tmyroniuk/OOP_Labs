//
// Created by tmyro on 13.10.2019.
//

#ifndef LAB1_IPV4_CIDR_H
#define LAB1_IPV4_CIDR_H


#include "IPv4.h"

class IPv4_CIDR : public IPv4 {
    uint8_t mask;
public:
    IPv4_CIDR(uint8_t*, uint8_t);
    std::string asString();
};


#endif //LAB1_IPV4_CIDR_H
