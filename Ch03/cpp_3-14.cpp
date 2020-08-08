#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int s;
    vector<int> obj;
    while(cin >> s)
    {
        obj.push_back(s);
    }
    return 0;
}