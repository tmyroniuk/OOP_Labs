//
// Created by tmyro on 13.10.2019.
//

#ifndef LAB1_IPV6_H
#define LAB1_IPV6_H


#include "AddressHolder.h"

class IPv6 : public AddressHolder {
public:
    IPv6(uint8_t*);
    virtual std::string asString();
};


#endif //LAB1_IPV6_H
