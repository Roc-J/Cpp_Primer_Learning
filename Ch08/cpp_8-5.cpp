#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void readFromFile(const string & filename, vector<string> & vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
        {
            vec.push_back(buf);
        }
        
    }
}

int main()
{
    vector<string> vec;
    readFromFile("./test.txt", vec);
    for (auto &item : vec)
    {
        cout << item << endl;
    }
    
    return 0;
}