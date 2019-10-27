//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_SUBNET_H
#define ADDRESS_SUBNET_H


#include "../Address.h"

//abstract class. Contains subnet in CIDR notation
class Subnet {
protected:
    //return position of '/' in string
    static int sub_parser(const std::string &);

    //base address
    Address *address;
    //mask bits
    uint8_t bits;
public:
    Subnet();

    Subnet(Address *, uint8_t);

    //return true if subnet contain <_address>
    bool contains(const Address &_address);

    //return bits amount
    uint8_t get_bits();

    //return type of address
    Address::Type type();

    ~Subnet();
};


#endif //ADDRESS_SUBNET_H
