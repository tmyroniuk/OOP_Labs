/**
 * @file NodeIterator.h
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains declaration of nodeIterator class.
 */

#ifndef LISTS_NODEITERATOR_H
#define LISTS_NODEITERATOR_H

/**
 * Abstract class that implements node and iterator over list.
 *
 * Node that stores value. Its methods can manipulate value and
 * return pointers to other nodes in the list.
 *
 * @tparam T Type of elements stored.
 */
template<typename T>
class NodeIterator {
protected:
    /**
     * Stored value.
     */
    T val;

public:

    /**
     * Default constructor.
     */
    NodeIterator();

    /**
     * Creates Node with specified value.
     *
     * @param data New node value.
     */
    explicit NodeIterator(T data);

    /**
     * Returns previous node Pointer.
     *
     * @return Pointer to the previous node.
     */
    virtual NodeIterator *getPrev() = 0;

    /**
     * Returns next node pointer.
     *
     * @return Pointer to the next node.
     */
    virtual NodeIterator *getNext() = 0;

    /**
     * Returns element that is <count> positions after this.
     *
     * @param count positions forward to move.
     *
     * @return Pointer to the node that is <count> positions after this.
     */
    virtual NodeIterator *forward(int count) = 0;

    /**
     * Returns element that is <count> positions before this.
     *
     * @param count positions backward to move.
     *
     * @return Pointer to the node that is <count> positions before this.
     */
    virtual NodeIterator *backward(int count) = 0;

    /**
     * Access to stored value.
     *
     * @return Reference of the stored value.
     */
    virtual T &getVal();

    /**
     * Sets node value.
     *
     * @param _val New value
     */
    virtual void setVal(T _val);

    /**
     * Sets previous node.
     *
     * @param to New previous node.
     */
    virtual void setPrev(NodeIterator *to) = 0;

    /**
     * Sets new next node.
     *
     * @param to New next node.
     */
    virtual void setNext(NodeIterator *to) = 0;
};

#include "NodeIterator.inl"

#endif //LISTS_NODEITERATOR_H
