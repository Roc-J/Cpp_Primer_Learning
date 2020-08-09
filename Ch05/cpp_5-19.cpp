#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1,s2;
    string resp;
    do {
        cout << "input two string " << endl;
        cin >> s1 >> s2;
        if (s1.size() < s2.size())
        {
            cout << s1 << endl;
        }
        else
        {
            cout << s2 << endl;
        }
        cout << "continue? input Yes or No " << endl;
        cin >> resp;
    } while (!resp.empty() && tolower(resp[0]) !='n');
    return 0;
}