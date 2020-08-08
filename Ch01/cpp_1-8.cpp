#include<iostream>
int main()
{
    int sum=0, val=50;
    while(val <=100)
    {
        sum += val;
        ++val;
    }
    std::cout << "the sum of 50~100 is " << sum << std::endl;
    return 0;
}