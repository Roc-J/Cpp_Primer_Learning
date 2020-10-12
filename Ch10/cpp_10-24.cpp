#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace placeholders;

bool check_size(int x, const string &a)
{
    return x > a.size();
}

int main()
{
    vector<int> ivec = {1,2,4,5,6,7,8,9};
    string s1 = "hello";

    auto f = find_if(ivec.cbegin(), ivec.cend(), bind(check_size, _1, s1));
    if(f!=ivec.end())
        cout << *f << endl;
    return 0;
}