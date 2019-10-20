//
// Created by tmyro on 06.10.2019.
//

#ifndef LAB1_IPV4_H
#define LAB1_IPV4_H


#include "AddressHolder.h"

class IPv4 : public AddressHolder {
public:
    IPv4(uint8_t*);
    virtual std::string asString();

};


#endif //LAB1_IPV4_H
