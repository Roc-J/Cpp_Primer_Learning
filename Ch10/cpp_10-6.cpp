#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    fill_n(ivec.begin(), ivec.size(), 0); 
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}