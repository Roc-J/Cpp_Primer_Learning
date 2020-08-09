#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec1 = {0,1,1,2,5};
    vector<int> vec2 = {0,1,1,2,4,5,6};
    size_t indexs = vec1.size()<vec2.size()?vec1.size():vec2.size();
    size_t i;
    for (i = 0; i < indexs; ++i)
    {
        if(vec1[i] != vec2[i])
            break;
    }
    if (i == indexs)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}