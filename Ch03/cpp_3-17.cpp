#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;
    vector<string> v;
    while (cin >> word)
    {
        v.push_back(word);
    }
    cout << "input all words" << endl;

    for (auto &i : v)
    {
        for (auto &j : i)
        {
            j = toupper(j);
        }
    }
    
    cout << "all words is toupper" << endl;
    for (auto &i : v)
    {
        cout << i << endl;
    }
    return 0;
}