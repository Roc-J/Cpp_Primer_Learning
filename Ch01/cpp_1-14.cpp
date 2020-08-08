#include<iostream>

int main()
{
    int num1, num2, tmp;
    std::cout << "please input two numbers: " << std::endl;
    std::cin >> num1 >> num2;

    if(num1>num2)
    {
        tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    for(num1; num1<=num2; num1++)
    {
        std::cout << num1 << std::endl;
    }

    return 0;
}