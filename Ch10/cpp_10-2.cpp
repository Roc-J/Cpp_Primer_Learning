#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    list<string> slist;
    string val;
    while(cin >> val)
    {
        slist.push_back(val);
    }
    string value = "123";
    auto total_sum = count(slist.cbegin(), slist.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}