#include<vector>
#include<list>
using namespace std;

int main()
{
    list<int> ili(5, 5);
    vector<int> ivec(5, 5);

    vector<double> dvec(ili.begin(), ili.end());
    vector<double> dvec2(ivec.begin(), ivec.end());
    return 0;
}