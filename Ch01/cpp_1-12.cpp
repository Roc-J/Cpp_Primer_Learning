#include<iostream>

int main()
{
    int sum=0;
    for(int val=50; val<=100; val++)
    {
        sum += val;
    }
    std::cout << "the sum of 50-100 is " << sum << std::endl;
    return 0;
}