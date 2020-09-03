#include<iostream>
#include<fstream>
#include<sstream>
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

int main()
{
    vector<string> vec;
    readFromFile("./test.txt", vec);
    for (auto &item : vec)
    {
        istringstream iss(item);
        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}