#include<iostream>
#include<vector>
#include<algorithm>
#include "../Ch07/cpp_7-12.h"

using namespace std;

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{
    vector<Sales_data> svec;
    Sales_data val;
    while (read(cin, val))
    {
        svec.push_back(val);
    }

    sort(svec.begin(), svec.end(), compareIsbn);
    
    for (auto &x : svec)
    {
        print(cout, x);
    }
    
    return 0;
}