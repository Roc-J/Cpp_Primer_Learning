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
    int x = fact(5);
    cout << "5! = " << x << endl;
    return 0;
}