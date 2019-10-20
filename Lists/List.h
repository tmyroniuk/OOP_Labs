//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

#include "BaseList.h"

template<typename T>
class List : public BaseList<T> {
public:
    List();
};

#include "List.inl"


#endif //LISTS_LIST_H
