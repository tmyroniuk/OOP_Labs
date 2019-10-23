//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_IPV4_H
#define ADDRESS_IPV4_H

#include "IPv6.h"
#include "Parser/IPv4_Parser.h"

//implements Address as IPv4 address
class IPv4 : public Address {
private:
    uint32_t data;

    static IPv4_Parser parser;
public:
    IPv4();

    //copy ctor
    IPv4(const IPv4 &that);

    //construct
    explicit IPv4(const std::string &string);

    //return data as uint32
    std::uint32_t asUint32();

    //return data as bits array
    std::vector<bool> asBits() const override;

    //return stored data as string in appropriate form using parser
    std::string asString() const override;

    //return data as IPv6 object
    IPv6 asIPv6() const override;

    bool operator==(const IPv4 &that) const;

    bool operator!=(const IPv4 &that) const;

    bool operator>(const IPv4 &that) const;

    bool operator<(const IPv4 &that) const;

    bool operator>=(const IPv4 &that) const;

    bool operator<=(const IPv4 &) const;

    IPv4 &operator=(const IPv4 &);
};


#endif //ADDRESS_IPV4_H
