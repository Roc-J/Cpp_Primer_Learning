#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

vector<PersonInfo> readFromFile(const string & filename, vector<PersonInfo> & people)
{
    string line, word;
    ifstream ifs(filename);
    if (ifs)
    {
        istringstream record;
        while (getline(ifs, line))
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record >> info.name;
            while (record >> word)
            {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }
    }
    return people;
}

int main(int argc, char **argv)
{
    vector<PersonInfo> people;
    readFromFile(argv[1], people);
    for (auto &person : people)
    {
        cout << person.name << " ";
        for (auto &info : person.phones)
        {
            cout << info << " ";
        }
        cout << endl;
    }
    return 0;
}