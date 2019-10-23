//
// Created by tmyro on 22.10.2019.
//

#ifndef LAB1_QUICKSORT_H
#define LAB1_QUICKSORT_H

#include "Sort.h"

//Class with quick sort algorithm
template<typename T>
class QuickSort : public Sort<T> {
public:
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
