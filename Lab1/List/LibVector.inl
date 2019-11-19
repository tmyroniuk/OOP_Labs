//
// Created by tmyro on 18.11.2019.
//

#include "LibVector.h"

template<typename T>
LibVector<T>::LibVector() : BaseList(new VectorList<T>()) {}

template<typename T>
T &LibVector<T>::operator[](unsigned int _val) {
    return realisation->begin()->forward(_val)->getVal();
}