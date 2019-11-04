/**
 * @file ListRealisation.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of ListRealisation class methods.
 */

#include "ListRealisation.h"

template<typename T>
ListRealisation<T>::ListRealisation() : len(0) {}

template<typename T>
unsigned int ListRealisation<T>::size() {
    return len;
}
