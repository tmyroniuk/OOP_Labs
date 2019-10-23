//
// Created by tmyro on 22.10.2019.
//

#ifndef LAB1_MERGESORT_H
#define LAB1_MERGESORT_H

#include "Sort.h"
#include "../Vector.h"

template <typename T>
class MergeSort : public Sort<T> {
    void merge(Iterator<T> begin, Iterator<T> med, Iterator<T> end, bool(*compar)(const T &, const T &));
public:
    void sort(Iterator<T> begin, Iterator<T> end, bool(*compar)(const T &, const T &));
};

template <typename T>
void MergeSort<T>::sort(Iterator<T> begin, Iterator<T> end, bool (*compar)(const T &, const T &)) {
    if (begin == end) return;
    int len = 0;
    for (auto i = begin; i != end; len++, i++);
    auto med = begin + (len/2);
    if(len>1) {
        sort(begin, med, compar);
        sort(med, end, compar);
    }
    merge(begin, med, end, compar);
}

template<typename T>
void MergeSort<T>::merge(Iterator<T> begin, Iterator<T> med, Iterator<T> end, bool (*compar)(const T &, const T &)) {
    auto i = begin;
    auto j = med;
    Vector<T> res;
    for(auto k = begin; k!=end; k++){
        if(j==end || (i!=med && (*compar)(*j, *i))){
            res.push_back(*i);
            i++;
        }
        else {
            res.push_back(*j);
            j++;
        }
    }
    i = begin;
    for(unsigned int k=0; k<res.size(); k++, i++) *i = res[k];
}

#endif //LAB1_MERGESORT_H
