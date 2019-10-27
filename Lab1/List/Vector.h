//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_VECTOR_H
#define LISTS_VECTOR_H

#include "BaseList.h"

//implementation of BaseList with ArrayList realisation
template<typename T>
class Vector : public BaseList<T> {
public:
    //create ArrayList realisation
    Vector();

    //access to data as in array
    T &operator[](unsigned int _val);
};

#include "Vector.inl"

#endif //LISTS_VECTOR_H
