#include<iostream>
#include<vector>
using namespace std;

int f(int,int);

int main()
{
    vector<decltype(f) *> vec;
    auto vec(vector<int>) -> int(*)(int, int);
    return 0;
}