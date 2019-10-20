//
// Created by tmyro on 13.10.2019.
//

#include "IPv4_CIDR.h"


IPv4_CIDR::IPv4_CIDR(uint8_t *data, uint8_t bits) : AddressHolder(data, 16, Type::IPv4_CIDR), mask(bits) {}
