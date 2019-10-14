//
// Created by tmyro on 13.10.2019.
//

#include "List_Realisation.h"

//should be used with "new NodIterator<T>(inherited)"
template<typename T>
List_Realisation<T>::List_Realisation() : len(0) {}

template<typename T>
unsigned int List_Realisation<T>::size() {
    return len;
}