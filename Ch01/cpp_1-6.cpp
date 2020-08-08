#include<iostream>

int main()
{
    std::cout << "Input two Numbers: " << std::endl;
    int x=0, y=0;
    std::cin >>  x >> y;
    std::cout << "The product of " ;
    std::cout << x;
    std::cout << " and " ;
    std::cout << y ;
    std::cout << " is " ;
    std::cout << x*y << std::endl;
    return 0;
}