#include<iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "input two numbers: " << endl;
    while( cin >> x >> y)
    {
        try
        {
            if (y == 0)
                throw runtime_error("bad number! The divisor is 0.");
            cout << x/y;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "are you sure again? y or n? " << endl;
            char c;
            cin >> c;
            if(c == 'n')
                break;
        }
    }
    
    return 0;
}