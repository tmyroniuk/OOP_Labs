//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV6_PARSER_H
#define ADDRESS_IPV6_PARSER_H


#include "Parser.h"

/**
 * Contain methods to parse IPv6 address.
 */
class IPv6_Parser : public Parser {
public:
    /**
     * Parses two blocks of MAC address to uint16.
     *
     * Converts block ffff:ffff to uint32 using hex parser. Removes the blocks
     * from input string.
     *
     * @param string IPv6 address in text form.
     * @return First two blocks as uint32.
     */
    uint32_t blockFromString(std::string &string);

    /**
     * Converts 128 bits to bool vector.
     *
     * @param data 128 bits data as 4 uint32 fields.
     * @return Bool vector representing 128 bit data in bit form.
     */
    std::vector<bool> asBits(const uint32_t data[4]);

    /**
     * Parses 128 bit data into IPv6 address text form.
     *
     * @param data 128 bits data as 4 uint32 fields.
     * @return IPv6 address in text form.
     */
    std::string asString(const uint32_t data[4]);
};


#endif //ADDRESS_IPV6_PARSER_H
