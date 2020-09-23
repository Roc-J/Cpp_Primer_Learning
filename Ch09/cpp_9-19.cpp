#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
    string s;
    list<string> sdeq;
    while (cin >> s)
    {
        sdeq.push_back(s);
    }
    
    for (auto iter = sdeq.begin(); iter != sdeq.end(); ++iter)
    {
        cout << *iter << " ";
    }
    
}