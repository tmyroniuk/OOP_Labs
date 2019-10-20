//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_H
#define ADDRESS_IPV6_H


#include "Address.h"
#include "Parser/IPv6_Parser.h"

class IPv6 : public Address {
private:
    static IPv6_Parser parser;
    uint32_t data[4];
public:
    IPv6();
    IPv6(const IPv6&);
    explicit IPv6(uint32_t[4]);
    explicit IPv6(std::string);
    std::vector<bool> as_bits() const override;
    std::string as_string() const override;
    IPv6 as_IPv6() const override;
    bool operator==(const IPv6&);
    bool operator!=(const IPv6&);
    bool operator>(const IPv6&);
    bool operator<(const IPv6&);
    bool operator>=(const IPv6&);
    bool operator<=(const IPv6&);
    IPv6 &operator=(const IPv6&);
};


#endif //ADDRESS_IPV6_H
