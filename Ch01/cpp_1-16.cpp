#include<iostream>

int main()
{
    int sum=0, val;
    std::cout << "input your numbers" << std::endl;
    while(std::cin>> val)
    {
        sum += val;
    }
    std::cout << "your numbers sum is : " << sum << std::endl;
    return 0;
}