#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s = "abgyjenehejem";
    decltype(s.size()) i=0;
    while (i<s.size())
    {
        s[i] = 'X';
        i++;
    }
    cout << s << endl;

    for(i; i<s.size();i++)
    {
        s[i] = 'X';
    }
    cout << s << endl;
    for(auto &c: s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}