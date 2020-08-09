#include<iostream>
#include<string>

using namespace std;

int main()
{
    string pres,curs;
    int find = 0;
    while(cin >> curs)
    {
        if (curs == pres)
        {
            find = 1;
            break;
        }
        else
        {
            pres = curs;
        }
    }
    if (find)
    {
        cout << "the word " << curs << " is repeat." << endl;
    }
    else
    {
        cout << "No word is Continuous occurrence." << endl;
    }
    return 0;
}