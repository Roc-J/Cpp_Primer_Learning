#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main()
{
    map<string, vector<string>> f_map;
    for(string f_name;cout << "input family name: <quit> exit" << endl, cin >> f_name && f_name != "quit";)
    {
        for(string c_name;cout << "input child name: <quit> exit" << endl, cin >> c_name && c_name != "quit";)
        {
            f_map[f_name].push_back(c_name);
        }
    }
    for (auto &i : f_map)
    {
        cout << "family name: " << i.first << endl;
        cout << "children names" << endl;
        for (auto &j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}