#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    const char a[] = "hello";
    const char b[] = "world";
    char c[100];
    strcpy(c, a);
    strcat(c, b);
    cout << c << endl;
    return 0;
}