#include<iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "input two numbers: " << endl;
    cin >> x >> y;
    if (y == 0)
        throw runtime_error("bad number! The divisor is 0.");
    cout << x/y;
    return 0;
}