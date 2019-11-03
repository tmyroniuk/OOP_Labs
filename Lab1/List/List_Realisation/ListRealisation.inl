//
// Created by tmyro on 13.10.2019.
//

#include "ListRealisation.h"

template<typename T>
ListRealisation<T>::ListRealisation() : len(0) {}

template<typename T>
unsigned int ListRealisation<T>::size() {
    return len;
}
