#include<iostream>
#include<string>
#include<list>
#include<deque>
using namespace std;

int main()
{
    int x;
    list<int> slist;
    while (cin >> x)
    {
        slist.push_back(x);
    }
    
    deque<int> sdq1,sdq2;
    for (auto iter = slist.begin(); iter != slist.end(); ++iter)
    {
        if ((*iter)%2)
        {
            sdq1.push_back(*iter);
        }
        else
        {
            sdq2.push_back(*iter);
        }
    }
    for (auto &x : sdq1)
    {
        cout << x << " " ;
    }
    cout << endl;
    for (auto &x : sdq2)
    {
        cout << x << " " ;
    }
    cout << endl;
}