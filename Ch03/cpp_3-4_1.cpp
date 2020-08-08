#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void first()
{
    string s1, s2;
    cout << "input first string : " << endl;
    cin >> s1;
    cout << "input second string : " << endl;
    cin >> s2;

    if (s1 == s2)
    {
        cout << "s1 is same to s2" << endl;
    }
    else
    {
        if(s1 > s2)
        {
            cout << s1 << " is biger" << endl;
        }
        else
        {
            cout << s2 << " is biger" << endl;
        }
        
    }
}

void second()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        if (s1 == s2)
        {
            cout << "s1 is same s2" << endl;
        }
        else
        {
            cout << "the bigger is: " << ((s1>s2)?s1:s2) << endl;
        }
        
    }
}

int main()
{
    second();
    return 0;
}