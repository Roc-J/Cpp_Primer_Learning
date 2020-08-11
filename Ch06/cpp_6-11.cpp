#include<iostream>

using namespace std;

void reset(int &i)
{
    i= 0;
}

int main()
{
    int x = 42;
    cout << "before reset x is : " << x << endl;
    reset(x);
    cout << "after reset x is : " << x << endl;
    return 0;
}