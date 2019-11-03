//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

#include "BaseList.h"

/**
 * Implements linked list.
 *
 * BaseList with LinkedList realisation. Iterators over this are safe to use after an
 * element is inserted or removed.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class List : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates List from BaseList constructor and LinkedList object as a
     * parameter.
     */
    List();
};

#include "List.inl"


#endif //LISTS_LIST_H
