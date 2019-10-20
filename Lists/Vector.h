//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_VECTOR_H
#define LISTS_VECTOR_H

#include "BaseList.h"

template<typename T>
class Vector : public BaseList<T> {
public:
    Vector();

    T &operator[](int _val);
};

#include "Vector.inl"

#endif //LISTS_VECTOR_H
