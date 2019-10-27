//
// Created by tmyro on 15.10.2019.
//

#include "List.h"

template<typename T>
List<T>::List() : BaseList(new LinkedList<T>()) {}
