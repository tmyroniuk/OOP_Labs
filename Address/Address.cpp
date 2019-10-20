//
// Created by tmyro on 16.10.2019.
//

#include "Address.h"

Address::Address(uint8_t _size, Type _type) : size(_size), type(_type) {}

uint8_t Address::getSize() const {
    return size;
}

Address::Type Address::getType() const {
    return type;
}
