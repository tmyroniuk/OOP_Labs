//
// Created by tmyro on 05.11.2019.
//

#ifndef LAB1_CUSTOMSORT_H
#define LAB1_CUSTOMSORT_H

#include <iostream>
#include "Address/MAC.h"
#include "List/Sort/Sort.h"

/**
 * Custom comparator for ints.
 *
 * Custom comparator function to sort in reverse direction.
 * @param first First number compared.
 * @param second Second number compared.
 * @return If first >= second.
 */
template <typename T>
bool customComparator(const T &first, const T &second) {
    return first <= second;
}

/**
 * Class with bubble sort algorithm.
 *
 * Sort subclass containing bubble sort algorithm
 *
 * @tparam T type of objects in list.
 */
template <typename T>
class CustomSort : public Sort<T> {
public:
    /**
     * Bubble sort algorithm.
     *
     * Sorts list of objects in range [begin, end). Overrides
     * pure virtual method of Sort class.
     *
     * @tparam T Type of objects in list.
     *
     * @param begin Iterator to the first position of the range.
     * @param end Iterator to the tail of the range.
     * @param comp comparator function.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comp)(const T &, const T &)) {
        std::cout << "\nBubble sorting\n";
        if (begin == end) return;
        for (auto i = begin; i != end; i++)
            for (auto j = begin + 1; j != end; j++)
                if ((*comp)(*(j - 1), *j)) std::swap(*(j - 1), *j);
    }
};


#endif //LAB1_CUSTOMSORT_H
