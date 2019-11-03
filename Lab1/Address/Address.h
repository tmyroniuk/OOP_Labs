//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_ADDRESS_H
#define ADDRESS_ADDRESS_H

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

class IPv6;

/**
 * Base class to store address.
 *
 * Implements interface for class storing address in one of supported
 * formats.
 */
class Address {
public:
    /**
     * Enum of types
     */
    enum Type {
        IPv6_t, IPv4_t, MAC_t
    };

    /**
     * Constructor
     * @param _size Address size in bits.
     * @param _type Type of address stored.
     */
    explicit Address(uint8_t _size, Type _type);

    /**
     * Represents stored address as bit vector.
     *
     * Creates bool vector which represents stored address as bits. Bool
     * vector is chosen because it is memory-optimized and easy to store and
     * process.
     *
     * @return Bool vector
     */
    virtual std::vector<bool> asBits() const = 0;

    /**
     * Represents stored data as string.
     *
     * Uses parser to convert stored data to string
     * in appropriate form.
     *
     * @return Address as string.
     */
    virtual std::string asString() const = 0;

    /**
     * Convert address into IPv6 object.
     *
     * @return IPv6 object storing this address.
     */
    virtual IPv6 asIPv6() const = 0;

    /**
     * Returns type of address stored.
     *
     * @return type of address stored.
     */
    Type getType() const;

    /**
     * Returns address size in bits.
     *
     * @return address size in bits.
     */
    uint8_t getSize() const;

protected:
    /**
     * Size in bits.
     */
    uint8_t size;

    /**
     * Type of the address stored.
     */
    Type type;
};


#endif //ADDRESS_ADDRESS_H
