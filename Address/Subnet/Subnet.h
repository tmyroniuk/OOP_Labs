//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_SUBNET_H
#define ADDRESS_SUBNET_H


#include "../Address.h"

class Subnet {
protected:
    static int sub_parser(const std::string&);
    Address* address;
    uint8_t bits;
public:
    Subnet();
    Subnet(Address*, uint8_t);
    bool contains(const Address&);
    uint8_t get_bits();
    Address::Type type();
    ~Subnet();
};


#endif //ADDRESS_SUBNET_H
