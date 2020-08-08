#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> socres(11,0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++socres[grade/10];
    }
    for (auto i : socres)
    {
        cout << i << " ";
    }
    cout << endl;

    while (cin>> grade)
    {
        if (grade <= 100)
            ++*(socres.begin() + grade/10);
    }
    for (auto i : socres)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}