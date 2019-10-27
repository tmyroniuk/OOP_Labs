//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_BASELIST_H
#define LISTS_BASELIST_H

#include "List_Realisation/ListRealisation.h"
#include "Iterator.h"
#include "Sort/QuickSort.h"


//Abstraction in bridge pattern
//implements ListRealisation
template<typename T>
class BaseList {
public:
    //ctor with realisation ptr as param
    explicit BaseList(ListRealisation<T> *type);

    virtual ~BaseList();

    //return head iterator
    Iterator<T> begin();

    //return tail iterator
    Iterator<T> end();

    //insert element with <data> before <pos>
    void insert(const Iterator<T> &pos, T data);

    //return element on <pos> and remove it
    T extract(const Iterator<T> &pos);

    //add element with <data> before tail
    void push_back(T data);

    //return last element and remove it
    T pop_back();

    //add element with <data> as first
    void push_front(T data);

    //return first element and remove it
    T pop_front();

    //access to first element
    T &front();

    //access to last element
    T &back();

    //return amount of elements in list
    unsigned int size();

    //true if list is empty
    bool empty();

    //Run sorting algorithm
    void sort();

    //Run sorting algorithm with comparator
    virtual void sort(bool(*compar)(const T &, const T &));

    //Set
    void setSortAlgo(Sort<T>* to);
protected:
    //realisation
    ListRealisation<T> *realisation;

    //extracts node from iterator
    NodeIterator<T> *getNode(const Iterator<T> &_iterator);

    //Sorting algorithm
    //QuickSort by default
    Sort<T>* sorting_algo;
};

#include "BaseList.inl"

#endif //LISTS_BASELIST_H
