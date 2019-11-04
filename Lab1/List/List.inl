/**
 * @file List.inl
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of List class methods.
 */

#include "List.h"

template<typename T>
List<T>::List() : BaseList(new LinkedList<T>()) {}
