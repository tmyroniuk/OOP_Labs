//
// Created by tmyro on 05.11.2019.
//

#ifndef LAB1_BUBBLESORT_H
#define LAB1_BUBBLESORT_H

#include <iostream>
#include "Address/IPv4.h"
#include "List/Sort/Sort.h"

/**
 * Class with reverse bubble algorithm specified for IPv4 objects.
 *
 * Sorting subclass containing reversed bubble sorting algorithm
 * for sorting IPv4 objects.
 */
class BubbleSort:public Sort<IPv4>{
public:
    /**
     * Revere bubble sort algorithm.
     *
     * Sorts list of IPv4 objects in range [begin, end). Overrides
     * pure virtual method of Sort class.
     *
     * @param begin Iterator to the first position of the range.
     * @param end Iterator to the tail of the range.
     * @param comp IPv4 comparator function.
     */
    void sort(Iterator<IPv4> begin, Iterator<IPv4> end, bool(*comp)(const IPv4&, const IPv4&)){
        std::cout<<"\nBubble sorting\n";
        if(begin == end) return;
        for(auto i = begin; i!=end; i++)
            for(auto j = begin+1; j!=end; j++)
                if((*comp)(*(j), *(j-1))) std::swap(*(j-1), *j);
    }
};


#endif //LAB1_BUBBLESORT_H
