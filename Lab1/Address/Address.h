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
    enum Type {
        IPv6_t, IPv4_t, MAC_t
    };

    explicit Address(uint8_t, Type);

    virtual std::vector<bool> asBits() const = 0;

    virtual std::string asString() const = 0;

    virtual IPv6 asIPv6() const = 0;

    Type getType() const;

    uint8_t getSize() const;

protected:
    uint8_t size;
    Type type;
};


#endif //ADDRESS_ADDRESS_H
