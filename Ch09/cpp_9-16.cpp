#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
    list<int> ili1 = {1,2,3,4,5};
    vector<int> ivec2 = {1,2,3,4,5};
    vector<int> ivec3 = {1,2,3,4};

    cout << (vector<int>(ili1.begin(),ili1.end()) == ivec2?"true":"false") << endl;
    cout << (vector<int>(ili1.begin(),ili1.end()) == ivec3?"true":"false") << endl;
    return 0;
}