//
// Created by tmyro on 06.10.2019.
//

#ifndef LAB1_ADDRESSHOLDER_H
#define LAB1_ADDRESSHOLDER_H

#include <cstdint>
#include <string>

class AddressHolder {
public:
    enum Type {IPv4, IPv6, MAC, IPv6_CIDR, IPv4_CIDR};
    static AddressHolder* create(uint8_t*, Type);
    static AddressHolder* create(const std::string&);
    static AddressHolder* create(char*, int);
    AddressHolder(uint8_t *, const int&, Type);
    virtual ~AddressHolder();
    virtual std::string asString() =0;
    int getSize();
    Type getType();
    uint8_t * getData();
protected:
    int size;
    uint8_t* data;
    Type type;
};


#endif //LAB1_ADDRESSHOLDER_H
