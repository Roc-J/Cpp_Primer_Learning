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

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	
}

int main(int argc, char **argv)
{
    vector<PersonInfo> people;
    readFromFile(argv[1], people);
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones)
        {
            if(!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                //format?? do what?
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            cout << entry.name << " "
                 << formatted.str() << endl;
        }
        else
        {
            cout << "input error: " << entry.name 
                 << "invalid numbers " << badNums.str() << endl;
        }
        
    }
    return 0;
}