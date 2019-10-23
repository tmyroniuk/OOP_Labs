//
// Created by tmyro on 22.10.2019.
//

#ifndef LAB1_INSERTIONSORT_H
#define LAB1_INSERTIONSORT_H

#include "Sort.h"

template <typename T>
class InsertionSort : public Sort<T> {
public:
    void sort(Iterator<T> begin, Iterator<T> end, bool(*compar)(const T &, const T &));
};

template<typename T>
void InsertionSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*compar)(const T &, const T &)) {
    for(auto i=begin; i!=end; i++){
        auto j = i;
        T temp = *i;
        while(j != begin && (*compar)(*(j-1), temp)){
            *j = *(j-1);
            j--;
        }
        *j = temp;
    }
}


#endif //LAB1_INSERTIONSORT_H
