#include<vector>
using namespace std;

bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin++ != end)
    {
        if(*begin == i)
            return true;
    }
    
    return false;
}