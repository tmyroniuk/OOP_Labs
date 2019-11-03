//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_SUBNET_H
#define ADDRESS_IPV4_SUBNET_H


#include "../IPv4.h"
#include "Subnet.h"

/**
 * Implements subnet of IPv4 addresses in CIDR notation.
 *
 * Subnet stores an address in IPv4 form forms and a number of
 * leading bits in subnet mask.
 */
class IPv4_Subnet : public Subnet {
public:
    /**
     * Default constructor. Creates empty subnet.
     */
    IPv4_Subnet();

    /**
     * Constructor which takes string as parameter.
     *
     * Uses parser to construct IPv4 subnet in CIDR notation from string. String
     * should contain address in IPv4 CIDR notation:
     * a1.a2.a3.a4/bits, where 0 <= ai <= 255 and bits <= 255.
     *
     * @param string Subnet in CIDR notation.
     */
    explicit IPv4_Subnet(const std::string &string);

    /**
     * Constructor that takes base address and mask bits as parameter.
     *
     * @param _address Base address of subnet in CIDR notation.
     * @param _bits Number of mask leading bits.
     */
    IPv4_Subnet(const IPv4 &_address, uint8_t _bits);
};


#endif //ADDRESS_IPV4_SUBNET_H
