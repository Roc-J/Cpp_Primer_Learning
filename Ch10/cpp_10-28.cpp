#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    list<int> ivec2, ivec3, ivec4;
    copy(ivec.begin(), ivec.end(), inserter(ivec2, ivec2.begin()));
    copy(ivec.begin(), ivec.end(), back_inserter(ivec3));
    copy(ivec.begin(), ivec.end(), front_inserter(ivec4));

    for (auto &x : ivec2)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : ivec3)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : ivec4)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}