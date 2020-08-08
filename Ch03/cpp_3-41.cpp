#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int a[] = {2,5,7,2,4,7,10};
    vector<int> vec(a, a+7);
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vec2(begin(a), end(a));

    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}