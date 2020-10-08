#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<char> cvec = {'h','e','l','l','o'};
    string s(cvec.cbegin(), cvec.cend());
    cout << s;
    return 0;
}