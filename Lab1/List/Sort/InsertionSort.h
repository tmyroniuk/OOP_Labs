/**
 * @file InsertionSort.h
 * @author tmyroniuk
 * @date 22.10.2019
 * @brief Contains declaration and definition of InsertionSort class.
 */

#ifndef LAB1_INSERTIONSORT_H
#define LAB1_INSERTIONSORT_H

#include "Sort.h"

/**
 * Realises insertion sort algorithm.
 *
 * Overrides the sort method of Sort class with insertion sort.
 *
 * @tparam T Type of elements sorted.
 */
template <typename T>
class InsertionSort : public Sort<T> {
public:
    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via insertion sort. Custom
     * comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &));
};

/*
 * Basic insertion sort algorithm, which sorts array
 * in range [begin, end) using comparator as >= function.
 */
template<typename T>
void InsertionSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*comparator)(const T &, const T &)) {
    for(auto i=begin; i!=end; i++){
        auto j = i;
        T temp = *i;
        while(j != begin && (*comparator)(*(j-1), temp)){
            *j = *(j-1);
            j--;
        }
        *j = temp;
    }
}


#endif //LAB1_INSERTIONSORT_H
