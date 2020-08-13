#include<iostream>

using namespace std;

void f()
{
    cout << "f() " << endl;
}

void f(int x)
{
    cout << "f(int) " << x << endl;
}

void f(int x, int y)
{
    cout << "f(int,int) " << x << " " << y << endl;
}

void f(double x, double y=3.14)
{
    cout << "f(double,double) " << x <<" " << y << endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}