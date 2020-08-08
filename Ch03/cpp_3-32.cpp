#include<iostream>
#include<vector>

using namespace std; 

int main()
{
    int a[10] = {};
    int b[10];
    for(size_t i=0;i<10;i++)
    {
        a[i] = i;
        b[i] = a[i];
    }
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vec(10);
    for(size_t i=0; i<10;i++)
    {
        vec[i] = i;
    }
    vector<int> vec2(vec);
    for (auto x : vec2)
    {
        cout << x << " ";
    }

    return 0;
}