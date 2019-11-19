//
// Created by tmyro on 18.11.2019.
//

#ifndef LAB1_LIBVECTOR_H
#define LAB1_LIBVECTOR_H

#include "BaseList.h"
#include "List_Realisation/VectorList.h"
/**
 * Implements vector list.
 *
 * BaseList with VectorList realisation. Iterators over this list are NOT safe to use after an
 * element is inserted or removed.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class LibVector : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates list from BaseList constructor with VectorList object as a
     * parameter.
     */
    LibVector();

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

#include "LibVector.inl"

#endif //LAB1_LIBVECTOR_H
