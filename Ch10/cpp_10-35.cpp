#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    for (auto it = prev(ivec.cend()); it != ivec.cbegin(); --it)
    {
        /* code */
        cout << *it << " ";
    }
    
    return 0;
}