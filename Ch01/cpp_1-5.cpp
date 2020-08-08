#include<iostream>

int main()
{
    std::cout << "Input two Numbers: " << std::endl;
    int x=0, y=0;
    std::cin >>  x >> y;
    std::cout << "The sum of " << x ;
    std::cout       << " and " << y;
    std::cout       << " is "  << x + y << std::endl;
    return 0;
}