#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int x;
    vector<int> v;
    while(cin >> x)
    {
        v.push_back(x);
    }

    decltype(v.size()) index = 0;
    for (index ; index < v.size()-1; index++)
    {
        /* code */
        cout << v[index] + v[index+1] << endl;
    }

    auto length = v.size()-1;
    for (index =0; index < v.size(); index++)
    {
        /* code */
        cout << v[index] + v[length-index] << endl;
    }
    
    return 0;
}