#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> svec;
    set<string> sset;
    string word;
    while (cin >> word)
    {
        sset.insert(word);
        auto index = find(svec.begin(), svec.end(), word);
        if(!(index != svec.end()))
        {
            //cout << word << " is not in vector." << endl;
            svec.push_back(word);
        }
        
    }
    cout << "set content is " << endl;
    for (auto &i : sset)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "vector content is " << endl;
    for (auto &j : svec)
    {
        cout << j << " ";
    }
    return 0;
}