#include<iostream>

int main()
{
    int i=0, j=1;
    int *p=&i, *q=p;

    p = &j;
    *q = j;
    return 0;
}