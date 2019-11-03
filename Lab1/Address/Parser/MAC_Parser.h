//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_MAC_PARSER_H
#define ADDRESS_MAC_PARSER_H


#include "Parser.h"

/**
 * Contain methods to parse MAC address.
 */
class MAC_Parser : Parser {
public:
    /**
     * Parses two blocks of MAC address to uint16.
     *
     * Converts block ff:ff to uint16 using hex parser. Removes the blocks
     * from input string.
     *
     * @param string MAC address in text form.
     * @return First two blocks as uint16.
     */
    uint16_t blockFromString(std::string &string);

    /**
     * Converts 48 bits to bool vector.
     *
     * @param data 48 bits data as 3 uint16 fields.
     * @return Bool vector representing 48 bit data in bit form.
     */
    std::vector<bool> asBits(const uint16_t data[3]);

    /**
     * Parses 48 bit data into MAC address text form.
     *
     * @param data 48 bits data as 3 uint16 fields.
     * @return MAC address in text form.
     */
    std::string asString(const uint16_t data[3]);
};


#endif //ADDRESS_MAC_PARSER_H
