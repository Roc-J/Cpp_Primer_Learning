#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for (auto &x : vec)
    {
        cout << (x%2 ==0 ?x:x*2) << " ";
    }
    return 0;
}