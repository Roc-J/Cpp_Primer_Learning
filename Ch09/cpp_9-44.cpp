#include<iostream>
#include<string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
    for (std::string::size_type i=0; i< s.size()-oldVal.size();)
    {
        if (s[i] == oldVal[0] && oldVal == s.substr(i, oldVal.size()))
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
        {
            ++i;
        }
        
    }
}

int main()
{
    string s("abcdefg");
	replace(s,"ab","111");
	replace(s,"ef","222");

	cout << s;
    return 0;
}