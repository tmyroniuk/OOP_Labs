#include <iostream>
#include "List/Vector.h"
#include "Address/IPv4.h"
#include "List/List.h"

//Custom reverse sorting algorithm (rev bubble sort)
class BubbleSort:public Sort<IPv4>{
public:
    void sort(Iterator<IPv4> begin, Iterator<IPv4> end, bool(*comp)(const IPv4&, const IPv4&)){
        std::cout<<"\nBubble sorting\n";
        if(begin == end) return;
        for(auto i = begin; i!=end; i++)
            for(auto j = begin+1; j!=end; j++)
                if((*comp)(*(j), *(j-1))) std::swap(*(j-1), *j);
    }
};

bool customComparator(const int& a, const int& b){
    return a<=b;
}

int main() {
    //Create Vector of int (array list abstraction)
    Vector<int> A;

    //Fill it with numbers from 20 to 1
    for(int i = 20; i>0; i--) A.push_back(i);

    //Add number in the front
    A.push_front(16);

    //Print Vector size and content
    std::cout<<"\nVector size is "<<A.size()<<"\nVector:\n";
    for(auto i:A) std::cout<<i<<" ";
    std::cout<<"\n";

    //Sort Vector (uses quick_sort by default)
    A.sort();
    //And print it
    std::cout<<"\nSorted Vector:\n";
    for(auto i:A) std::cout<<i<<" ";
    std::cout<<"\n";

    //Now sort it with our custom comparator
    A.sort(&customComparator);
    //Print it using array-like access
    std::cout<<"\nReverse sorted Vector:\n";
    for(unsigned int i=0; i<A.size(); i++) std::cout<<A[i]<<" ";
    std::cout<<"\n";

    //Create List (linked list abstraction) of IPv4 structure
    List<IPv4> B;
    B.push_back(IPv4("192.168.1.1"));
    B.push_back(IPv4("192.168.1.0"));
    B.push_back(IPv4("192.168.1.199"));
    B.push_front(IPv4("255.255.255.0"));

    //Print it
    std::cout<<"\nList size is "<<B.size()<<"\nList:\n";
    for(const auto& i:B) std::cout<<i.asString()<<"  ";
    std::cout<<"\n";

    //Reverse sort list using custom (rev bubble) algorithm
    B.setSortAlgo(new BubbleSort);
    B.sort();
    //And print
    std::cout<<"\nReverse sorted with custom algorithm List:\n";
    for(const auto& i:B) std::cout<<i.asString()<<"  ";
    std::cout<<"\n";

    //Print in IPv6 form
    std::cout<<"\nReverse sorted with custom algorithm List as IPv6:\n";
    for(const auto& i:B) std::cout<<i.asIPv6().asString()<<"  ";
    std::cout<<"\n";
}