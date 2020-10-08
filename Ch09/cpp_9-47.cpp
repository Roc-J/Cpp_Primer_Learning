#include<iostream>
#include<string>

using namespace std;

void _find(const string& s, const string& find_s)
{
    string::size_type pos = 0;
    while( (pos = s.find_first_of(find_s, pos)) != string::npos)
    {
        cout << pos << " ";
        ++pos;
    }
    cout << endl;
    pos = 0;
    while( (pos = s.find_first_not_of(find_s, pos)) != string::npos)
    {
        cout << pos << " ";
        ++pos;
    }
}

int main()
{
    string all = "ab2c3d7R4E6";
    string numbers = "0123456789";
    _find(all, numbers);
    return 0;
}