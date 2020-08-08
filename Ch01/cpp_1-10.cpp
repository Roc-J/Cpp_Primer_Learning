#include<iostream>

int main()
{
    std::cout << "Input two numbers: " << std::endl;
    int x, y, temp;
    std::cin >> x >> y;
    if(x > y)
    {
        temp = x;
        x = y;
        y = temp;

    }
    while(x<=y)
    {
        std::cout << x << std::endl;
        ++x;
    }
    return 0;
}