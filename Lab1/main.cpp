#include <iostream>
#include "List/List.h"

int main() {
    List<int> list;
    int i=1;
    std::cout<<list.size()<<std::endl<<(list.begin()==list.end())<<std::endl<<((list.begin()+i)==list.end())<<"a"<<std::endl;
    std::cout<<"b\n";
    return 0;
}