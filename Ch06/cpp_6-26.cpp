#include<iostream>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
    for (size_t i = 1; i < argc; i++)
    {
        cout << static_cast<string>(argv[i]) << endl;
    }
    return 0;
}