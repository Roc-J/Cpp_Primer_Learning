#include<iostream>

using namespace std;

int main()
{
    int a[10] = {};
    for (size_t i = 0; i< 10; i++)
    {
        a[i] = i;
    }
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    //first
    int *p = a;
    for (size_t i = 0; i< 10; i++)
    {
        *(p + i) = 0;
    }

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    //second
    for (auto ptr = a; ptr != a + 10; ++ptr)
    {
        *ptr = 0;
    }
    return 0;
}