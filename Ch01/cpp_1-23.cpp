#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item curr, item;
    if (std::cin >> curr)
    {
        int cnt = 1;
        while(std::cin >> item)
        {
            if (curr.isbn() == item.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout << "same is :" << cnt << std::endl;
                curr = item;
                cnt = 1;
            }   
        }
        std::cout << "same is :" << cnt << std::endl;
    }
    return 0;
}