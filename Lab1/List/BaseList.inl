/**
 * @file BaseList.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of BaseList class methods.
 */

#include "BaseList.h"
#include "List_Realisation/LinkedList.h"
#include "List_Realisation/ArrayList.h"


template<typename T>
NodeIterator<T> *BaseList<T>::getNode(const Iterator<T> &_iterator) {
    return _iterator.node;
}

template<typename T>
typename Iterator<T> BaseList<T>::begin() {
    return Iterator<T>(realisation->begin());
}

template<typename T>
typename Iterator<T> BaseList<T>::end() {
    return Iterator<T>(realisation->end());
}


template<typename T>
void BaseList<T>::insert(const Iterator<T> &pos, T data) {
    realisation->insert(getNode(pos), data);
}

template<typename T>
T BaseList<T>::extract(const Iterator<T> &pos) {
    return realisation->extract(getNode(pos));
}

template<typename T>
unsigned int BaseList<T>::size() {
    return realisation->size();
}

template<typename T>
BaseList<T>::BaseList(ListRealisation<T> *type) : realisation(type), sorting_algo(new QuickSort<T>) {}

template<typename T>
void BaseList<T>::push_back(T data) {
    realisation->insert(realisation->end(), data);
}

template<typename T>
void BaseList<T>::push_front(T data) {
    realisation->insert(realisation->begin(), data);
}

template<typename T>
T BaseList<T>::pop_back() {
    return realisation->extract(realisation->end()->getPrev());
}

template<typename T>
T BaseList<T>::pop_front() {
    return realisation->extract(realisation->begin());
}

template<typename T>
T &BaseList<T>::front() {
    return realisation->begin()->getVal();
}

template<typename T>
T &BaseList<T>::back() {
    return realisation->end()->getPrev()->getVal();
}

template<typename T>
BaseList<T>::~BaseList() {
    delete realisation;
}

template<typename T>
bool BaseList<T>::empty() {
    return realisation->size() == 0;
}

template<typename T>
void BaseList<T>::sort() {
    sorting_algo->sort(begin(), end());
}

template<typename T>
void BaseList<T>::sort(bool (*comparator)(const T &, const T &)) {
    sorting_algo->sort(begin(), end(), comparator);
}

template<typename T>
void BaseList<T>::setSortAlgo(Sort<T> *to) {
    delete sorting_algo;
    sorting_algo = to;
}
