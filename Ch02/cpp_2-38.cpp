#include<iostream>

int main()
{
    int i=0, &r=i;

    //same
    auto a = i;
    decltype(i) b = i;

    //different
    auto c = r;
    decltype(r) d = r;
    return 0;
}