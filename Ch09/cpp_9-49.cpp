#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void _find(const string& s, string& result)
{
    string not_in("dfpg");
    if (s.find_first_of(not_in) == string::npos)
    {
        result = result.size() < s.size()?s:result;
    }
}

int main()
{
    string path = "test.txt";
    ifstream ifs(path);
    if(!ifs)
    {
        cout << "open file error!" << endl;
        return -1;
    }
    string curr="", result="";
    while (ifs >> curr)
    {
        _find(curr, result);
    }
    cout << result << endl;
    return 0;
}