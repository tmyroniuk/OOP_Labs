//
// Created by tmyro on 13.10.2019.
//

#ifndef LAB1_MAC_H
#define LAB1_MAC_H


#include "AddressHolder.h"

class MAC : public AddressHolder {
public:
    MAC(uint8_t*);
    std::string asString();
};


#endif //LAB1_MAC_H
