//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_BASELIST_H
#define LISTS_BASELIST_H

#include "List_Realisation/ListRealisation.h"
#include "Iterator.h"
#include "Sort/QuickSort.h"


/**
 * Implements client interface of the list with given realisation.
 *
 * Base class which implements list of objects with specified realisation. Objects
 * type is given as template parameter. Classes with concrete list realisation
 * should be inherited from this class.
 *
 * @tparam T Type of objects stored.
 */

template<typename T>
class BaseList {
public:
    /**
     * A constructor. Takes list realisation object ptr as a parameter.
     *
     * Creates BaseList with specified realisation. Uses exactly given pointer,
     * so should be used with new operator:
     * BaseList list(new ListRealisation<T>());
     *
     * @param type Pointer to a realisation object.
     */
    explicit BaseList(ListRealisation<T> *type);

    /**
     * A destructor.
     *
     * Deletes list realisation stored.
     */
    virtual ~BaseList();

    /**
     * Returns an Iterator<T> to the list head.
     *
     * Creates an iterator to node returned be realisation method begin()
     * as default. Can be overloaded for specific realisation.
     *
     * @return Iterator<T> to the head of the list.
     */
    virtual Iterator<T> begin();

    /**
     * Returns an Iterator<T> to the list tail.
     *
     * Creates an iterator to node returned be realisation method end()
     * as default. Note that the tail of the list is a node after the last
     * list element.
     *
     * @return  Iterator<T> to the tail of the list.
     */
    virtual Iterator<T> end();

    /**
     * Insert new node with given data before the element which iterator is given.
     *
     * Calls realisation method insert() with given data and the node iterator points to
     * as parameters. Old iterator are not safe to use after insertion.
     * Example:
     * list.insert(list.begin(), data);
     * This function call inserts given data as the first element.
     *
     * @param pos Iterator of the insertion position.
     * @param data Value being inserted.
     */
    void insert(const Iterator<T> &pos, T data);

    /**
     * Removes element from the list and returns its value.
     *
     * Calls realisation method remove() with the node iterator points to
     * as parameter. Old iterators are not safe to use after element removed.
     * If a pointer was stored it should be captured and deleted by client.
     *
     * @param pos Iterator to the element removed.
     * @return Value of the element removed.
     */
    T extract(const Iterator<T> &pos);

    /**
     * Inserts an element with given value in the end of the list.
     *
     * The element is inserted before a tail.
     * Equivalent to:
     *  list.insert(list.end(), data);
     *
     * @param data The value inserted.
     */
    void push_back(T data);

    /**
     * Removes the last element of the list and returns its value.
     *
     * The element removed is the one before tail. List must not be empty.
     * If a pointer was stored it should be captured and deleted by client.
     * Equivalent to:
     *  val = list.remove(list.end()-1);
     *
     * @return Value of the element removed.
     */
    T pop_back();

    /**
     * Inserts an element with given value as the first element of the list.
     *
     * The element is inserted before a head.
     * Equivalent to:
     *  list.insert(list.begin(), data);
     *
     * @param data The value inserted.
     */
    void push_front(T data);

    /**
     * Removes the first element of the list and returns its value.
     *
     * List must not be empty. If a pointer was stored it should be
     * captured and deleted by client.
     * Equivalent to:
     *  val = list.remove(list.begin());
     *
     * @return Value of the element removed.
     */
    T pop_front();

    /**
     * Returns a reference to the first element value.
     *
     * @return Reference to the first element value.
     */
    T &front();

    /**
     * Returns a reference to the last element value.
     *
     * @return Reference to the last element value.
     */
    T &back();

    /**
     * Returns amount of elements stored in list.
     *
     * @return Amount of elements stored in list.
     */
    unsigned int size();

    /**
     * Checks if list is empty.
     *
     * Equivalent to (list.size() == 0)
     *
     * @return If the list is empty.
     */
    bool empty();

    /**
     * Sorts the list using stored Sort<T> object and a default comparator.
     */
    void sort();

    /**
     * Sorts the list using stored Sort<T> object and given comparator.
     *
     * @param comparator Bool function that equal to >= comparison of two T variables.
     */
    virtual void sort(bool(*comparator)(const T &, const T &));

    /**
     * Sets used sorting algorithm to the given Sort<T> object ptr.
     *
     * Setter function for the sorting_algo field. Uses exactly
     * given pointer, so should be used with new operator:
     *  list.setSortingAlgo(new Sort<T>());
     *
     * @param to Pointer to the Sort<T> object with new sorting algorithm.
     */
    void setSortAlgo(Sort<T>* to);

protected:

    /**
     * Returns NodeIterator pointer stored in the iterator given.
     *
     * Extracts node from the iterator to use it in list realisation.
     *
     * @param _iterator Iterator with NodeIterator being extracted.
     *
     * @return NodeIterator ptr that was stored in the iterator.
     */
    NodeIterator<T> *getNode(const Iterator<T> &_iterator);

    /**
     * Pointer to the list realisation used.
     */
    ListRealisation<T> *realisation;

    /**
     * Pointer to the Sort<T> object which sorting algorithm is used.
     */
    Sort<T>* sorting_algo;
};

#include "BaseList.inl"

#endif //LISTS_BASELIST_H
