#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    vector<int>::iterator begin = ivec.begin();
    while (begin != ivec.end())
    {
        ++begin;
        ivec.insert(begin, 42);
        ++begin;
    }
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}