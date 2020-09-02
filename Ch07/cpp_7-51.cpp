#include<iostream>
#include<string>
#include<vector>

using namespace std;

void print(std::string str)
{
    cout << str << endl;
}

int getSize(const std::vector<int> &vec)
{
    return vec.size();
}

int main()
{
    print("test");
    //int ret = getSize(12);
    //cout << ret << endl;
    return 0;
}