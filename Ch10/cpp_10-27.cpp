#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,3,4,5,6,6,7,8,9};
    list<int> ilst;
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
    for (auto &x : ilst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}