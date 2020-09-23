#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {1};
    if (!ivec.empty())
    {
        auto val = *ivec.begin(), val2 = ivec.front();
        auto last = ivec.end();
        auto val3 = *(--last);
        auto val4 = ivec.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    
    return 0;
}