#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {1};
    if (!ivec.empty())
    {
        auto val = ivec.at(0);
        auto val2 = ivec[0];
        auto val3 = ivec.front();
        auto val4 = ivec.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    
    vector<int> ivec2;
    if (!ivec2.empty())
    {
        auto val = ivec2.at(0);
        auto val2 = ivec2[0];
        auto val3 = ivec2.front();
        auto val4 = ivec2.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    return 0;
}