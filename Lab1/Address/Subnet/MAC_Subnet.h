/**
 * @file MAC_Subnet.h
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains declaration of MAC_Subnet class.
 */

#ifndef ADDRESS_MAC_SUBNET_H
#define ADDRESS_MAC_SUBNET_H

#include "../MAC.h"
#include "Subnet.h"

/**
 * Implements subnet of MAC addresses in CIDR notation.
 *
 * Subnet stores an address in MAC form forms and a number of
 * leading bits in subnet mask.
 */
class MAC_Subnet : public Subnet {
public:
    MAC_Subnet();

    /**
     * Constructor which takes string as parameter.
     *
     * Uses parser to construct MAC subnet in CIDR notation from string. String
     * should contain address in MAC CIDR notation:
     * b1.b2.b3.b4.b5.b6/bits, where 00 <= bi <= ff and bits <= 255.
     *
     * @param string Subnet in CIDR notation.
     */
    explicit MAC_Subnet(const std::string &);

    /**
     * Constructor that takes base address and mask bits as parameter.
     *
     * @param _address Base address of subnet in CIDR notation.
     * @param _bits Number of mask leading bits.
     */
    MAC_Subnet(const MAC &_address, uint8_t _bits);
};


#endif //ADDRESS_MAC_SUBNET_H
