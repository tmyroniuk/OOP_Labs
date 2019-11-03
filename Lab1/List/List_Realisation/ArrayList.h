/**
 * @file ArrayList.h
 * @brief ArrayList class header
 */

#ifndef LISTS_ARRAYLIST_H
#define LISTS_ARRAYLIST_H

#include "ListRealisation.h"

/**
 * Realisation of array list.
 *
 * Realisation of list which stores nodes in the array. Supports
 * random access.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class ArrayList : public ListRealisation<T> {
public:
    /**
     * Implementation of node and iterator over array list
     *
     * Behaves as node and iterator in ArrayList. Overrides methods
     * of NodeIterator class to work with array list.
     */
    class Node : public NodeIterator<T> {
    public:
        /**
         * Default ctor.
         *
         * Creates empty node.
         */
        Node();

        /**
         * Constructor, takes value as argument.
         *
         * Creates node with stored value _val.
         *
         * @param _val Value stored in node.
         */
        explicit Node(T _val);

        /**
         * Returns previous node in the list.
         *
         * @return Pointer to the previous node.
         */
        NodeIterator<T> *getPrev();

        /**
         * Returns next node in the list.
         *
         * @return Pointer to the next node.
         */
        NodeIterator<T> *getNext();

        /**
         * Returns node that is <count> positions after this node.
         *
         * @param count positions forward to move.
         *
         * @return Node <count> positions after this.
         */
        NodeIterator<T> *forward(int count);

       /**
        * Returns node that is <count> positions before this node.
        *
        * @param count positions backward to move.
        *
        * @return Node <count> positions after this.
        */
        NodeIterator<T> *backward(int count);

        /**
         * Does nothing for this realisation.
         * @param to
         */
        virtual void setPrev(NodeIterator<T> *to) {}

        /**
         * Does nothing for this realisation.
         * @param to
         */
        virtual void setNext(NodeIterator<T> *to) {}
    };

    /**
     * Default constructor.
     *
     * Creates empty array list (with only tail element).
     */
    ArrayList();

    /**
     * Inserts element before <pos>.
     *
     * Inserts new node with given data before node, pointer to which is given.
     *
     * @param pos Position to insert.
     * @param data New element value.
     */
    void insert(NodeIterator<T> *pos, T data);

    /**
     * Removes the node which pointer is given from the list and return its value.
     *
     * @param pos Pointer to the node to remove.
     * @return Removed node value.
     */
    T extract(NodeIterator<T> *pos);

    /**
     * Returns pointer to the first element of the list.
     *
     * @return Pointer to the head of the list.
     */
    NodeIterator<T> *begin();

    /**
     * Returns element to the tail of the list.
     *
     * Equal to:
     *  node_ptr = realisation.begin() + realisation.size();
     * @return
     */
    NodeIterator<T> *end();

    /**
     * Destructor.
     *
     * Deletes the array of elements.
     * Does NOT delete raw pointers stored in list.
     */
    ~ArrayList();

private:

    /**
     * Times the array is increased when it overflows.
     */
    const unsigned int grow_rate;

    /**
     * Pointer to the head of the list.
     */
    NodeIterator<T> *head;

    /**
     * Current size of the array.
     */
    unsigned int reserved;

    /**
     * Increases array size in <grow_rate> times.
     */
    void grow();

    /**
     * If list is empty releases memory.
     */
    void shrink();
};

#include "ArrayList.inl"

#endif //LISTS_ARRAYLIST_H
