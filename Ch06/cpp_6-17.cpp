#include<iostream>
#include<string>

using namespace std;

bool isUpper(const string &s)
{
    for (auto &i : s)
    {
        if (isupper(i))
            return true;
    }
    return false;
}

void chg_lowwer(string &s)
{
    for (auto &i : s)
    {
        i = tolower(i);
    }
}

int main()
{
    string s1;
    while (cin >> s1)
    {
        bool ret = isUpper(s1);
        if (ret)
        {
            cout << s1 << " has upper alpha" << endl;
            chg_lowwer(s1);
            cout << s1 << endl;
        }
        else
        {
            cout << s1 << " has't upper alpha" <<endl;
        }   
    }
    return 0;
}