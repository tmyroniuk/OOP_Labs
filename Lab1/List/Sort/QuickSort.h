//
// Created by tmyro on 22.10.2019.
//

#ifndef LAB1_QUICKSORT_H
#define LAB1_QUICKSORT_H

#include "Sort.h"

/**
 * Realises insertion sort algorithm.
 *
 * Overrides the sort method of Sort class with insertion sort.
 *
 * @tparam T Type of elements sorted.
 */
template<typename T>
class QuickSort : public Sort<T> {
public:

    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via quick sort (Hoare's algorithm is used).
     * Custom comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*compar)(const T &, const T &));
};

//Quick sort algorithm to override method sort
template<typename T>
void QuickSort<T>::sort(Iterator<T> begin, Iterator<T> end, bool (*compar)(const T &, const T &)) {
    if (begin == end) return;
    T privot = *(end - 1);
    auto i = begin;
    for (auto j = begin; j != (end - 1); j++) {
        if ((*compar)(privot, *j)) {
            std::swap(*i, *j);
            i++;
        }
    }
    std::swap(*i, *(end - 1));
    sort(begin, i, compar);
    if (i != end) sort(i + 1, end, compar);
}


#endif //LAB1_QUICKSORT_H
