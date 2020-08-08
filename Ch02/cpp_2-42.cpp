#include<iostream>
#include "Sales_data.h"

void demo1()
{
    Sales_data item;
    double price;
    std::cout << "input Sales_item:" << std::endl;
    std::cin >> item.bookNo >> item.units_sold >> price;
    item.revenus = item.units_sold*price;
    std::cout << item.bookNo << " " <<  item.units_sold << " " << price << " " << item.revenus << std::endl;
}

void demo2()
{
    //编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。
    Sales_data item1, item2;
    double price1, price2;
    std::cout << "input first Sales_item:" << std::endl;
    std::cin >> item1.bookNo >> item1.units_sold >> price1;

    std::cout << "input second Sales_item:" << std::endl;
    std::cin >> item2.bookNo >> item2.units_sold >> price2;

    if(item1.bookNo == item2.bookNo)
    {
        unsigned total_c = item1.units_sold + item2.units_sold;
        double total_p = item1.units_sold * price1 + item2.units_sold * price2;
        std::cout << "The same bookNo is " << item1.bookNo << " sales total number is : " << total_c << " total price  is " << total_p;
    }
    else
    {
        std::cout << "input items bookNo is different." << std::endl;
    }
    
}

int main()
{
    //demo1();
    demo2();
    return 0;
}