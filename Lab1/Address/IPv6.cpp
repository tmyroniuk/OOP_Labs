//
// Created by tmyro on 13.10.2019.
//

#include "IPv6.h"

IPv6::IPv6(uint8_t *data) : AddressHolder(data, 16, Type::IPv6) {}
