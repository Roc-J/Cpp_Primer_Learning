#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int main()
{
    int x = 5, y = 10;
    cout << "before: x is " << x <<" y is " << y << endl;
    swap(&x, &y);
    cout << "after: x is " << x <<" y is " << y << endl;
    return 0;
}