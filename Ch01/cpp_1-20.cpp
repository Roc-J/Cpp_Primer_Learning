#include<iostream>
#include "Sales_item.h"

int main()
{
    //for
    for(Sales_item item; std::cin>> item; std::cout << item);

    //while
    Sales_item item;
    while(std::cin>> item)
    { 
        std::cout << item;
    }
    return 0;
}

