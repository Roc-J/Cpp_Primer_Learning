#include<iostream>
using namespace std;
int main()
{
    int i;
    while(cin >> i)
    {
        cout << i << " ";
    }

    for(int i; cin >> i;)
    {
        cout << i << " ";
    }

    for(int i=0;i<10;++i)
    {
        cout << i << " ";
    }

    int i = 0;
    while(i<10)
    {
        cout << i << " ";
        ++i;
    }
    return 0;
}