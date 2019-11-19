/**
 * @file Parser.h
 * @author tmyroniuk
 * @date 20.10.2019
 * @brief Contains declaration of Parser class.
 */

#ifndef ADDRESS_PARSER_H
#define ADDRESS_PARSER_H


#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

/**
 * ??Should be a namespace??
 * Contain methods to parse address from string.
 */
class Parser {
public:
    /**
     * Convert uint32 number into bool vector specified size.
     *
     * Used to represent address as bit vector. std::vector is memory-optimized
     * for storing bool values, so it is the best choice to store address
     * in bits form.
     *
     * @param data Number converted.
     * @param bits Size of output vector.
     * @return Output vector.
     */
    std::vector<bool> intToBits(uint32_t data, uint8_t bits);

    /**
     * Convert hex number to uint32.
     *
     * Needed to store IPv6 and MAC addresses that are written using
     * hex numbers.
     *
     * @param data String storing hex number.
     * @return Data as uint32.
     */
    uint32_t hexToInt(const std::string &data);

    /**
     * Converts uint32 number to hex in string.
     *
     * Needed to parse IPv6 and MAC addresses to string which are using
     * hex numbers.
     *
     * @param data Number converted.
     * @return String containing number hex number.
     */
    std::string intToHex(uint32_t data);
};


#endif //ADDRESS_PARSER_H
