#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print_int(const vector<int>& v)
{
    cout << "size: " << v.size() << endl;
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ((it!=v.end()-1)?",":"");
    }
    cout << endl;
}

void print_string(const vector<string>& v)
{
    cout << "size: " << v.size() << endl;
    for(auto it = v.begin(); it!=v.end(); ++it)
    {
        cout << *it << ((it!=v.end()-1)?",":"");
    }
    cout << endl;
}

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    print_int(v1);
    print_int(v2);
    print_int(v3);
    print_int(v4);
    print_int(v5);
    print_string(v6);
    print_string(v7);
    return 0;
}