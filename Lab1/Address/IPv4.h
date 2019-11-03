//
// Created by tmyro on 16.10.2019.
//

#ifndef ADDRESS_IPV4_H
#define ADDRESS_IPV4_H

#include "IPv6.h"

#include "Parser/IPv4_Parser.h"

/**
 * Implementation of Address class to store IPv4 address.
 *
 * Stores IPv4 address as uint32. Includes static parsing object. Does
 * parsing and comparing operations.
 */
class IPv4 : public Address {
private:
    ///IPv4 stored as uint32.
    uint32_t data;

    ///Parser object.
    static IPv4_Parser parser;
public:
    /**
     * Default constructor. Sets data type, sets size to 32 bits.
     */
    IPv4();

    /**
     * Copy constructor.
     *
     * @param that An object copied.
     */
    IPv4(const IPv4 &that);

    /**
     * Constructs IPv4 from string.
     *
     * Uses parser to construct IPv4 object from string. String should contain
     * address in IPv4 form (a1.a2.a3.a4 where 0 <= ai <= 255).
     *
     * @param string IPv4 address in text form.
     */
    explicit IPv4(const std::string &string);

    /**
     * Returns stored data as uint32.
     * @return IPv4 address as uint32.
     */
    std::uint32_t asUint32();

    /**
     * Represents stored address as bit vector.
     *
     * @return Bool vector representing stored address as bit string.
     */
    std::vector<bool> asBits() const override;

    /**
     * Returns address as string in an IPv4 form using parser.
     *
     * @return IPv4 address as string.
     */
    std::string asString() const override;

    /**
     * Converts address into IPv6 object.
     *
     * @return IPv4 object storing this address.
     */
    IPv6 asIPv6() const override;

    bool operator==(const IPv4 &that) const;

    bool operator!=(const IPv4 &that) const;

    bool operator>(const IPv4 &that) const;

    bool operator<(const IPv4 &that) const;

    bool operator>=(const IPv4 &that) const;

    bool operator<=(const IPv4 &that) const;

    IPv4 &operator=(const IPv4 &that);
};


#endif //ADDRESS_IPV4_H
