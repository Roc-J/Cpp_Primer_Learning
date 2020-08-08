#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a = "sgghshyjn";
    string b = "agwhswn";
    if (a == b)
    {
        cout << "string a is same to b" << endl;
    }
    else
    {
        if (a < b)
        {
            cout << "string a is lager to b" << endl;
        }
        else
        {
            cout << "string a is smaller to b" << endl;
        }
        
    }
    //C 
    const char * c1 = "aaaa";
    const char * c2 = "aaaa";
    auto result = strcmp(c1, c2);
    if (result == 0)
    {
        cout << "string c1 is same to c2" << endl;
    }
    else if (result < 0)
    {
        cout << "string c1 is samller to c2" << endl;
    }
    else
    {
        cout << "string c1 is lager to c2" << endl;
    }
    return 0;
}