#include<iostream>
#include<string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
    auto curr = s.begin();
    while (curr != s.end()-oldVal.size())
    {
        if (oldVal == string(curr, curr + oldVal.size()))
        {
            curr = s.erase(curr, curr + oldVal.size());
			curr = s.insert(curr, newVal.begin(), newVal.end());
        }
        else
        {
            ++curr;
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