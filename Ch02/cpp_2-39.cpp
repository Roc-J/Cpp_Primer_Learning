#include<iostream>

struct Foo { /* 此处为空  */ }; // 注意：没有分号

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    std::string submitTime;
    double revenus = 0.0;
    unsigned units_sold =0;
    double price;
};

int main()
{
    return 0;
}