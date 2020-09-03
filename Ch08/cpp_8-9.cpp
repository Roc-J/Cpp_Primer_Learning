#include<iostream>
#include<sstream>
using namespace std;

std::istream& func(std::istream &is)
{
    std::string s;
    while (is >> s)
    {
        cout << s << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    istringstream iss("Hi");
    func(iss);
    return 0;
}