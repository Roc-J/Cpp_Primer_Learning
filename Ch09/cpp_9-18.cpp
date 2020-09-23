#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    string s;
    deque<string> sdeq;
    while (cin >> s)
    {
        sdeq.push_back(s);
    }
    
    for (auto iter = sdeq.begin(); iter != sdeq.end(); ++iter)
    {
        cout << *iter << " ";
    }
    
}