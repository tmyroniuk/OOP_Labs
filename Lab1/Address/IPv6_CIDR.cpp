//
// Created by tmyro on 13.10.2019.
//

#include "IPv6_CIDR.h"

IPv6_CIDR::IPv6_CIDR(uint8_t *data, uint8_t bits) : IPv6(data), mask(bits) {}
