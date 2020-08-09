#include<iostream>

using namespace std;

int main()
{
    int sum=0, val=1;
    while (val <=10)
        sum+=val, ++val;
    cout << "sum is " << sum << endl;
    return 0;
}