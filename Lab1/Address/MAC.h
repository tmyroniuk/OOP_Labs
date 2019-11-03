//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_H
#define ADDRESS_MAC_H


#include "IPv6.h"

#include "Parser/MAC_Parser.h"

/**
 * Implementation of Address class to store MAC address.
 *
 * Stores MAC address as array of 3 uint16. Includes static parsing object. Does
 * parsing and comparing operations.
 */
class MAC : public Address {
private:
    ///Parser object.
    static MAC_Parser parser;

    ///Address stored as 3 uint16 fields.
    uint16_t data[3];
public:
    /**
     * Default constructor.
     *
     * Sets data type to MAC_t, size to 48 bits.
     */
    MAC();

    /**
     * Copy constructor.
     *
     * @param that The object copied.
     */
    MAC(const MAC &that);

    /**
     * Constructs MAC address from string.
     *
     * Uses parser to construct MAC object from string. String should contain
     * address in MAC text form (b1.b2.b3.b4.b5.b6 where 00 <= bi <= ff).
     * Only complete text form is supported.
     *
     * @param string MAC address in text form.
     */
    explicit MAC(std::string string);

    /**
     * Represents stored address as bit vector.
     *
     * @return Bool vector representing stored address as bit string.
     */
    std::vector<bool> asBits() const override;

    /**
     * Returns address as string in an MAC text form using parser.
     *
     * @return MAC address as string.
     */
    std::string asString() const override;

    /**
     * Creates IPv6 address object storing this address.
     *
     * @return IPv6 object storing this address.
     */
    IPv6 asIPv6() const override;

    bool operator==(const MAC &that) const;

    bool operator!=(const MAC &that) const;

    bool operator>(const MAC &that) const;

    bool operator<(const MAC &that) const;

    bool operator>=(const MAC &that) const;

    bool operator<=(const MAC &that) const;

    MAC &operator=(const MAC &that);
};


#endif //ADDRESS_MAC_H
