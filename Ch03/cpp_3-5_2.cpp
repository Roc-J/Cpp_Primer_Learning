#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s, output;
    while (cin >> s)
    {
        output += s;
        output += " ";
    }
    cout << output << endl;

    return 0;
}