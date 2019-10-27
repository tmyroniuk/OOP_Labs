//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_SUBNET_H
#define ADDRESS_IPV6_SUBNET_H


#include "../IPv6.h"
#include "Subnet.h"

//implements subnet with IPv6 address object
class IPv6_Subnet : public Subnet {
public:
    IPv6_Subnet();

    explicit IPv6_Subnet(const std::string &);

    IPv6_Subnet(const IPv6 &, uint8_t);
};


#endif //ADDRESS_IPV6_SUBNET_H
