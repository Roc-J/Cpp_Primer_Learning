#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    map<string, vector<string>> f_map;
    vector<string> svec;
    string firstName, lastName;

    cout << "input family name" << endl;
    cin >> firstName;
    while (cin >> lastName)
    {
        svec.push_back(lastName);
    }
    f_map[firstName] = svec;
    for (auto &i : f_map)
    {
        cout << "family name: " << i.first << endl;
        cout << "children names" << endl;
        for (auto &j : i.second)
        {
            cout << j << " ";
        }
        
    }
    return 0;
}