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

//abstract class to store address
class Address {
public:
    //type of address
    enum Type {
        IPv6_t, IPv4_t, MAC_t
    };

    explicit Address(uint8_t, Type);

    //return stored data as bit vector
    virtual std::vector<bool> asBits() const = 0;

    //return stored data as string in appropriate form using parser
    virtual std::string asString() const = 0;

    //return address as IPv6 object
    virtual IPv6 asIPv6() const = 0;

    //return address type
    Type getType() const;

    //return size in bits
    uint8_t getSize() const;

protected:
    //size in bits
    uint8_t size;
    //type of stored data
    Type type;
};


#endif //ADDRESS_ADDRESS_H
