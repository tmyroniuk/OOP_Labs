/**
 * @file Vector.inl
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of Vector class methods.
 */

#include "Vector.h"

template<typename T>
Vector<T>::Vector() : BaseList(new ArrayList<T>()) {}

template<typename T>
T &Vector<T>::operator[](unsigned int _val) {
    return realisation->begin()->forward(_val)->getVal();
}
