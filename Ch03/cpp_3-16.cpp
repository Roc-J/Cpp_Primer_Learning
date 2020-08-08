#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    cout << "v1 size: " << v1.size() << endl;
    for(auto &r: v1)
    {
        cout << r << endl;
    }
    cout << "v2 size: " << v2.size() << endl;
    for(auto &r: v2)
    {
        cout << r << endl;
    }
    cout << "v3 size: " << v3.size() << endl;
    for(auto &r: v3)
    {
        cout << r << endl;
    }
    cout << "v4 size: " << v4.size() << endl;
    for(auto &r: v4)
    {
        cout << r << endl;
    }
    cout << "v5 size: " << v5.size() << endl;
    for(auto &r: v5)
    {
        cout << r << endl;
    }
    cout << "v6 size: " << v6.size() << endl;
    for(auto &r: v6)
    {
        cout << r << endl;
    }
    cout << "v7 size: " << v7.size() << endl;
    for(auto &r: v7)
    {
        cout << r << endl;
    }
    return 0;
}