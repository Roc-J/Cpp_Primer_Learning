#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int x[] = {1,2,3,4,5};
    vector<int> ivec;
    vector<int>::iterator iter = ivec.begin();
    for (auto &item : x)
    {
        iter = ivec.insert(iter, item);
    }
    
    for (auto &item : ivec)
    {
        cout << item << " ";
    }
    
}