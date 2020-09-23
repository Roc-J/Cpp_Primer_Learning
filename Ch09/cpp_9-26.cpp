#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> ivec(ia, end(ia));
    list<int> ilist(ivec.begin(), ivec.end());

    for (auto it = ilist.begin(); it != ilist.end();)
    {
        if(*it%2)
        {
            it = ilist.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    for (auto it = ivec.begin(); it != ivec.end();)
    {
        if(!(*it %2))
        {
            it = ivec.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto &x : ilist)
    {
        cout << x <<"  ";
    }
    cout << endl;
    for (auto &x : ivec)
    {
        cout << x <<"  ";
    }
    cout << endl;
    return 0;
}