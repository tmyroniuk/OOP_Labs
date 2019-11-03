//
// Created by tmyro on 13.10.2019.
//

#ifndef LISTS_LINKEDLIST_H
#define LISTS_LINKEDLIST_H


#include "ListRealisation.h"

/**
 * Realisation of the doubly linked list.
 *
 * Realisation of the list which stores Nodes pointing to next and the previous.
 * List ends with tail node, first Node in the list is head.
 *
 * @tparam T Type if the elements stored.
 */
template<typename T>
class LinkedList : public ListRealisation<T> {
public:
    /**
     * Implementation of node and iterator over linked list
     *
     * Behaves as node and iterator in LinkedList. Overrides methods
     * of NodeIterator class to work with array list.
     */
    class Node : public NodeIterator<T> {
    private:
        /**
         * Pointer to the next node in the list.
         */
        NodeIterator<T> *next;

        /**
         * Pointer to the previous node in the list.
         */
        NodeIterator<T> *prev;
    public:

        /**
         * Default constructor.
         */
        Node();

        /**
         * Creates node with given value and pointers to next and previous elements.
         *
         * @param data New node value.
         * @param _prev Element before new node.
         * @param _next Element after new node.
         */
        Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next);

        /**
         * Returns ptr to the previous element.
         *
         * @return Pointer to the previous node.
         */
        NodeIterator<T> *getPrev();

        /**
         * Returns ptr to the next element.
         *
         * @return Pointer to the next node.
         */
        NodeIterator<T> *getNext();

        /**
         * Returns node <count> positions after this.
         *
         * @param count Positions forward to move.
         *
         * @return Pointer to the node <count> positions after this.
         */
        NodeIterator<T> *forward(int count);

        /**
         * Returns node <count> positions before this.
         *
         * @param count Positions backward to move.
         *
         * @return Pointer to the node <count> positions before this.
         */
        NodeIterator<T> *backward(int count);

        /**
         * Changes previous element to given.
         *
         * @param to New previous element.
         */
        virtual void setPrev(NodeIterator<T> *to);

        /**
         * Changes next element to given.
         *
         * @param to New next element.
         */
        virtual void setNext(NodeIterator<T> *to);
    };

    /**
     * Default constructor.
     *
     * Creates tail node. Set the head pointer to it. Links them.
     */
    LinkedList();

    /**
     * Inserts new element with given value before given position.
     *
     * @param pos Insertion position.
     * @param data New element value.
     */
    void insert(NodeIterator<T> *pos, T data);

    /**
     * Removes element on given position from the list, returns its value.
     *
     * @param pos Pointer to the node removed.
     *
     * @return Removed element value.
     */
    T extract(NodeIterator<T> *pos);

    /**
     * Returns pointer to the first element.
     *
     * @return Pointer to the head.
     */
    NodeIterator<T> *begin();

    /**
     * Returns pointer to the tail.
     *
     * @return Tail pointer.
     */
    NodeIterator<T> *end();

    /**
     * Destructor.
     *
     * Deletes each element of the list. Does NOT delete raw pointers stored
     * in the list.
     */
    virtual ~LinkedList();

private:

    /**
     * Pointer to the first element.
     */
    NodeIterator<T> *head;

    /**
     * Pointer to the tail. Tail always exist.
     */
    NodeIterator<T> *tail;
};

#include "LinkedList.inl"

#endif //LISTS_LINKEDLIST_H
