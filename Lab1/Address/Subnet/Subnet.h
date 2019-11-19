/**
 * @file Subnet.h
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains declaration of Subnet class.
 */

#ifndef ADDRESS_SUBNET_H
#define ADDRESS_SUBNET_H


#include "../Address.h"

/**
 * Base class for subnet in CIDR notation.
 *
 * Subnet stores an address in one of supported forms and a number of
 * leading bits in subnet mask.
 */
class Subnet {
protected:
    /**
     * Finds position of the first '/' symbol in given string.
     *
     * Used to parse CIDR notation subnet from string.
     *
     * @param string string containing '/' symbol.
     * @return position of '/' symbol in string.
     */
    static int sub_parser(const std::string &string);

    ///Base address.
    Address *address;

    ///Number of leading bits.
    uint8_t bits;
public:
    /**
     * Default constructor. Creates empty Subnet object.
     */
    Subnet();

    /**
     * Constructor with base address and mask bits as parameters.
     *
     * @param _address Base address in CIDR notation.
     * @param _bits Number of leading bits in subnet mask.
     */
    Subnet(Address *_address, uint8_t _bits);

    /**
     * Checks if the subnet contains given address.
     *
     * @param _address Address checked.
     * @return If subnet contains the address.
     */
    bool contains(const Address &_address);

    /**
     * Returns type of addresses the subnet contains.
     * @return Type of base address.
     */
    Address::Type type();

    /**
     * Converts subnet into string in CIDR notation.
     *
     * @return Subnet as string.
     */
    std::string asString();

    ~Subnet();
};


#endif //ADDRESS_SUBNET_H
