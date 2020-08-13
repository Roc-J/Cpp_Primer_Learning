#include<iostream>

using namespace std;

int calc_params(initializer_list<int> const &li)
{
    int ret = 0;
    for (auto x : li)
    {
        ret += x;
    }
    return ret;
}

int main()
{
    initializer_list<int>  T = {1,2,3,4,5,6,7,8,9};
    int ret = calc_params(T);
    cout << ret << endl;
    return 0;
}