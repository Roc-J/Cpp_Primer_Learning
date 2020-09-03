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
        while (getline(ifs, buf))
        {
            vec.push_back(buf);
        }
        
    }
}