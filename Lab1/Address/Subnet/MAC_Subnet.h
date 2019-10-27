//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_SUBNET_H
#define ADDRESS_MAC_SUBNET_H

#include "../MAC.h"
#include "Subnet.h"

//implements subnet with MAC address object
class MAC_Subnet : public Subnet {
public:
    MAC_Subnet();

    explicit MAC_Subnet(const std::string &);

    MAC_Subnet(const MAC &, uint8_t);
};


#endif //ADDRESS_MAC_SUBNET_H
