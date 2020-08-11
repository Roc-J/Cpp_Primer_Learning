#include<iostream>
using namespace std;

int abs_x(int val)
{
    return val<0?-val:val;
}

int main()
{
    int x;
    cout << "input a number: " << endl;
    while (cin >> x)
    {
        int ret = abs_x(x);
        cout << x << " abs = " << ret << endl;
        cout << "input a number: " << endl;
    }
    return 0;
}