//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_H
#define ADDRESS_MAC_H


#include "IPv6.h"
#include "Parser/MAC_Parser.h"

class MAC : public Address{
private:
    static MAC_Parser parser;
    uint16_t data[3];
public:
    MAC();
    MAC(const MAC&);
    explicit MAC(std::string);
    std::vector<bool> as_bits() const override;
    std::string as_string() const override;
    IPv6 as_IPv6() const override;
    bool operator==(const MAC&);
    bool operator!=(const MAC&);
    bool operator>(const MAC&);
    bool operator<(const MAC&);
    bool operator>=(const MAC&);
    bool operator<=(const MAC&);
    MAC &operator=(const MAC&);
};


#endif //ADDRESS_MAC_H
