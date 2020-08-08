#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }
    cout << "origin vector is :" << endl;
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto it = vec.begin(); it !=vec.end(); it++)
    {
        /* code */
        (*it) = (*it)*2;
    }

    cout << "now vector is :" << endl;
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    return 0;
}