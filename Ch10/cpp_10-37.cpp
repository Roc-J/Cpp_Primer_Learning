#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilst;
    auto beg = find(ivec.cbegin(), ivec.cend(), 3);
    auto end = find(ivec.cbegin(), ivec.cend(), 7);
    copy(beg, end, front_inserter(ilst));
    for (auto &x : ilst)
    {
        cout << x << " ";
    }
    
    return 0;
}