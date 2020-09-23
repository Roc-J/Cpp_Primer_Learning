#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> iv = {1,2,3,4,1,2,3,4};
    for (auto &x : iv)
    {
        cout << x << " ";
    }
    int some_val = 2;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid)
    {
    	if (*iter == some_val)
    	{
    		iter = iv.insert(iter, 2*some_val);
            mid = iv.begin() + iv.size()/2;
    		++iter;
        }
    	++iter;
    }
    cout << endl;
    for (auto x : iv)
    {
        cout << x << " ";
    }
    
    return 0;
}

