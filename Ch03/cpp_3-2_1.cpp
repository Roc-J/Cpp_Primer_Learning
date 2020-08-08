#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

int main()
{
    string line;
    cout << "input a line: " << endl;
    while(getline(cin, line))
    {
        cout << "output: " << line << endl;
        cout << "input a line: " << endl;
    }
    return 0;
}