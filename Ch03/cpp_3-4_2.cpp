#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        if (s1.size() == s2.size())
        {
            cout << "s1 is same length with s2" << endl;
        }
        else
        {
            cout << "the bigger is: " << ((s1.size()>s2.size())?s1:s2) << endl;
        }
        
    }
    return 0;
}