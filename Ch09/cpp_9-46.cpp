#include<iostream>
#include<string>

using namespace std;

string replaceAndAppend(string& s, const string &Prefix, const string& Suffix)
{
    string::size_type pos = 0;
    s.insert(pos, Prefix);
    s.insert(s.size(), Suffix);
    return s;
}

int main()
{
    string s = "Roc-J", prex = "Mr.", suffix = "III" ;
    string result = replaceAndAppend(s, prex, suffix);
    cout << result << endl;
    return 0;
}