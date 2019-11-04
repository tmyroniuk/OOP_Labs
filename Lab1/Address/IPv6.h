/**
 * @file IPv6.h
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains declaration of IPv6 class.
 */

#ifndef ADDRESS_IPV6_H
#define ADDRESS_IPV6_H


#include "Address.h"

#include "Parser/IPv6_Parser.h"

/**
 * Implementation of Address class to store IPv6 address.
 *
 * Stores IPv4 address an array of four uint32 variables. Includes static parsing
 * object. Does parsing and comparing operations. Any address can be converted into
 * IPv6 object.
 */
class IPv6 : public Address {
private:
    ///Parsing object.
    static IPv6_Parser parser;

    ///Address as 4 uint32 fields.
    uint32_t data[4];
public:

    /**
     * Default constructor. Sets data type, sets size to 128 bits.
     */
    IPv6();

    /**
     * Copy constructor.
     *
     * @param that Object copied.
     */
    IPv6(const IPv6 &that);

    /**
     * Constructor with raw data as an argument.
     *
     * @param _data IPv6 address as 4 uint32.
     */
    explicit IPv6(uint32_t _data[4]);

    /**
     * Constructor with string as argument.
     *
     * Uses parser to construct IPv6 object from its text form. String should contain
     * address in IPv6 text form (b1.b2.b3.b4.b5.b6.b7.b8 where 0000 <= bi <= ffff).
     * Only complete form is supported.
     *
     * @param string IPv6 address in text form.
     */
    explicit IPv6(std::string string);

    /**
     * Represents stored address as bit vector.
     *
     * @return Bool vector representing stored address as bit string.
     */
    std::vector<bool> asBits() const override;

    /**
     * Returns address as string in an IPv6 form using parser.
     *
     * @return IPv6 address as string.
     */
    std::string asString() const override;

    /**
     * Returns this object copy.
     *
     * @return This object copy.
     */
    IPv6 asIPv6() const override;

    bool operator==(const IPv6 &that) const;

    bool operator!=(const IPv6 &that) const;

    bool operator>(const IPv6 &that) const;

    bool operator<(const IPv6 &that) const;

    bool operator>=(const IPv6 &that) const;

    bool operator<=(const IPv6 &that) const;

    IPv6 &operator=(const IPv6 &that);
};


#endif //ADDRESS_IPV6_H
