#include<iostream>

using namespace std;

int compare(const int x, const int *p)
{
    return x>(*p)?x:(*p);
}

int main()
{
    int x,y;
    int *p=&y;
    while (cin >> x >> y)
    {
        int ret = compare(x, &y);
        cout << x << " and " << (*p) << " max is " << ret << endl;
    }
    return 0;
}