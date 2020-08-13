#include<iostream>
#include<vector>

using namespace std;

//#define NDEBUG

void print(vector<int>::iterator beg, vector<int>::iterator end)
{
#ifndef NDEBUG
    cout << "vector size: " << end-beg << endl;
#endif
    if (beg == end)
    {
        cout << "done." << endl;
        return;
    }
    cout << *beg++ << endl;
    print(beg, end);
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    print(vec.begin(), vec.end());
    return 0;
}