//
// Created by tmyro on 15.10.2019.
//

#include "Vector.h"

template<typename T>
Vector<T>::Vector() : BaseList(new ArrayList<T>()) {}

template<typename T>
T &Vector<T>::operator[](unsigned int _val) {
    return realisation->begin()->forward(_val)->getVal();
}
