/**
 * @file Iterator.h
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains declaration of Iterator class.
 */

#ifndef LISTS_ITERATOR_H
#define LISTS_ITERATOR_H


#include "List_Realisation/NodeIterator.h"

template<typename T>
class BaseList;

/**
 * Iterates over the BaseList.
 *
 * Contain a pointer to the NodeIterator of list realisation,
 * hide its operations from client.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class Iterator {
private:
    /**
     * Pointer to the node currently pointed to.
     */
    NodeIterator<T> *node;
public:

    friend BaseList<T>;

    /**
     * Default constructor.
     *
     * Creates Iterator which does not point to any node.
     */
    Iterator();

    /**
     * Copy constructor.
     *
     * Creates Iterator that points to the same node as copied.
     *
     * @param _that Iterator copied.
     */
    Iterator(const Iterator &_that);

    /**
     * Constructor with specified node.
     *
     * Creates Iterator pointing to the node given.
     *
     * @param _node ptr to the node the iterator will point to.
     */
    explicit Iterator(NodeIterator<T> *_node);

    /**
     * Copy assignment operator.
     *
     * Change the node pointed to the node other iterator points to.
     *
     * @param that Iterator copied.
     *
     * @return Reference to this iterator.
     */
    Iterator &operator=(const Iterator &that);

    /**
     * Prefix increment operator.
     *
     * Change the node pointed the next in the list.
     *
     * @return New iterator value.
     */
    Iterator &operator++();

    /**
     * Postfix increment operator.
     *
     * Change the node pointed the next in the list.
     *
     * @return Original iterator value.
     */
    Iterator operator++(int);

    /**
     * Prefix decrement operator.
     *
     * Change the node pointed the previous in the list.
     *
     * @return New iterator value.
     */
    Iterator &operator--();

    /**
     * Postfix decrement operator.
     *
     * Change the node pointed the previous in the list.
     *
     * @return Original iterator value.
     */
    Iterator operator--(int);

    /**
     * Equal operator.
     *
     * Iterators are equal if they are pointing to the same node.
     *
     * @param that Iterator to compare.
     *
     * @return If Iterators are pointing to the same node.
     */
    bool operator==(const Iterator &that);

    /**
     * Not equal operator.
     *
     * Iterators are equal if they are pointing to the same node.
     *
     * @param that Iterator to compare.
     *
     * @return If Iterators are not pointing to the same node.
     */
    bool operator!=(const Iterator &that);

    /**
     * Binary plus operator.
     *
     * Creates iterator pointing to the node that is <_val> positions after this.
     * _val Can be negative, than uses plus operator.
     *
     * @param _val Positions forward to move.
     *
     * @return Created iterator.
     */
    Iterator operator+(int _val);

    /**
     * Binary minus operator.
     *
     * Creates iterator pointing to the node that is <_val> positions before this.
     * _val can be negative, than uses minus operator.
     *
     * @param _val Positions backward to move.
     *
     * @return Created iterator.
     */
    Iterator operator-(int _val);

    /**
     * Addition assignment operator.
     *
     * Moves iterator to the node that is _val positions after current.
     * If _val is negative, uses subtraction assignment operator.
     *
     * @param _val Positions forward to move.
     *
     * @return New iterator value.
     */
    Iterator &operator+=(int _val);

    /**
     * Subtraction assignment operator.
     *
     * Moves iterator to the node that is _val positions before current.
     * If _val is negative, uses addition assignment operator.
     *
     * @param _val Operations backward to move.
     *
     * @return New iterator value.
     */
    Iterator &operator-=(int _val);

    /**
     * Indirection operator.
     *
     * Gives access to the value stored in the current node.
     *
     * @return Reference to the value stored in the node pointing to.
     */
    T &operator*();
};

#include "Iterator.inl"

#endif //LISTS_ITERATOR_H
