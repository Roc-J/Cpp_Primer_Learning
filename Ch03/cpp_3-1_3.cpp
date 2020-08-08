#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int x,y,temp;
    cout << "input two numbers: " << endl;
    cin >> x >> y;
    if (x>y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    while (x <= y)
    {
        cout << x << endl;
        x++;
    }
    return 0;
}