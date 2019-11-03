//
// Created by tmyro on 20.10.2019.
//

#ifndef ADDRESS_IPV4_PARSER_H
#define ADDRESS_IPV4_PARSER_H


#include "Parser.h"

/**
 * Contain methods to parse IPv4 address.
 */
class IPv4_Parser : Parser {
public:
    /**
     * Parses IPv4 address into uint32.
     *
     * Converts IPv4 address in text form into uint32 using parser.
     *
     * @param string IPv4 address in text form.
     * @return Address as uint32.
     */
    uint32_t dataFromString(const std::string &string);

    /**
     * Converts 32 bits to bool vector.
     *
     * @param data 32 bits data as uint32 field.
     * @return Bool vector representing 32 bit data in bit form.
     */
    std::vector<bool> asBits(uint32_t data);

    /**
     * Parses 32 bit data into IPv4 address text form.
     *
     * @param data 32 bits data as uint32 field.
     * @return IPv4 address in text form.
     */
    std::string asString(uint32_t data);
};


#endif //ADDRESS_IPV4_PARSER_H
