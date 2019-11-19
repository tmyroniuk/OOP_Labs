//
// Created by tmyro on 18.11.2019.
//

#ifndef LAB1_VECTORLIST_H
#define LAB1_VECTORLIST_H

#include <vector>
#include "ListRealisation.h"

/**
 * Realisation of vector list.
 *
 * Realisation of list which stores nodes in the std::vector. Supports
 * random access.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class VectorList : public ListRealisation<T> {
public:
    /**
     * Implementation of node and iterator over vector list
     *
     * Has to be inherited from NodeIterator class so vector::Iterator cannot
     * be used.
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
     * Creates empty vector list.
     */
    VectorList();

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

    ~VectorList();

private:
    /**
     * std::vector which actually stores the elements
     * in list.
     */
    std::vector<Node>* body;
};

#include "VectorList.inl"


#endif //LAB1_VECTORLIST_H
