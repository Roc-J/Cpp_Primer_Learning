#include<iostream>
#include<string>

using namespace std;

string replaceAndAppend(string& s, const string &Prefix, const string& Suffix)
{
    s.insert(s.begin(), Prefix.begin(), Prefix.end());
    s.append(Suffix);
    return s;
}

int main()
{
    string s = "Roc-J", prex = "Mr.", suffix = "III" ;
    string result = replaceAndAppend(s, prex, suffix);
    cout << result << endl;
    return 0;
}