//
// Created by tmyro on 15.10.2019.
//

#ifndef LISTS_VECTOR_H
#define LISTS_VECTOR_H

#include "BaseList.h"

/**
 * Implements array list.
 *
 * BaseList with ArrayList realisation. Iterators over this list are NOT safe to use after an
 * element is inserted or removed.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class Vector : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates List from BaseList constructor and ArrayList object as a
     * parameter.
     */
    Vector();

    /**
     * Random access operator.
     *
     * Equal to:
     * val = *(list.begin() + _val);
     *
     * @param _val Index of element in the list (starting from zero)
     * @return Element on given index.
     */
    T &operator[](unsigned int _val);
};

#include "Vector.inl"

#endif //LISTS_VECTOR_H
