#include<iostream>

using namespace std;

void swap(int * &p, int * &q)
{
    auto tmp = p;
    p = q;
    q = tmp; 
}

int main()
{
    int x,y;
    int *p=&x, *q = &y;
    while (cin >> x >> y)
    {
        cout << "p is " << (*p) << " q is " << (*q) << endl;
        swap(p, q);
        cout << "p is " << (*p) << " q is " << (*q) << endl;
    }
    return 0;
}