/**
 * @file IPv6_Subnet.h
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains declaration of IPv6_Subnet class.
 */

#ifndef ADDRESS_IPV6_SUBNET_H
#define ADDRESS_IPV6_SUBNET_H


#include "../IPv6.h"
#include "Subnet.h"

/**
 * Implements subnet of IPv6 addresses in CIDR notation.
 *
 * Subnet stores an address in IPv6 form forms and a number of
 * leading bits in subnet mask.
 */
class IPv6_Subnet : public Subnet {
public:
    /**
     * Default constructor. Creates empty subnet.
     */
    IPv6_Subnet();

    /**
     * Constructor which takes string as parameter.
     *
     * Uses parser to construct IPv6 subnet in CIDR notation from string. String
     * should contain address in IPv6 CIDR notation:
     * b1.b2.b3.b4.b5.b6.b7.b8/bits, where 0000 <= bi <= ffff and bits <= 255.
     *
     * @param string Subnet in CIDR notation.
     */
    explicit IPv6_Subnet(const std::string & string);

    /**
     * Constructor that takes base address and mask bits as parameter.
     *
     * @param _address Base address of subnet in CIDR notation.
     * @param _bits Number of mask leading bits.
     */
    IPv6_Subnet(const IPv6 &_address, uint8_t _bits);
};


#endif //ADDRESS_IPV6_SUBNET_H
