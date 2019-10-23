//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_H
#define ADDRESS_MAC_H


#include "IPv6.h"
#include "Parser/MAC_Parser.h"

class MAC : public Address {
private:
    static MAC_Parser parser;
    uint16_t data[3];
public:
    MAC();

    MAC(const MAC &);

    explicit MAC(std::string);

    //return data as bits array
    std::vector<bool> asBits() const override;

    //return stored data as string in appropriate form using parser
    std::string asString() const override;

    //return data as IPv6 object
    IPv6 asIPv6() const override;

    bool operator==(const MAC &) const;

    bool operator!=(const MAC &) const;

    bool operator>(const MAC &) const;

    bool operator<(const MAC &) const;

    bool operator>=(const MAC &) const;

    bool operator<=(const MAC &) const;

    MAC &operator=(const MAC &);
};


#endif //ADDRESS_MAC_H
