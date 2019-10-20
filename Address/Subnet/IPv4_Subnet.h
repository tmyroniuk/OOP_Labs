//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_SUBNET_H
#define ADDRESS_IPV4_SUBNET_H


#include "../IPv4.h"
#include "Subnet.h"

class IPv4_Subnet : public Subnet {
public:
    IPv4_Subnet();
    explicit IPv4_Subnet(const std::string&);
    IPv4_Subnet(const IPv4&, uint8_t);
};


#endif //ADDRESS_IPV4_SUBNET_H
