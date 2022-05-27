#include <iostream>
#include "MyLinkedList.h"

int main()
{
    my_linked_list<int> list;

    list.insert(1);
    list.insert(2);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    std::cout<<"Removed item:"<< list.remove(3)<<std::endl;
    list.insert(3,2); 
    list.print();
    list.reverse();
    list.print();
    
    return 0;
}

