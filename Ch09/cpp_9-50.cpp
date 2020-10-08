#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<string> svec = {"1","2","3"};
    long result = 0;
    for (auto &x : svec)
    {
        result += stoi(x);
    }
    cout << result << endl;

    vector<string> sdvec = {"1.1","2.2","3.3"};
    double dresult = 0.0;
    for (auto &x : sdvec)
    {
        dresult += stod(x);
    }
    cout << dresult;
    return 0;
}