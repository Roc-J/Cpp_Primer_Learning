#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;
    int x;
    while(cin >> x)
    {
        vec.push_back(x);
    }

    //output
    for (auto it = vec.begin(); it != vec.end()-1; ++it)
    {
        /* code */
        cout << (*it) + *(it+1) << " ";
    }
    cout << endl;
    for (auto p = vec.begin(), q = vec.end()-1; p != vec.end(); p++,q--)
    {
        /* code */
        cout << (*p) + (*q) << " ";
    }
    
    
    return 0;
}