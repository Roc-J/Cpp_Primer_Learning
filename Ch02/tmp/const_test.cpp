#include<iostream>
using namespace std;

int main()
{
    int cnt = 0;
    const int sz = cnt;
    cout << cnt << " " << sz << endl;
    const int i = -1, &r = 0;
    return 0;
}