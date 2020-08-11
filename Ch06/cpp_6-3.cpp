#include<iostream>
using namespace std;

int fact(int val)
{
    int result = 1;
    while (val > 0)
    {
        result *= val--;
    }
    return result;
}

int main()
{
    int x;
    cout << "input a number: " << endl;
    while (cin >> x)
    {
        int ret = fact(x);
        cout << x << "! = " << ret << endl;
        cout << "input a number: " << endl;
    }
    return 0;
}