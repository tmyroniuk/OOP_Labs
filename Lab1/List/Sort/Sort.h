//
// Created by tmyro on 21.10.2019.
//

#ifndef LAB1_SORT_H
#define LAB1_SORT_H


#include "../Iterator.h"

template <typename T>
static bool compare(const T& a, const T& b){
    return a>=b;
}

template <typename T>
class Sort {
public:
    virtual void sort(Iterator<T> begin, Iterator<T> end, bool(*compar)(const T&, const T&)) = 0;

    void sort(Iterator<T> begin, Iterator<T> end){
        sort(begin, end, &compare);
    }
};

#endif //LAB1_SORT_H
