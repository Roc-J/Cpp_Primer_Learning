#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec;
    int val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }
    int value = 5;
    auto total_sum = count(ivec.cbegin(), ivec.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}