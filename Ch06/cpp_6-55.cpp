#include<iostream>
#include<vector>
using namespace std;

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

int mul(int x,int y)
{
    return x*y;
}

int divide(int x,int y)
{
    if(y)
        return x/y;
    else
    {
        return 0;
    }
}

int main()
{
    vector<decltype(add)*> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(divide);

    for (auto x : vec)
    {
        cout << x(4,7) << endl;
    }
    
    return 0;
}