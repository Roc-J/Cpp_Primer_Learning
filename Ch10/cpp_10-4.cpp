#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<double> ivec;
    double val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }

    auto total_sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "accumulate in ivec is " << total_sum << endl;
    return 0;
}