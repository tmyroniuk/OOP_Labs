//
// Created by tmyro on 21.10.2019.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H


#include "../Iterator.h"

/**
 * Default comparator function.
 *
 * @tparam T Type of elements compared.
 * @param a First element.
 * @param b Second element.
 * @return If a >= b.
 */
template<typename T>
static bool compare(const T &a, const T &b) {
    return a >= b;
}

/**
 * Abstract sort class.
 *
 * Contains pure virtual method sort(Iterator<T>, Iterator<T>, comparator). Custom
 * sort algorithms should override this method. Can use either default
 * or custom comparator to sort elements.
 *
 * @tparam T Type of elements sorted.
 */
template<typename T>
class Sort {
public:

    /**
     * Sorts the elements in range [begin, end).
     *
     * Custom comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    virtual void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &)) = 0;

    /**
     * Overloads sort() function to use custom comparator.
     *
     * @overload void Sort<T>::sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &)).
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the end of the range.
     */
    void sort(Iterator<T> begin, Iterator<T> end) {
        sort(begin, end, &compare);
    }
};

#endif //LAB1_SORT_H
