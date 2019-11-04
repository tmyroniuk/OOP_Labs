//
// Created by tmyro on 22.10.2019.
//

#ifndef LAB1_MERGESORT_H
#define LAB1_MERGESORT_H

#include "Sort.h"

#include "../Vector.h"

/**
 * Realises merge sort algorithm.
 *
 * Overrides the sort method of Sort class with merge sort.
 *
 * @tparam T Type of elements sorted.
 */
template<typename T>
class MergeSort : public Sort<T> {

    /**
     * Additional function for merge sort algorithm.
     *
     * Called by sort() method. Merges two sorted ranges into one.
     *
     * @param begin Iterator to the begin of the range.
     * @param med Iterator to the median of the range.
     * @param end Iterator to the end of the range.
     * @param comparator Custom comparator.
     */
    void merge(Iterator<T> begin, Iterator<T> med, Iterator<T> end, bool(*comparator)(const T &, const T &));

public:

    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via merge sort. Custom
     * comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &));
};

/*
 * Recursive merge sort function which uses comparator as >= and merge function
 * to merge two sorted ranges.
 */
template<typename T>
void MergeSort<T>::sort(Iterator<T> begin, Iterator<T> end, bool (*comparator)(const T &, const T &)) {
    if (begin == end) return;
    int len = 0;
    for (auto i = begin; i != end; len++, i++);
    auto med = begin + (len / 2);
    if (len > 1) {
        sort(begin, med, comparator);
        sort(med, end, comparator);
    }
    merge(begin, med, end, comparator);
}

/*
 * Merges sorted ranges [begin, med) and [med, end) into sorted range
 * [begin, end) using Vector as additional memory.
 */
template<typename T>
void
MergeSort<T>::merge(Iterator<T> begin, Iterator<T> med, Iterator<T> end, bool (*comparator)(const T &, const T &)) {
    auto i = begin;
    auto j = med;
    Vector<T> res;
    for (auto k = begin; k != end; k++) {
        if (j == end || (i != med && (*comparator)(*j, *i))) {
            res.push_back(*i);
            i++;
        } else {
            res.push_back(*j);
            j++;
        }
    }
    i = begin;
    for (unsigned int k = 0; k < res.size(); k++, i++) *i = res[k];
}

#endif //LAB1_MERGESORT_H
