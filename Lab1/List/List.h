//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

#include "BaseList.h"

//implements BaseList with LinkedList realisation
template<typename T>
class List : public BaseList<T> {
public:
    //ctor set realisation to LinkedList
    List();
};

#include "List.inl"


#endif //LISTS_LIST_H
