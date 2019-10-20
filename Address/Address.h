//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_ADDRESS_H
#define ADDRESS_ADDRESS_H
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

class IPv6;

class Address {
protected:
    uint8_t size;
public:
    explicit Address(uint8_t);
    virtual std::vector<bool> as_bits() =0;
    virtual std::string as_string() =0;
    virtual IPv6 as_IPv6() =0;
};


#endif //ADDRESS_ADDRESS_H
