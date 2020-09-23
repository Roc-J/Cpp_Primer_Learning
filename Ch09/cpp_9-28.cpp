#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

int main()
{
    string s1="Hello";
    string s2="Roc-J";
    bool flag = false;
    forward_list<string> sflst = {"Hello", "World"};
    auto prev = sflst.before_begin();
    auto curr = sflst.begin();
    while (curr != sflst.end())
    {
        if (*curr == s1) 
        {
            sflst.insert_after(curr, s2);
            flag = true;
            break;
        }
        else
        {
            prev = curr;
            ++curr;
        }   
    }
    if (!flag)
        sflst.insert_after(prev, s2);
    for (auto &x : sflst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}