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
public:
    enum Type {IPv6_t, IPv4_t, MAC_t};
    explicit Address(uint8_t, Type);
    virtual std::vector<bool> as_bits() const =0;
    virtual std::string as_string() const =0;
    virtual IPv6 as_IPv6() const =0;
    Type get_Type() const;
    uint8_t get_size() const;
protected:
    uint8_t size;
    Type type;
};


#endif //ADDRESS_ADDRESS_H
