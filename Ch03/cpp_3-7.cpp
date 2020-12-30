#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s = "acbxhrrhsh";
    for (char c : s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}