#include "cpp_7-11.h"

int main()
{
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("abc");
    print(std::cout, item2) << std::endl;

    Sales_data item3("abc",5,100);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;
    return 0;
}