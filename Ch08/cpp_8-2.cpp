#include<iostream>

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
    std::istream &is = func(std::cin);
    cout << is.rdstate() << endl;
    return 0;
}