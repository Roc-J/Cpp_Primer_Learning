#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, item;
    if (std::cin >> sum)
    {
        while(std::cin >> item)
        {
            if (sum.isbn() == item.isbn())
            {
                sum += item;
            }
            else
            {
                std::cout << "Total sum is :" << sum << std::endl;
                sum = item;
            }   
        }
        std::cout << "Total sum is :" << sum << std::endl;
    }
    return 0;
}