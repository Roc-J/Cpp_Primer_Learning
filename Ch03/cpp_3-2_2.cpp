#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string word;
    cout << "input a word: " << endl;
    while(cin >> word)
    {
        cout << "output: " << word << endl;
        cout << "input a word: " << endl;
    }
    return 0;
}