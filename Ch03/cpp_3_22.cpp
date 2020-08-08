#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void line()
{
    string s = "this is a book";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        /* code */
        if(!isspace(*it))
        {
            (*it) = toupper(*it);
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        /* code */
        cout << (*it) ;
    }
}

void lines()
{
    vector<string> vec;
    vec.push_back("this is a book");
    vec.push_back("oh, my god!");
    vec.push_back("");
    vec.push_back("no,you win~~");

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        /* code */
        for (auto line = (*it).begin(); line != (*it).end() && !(*it).empty(); ++line)
        {
            /* code */
            if(isalpha(*line))
            {
                (*line) = toupper(*line);
            }
        }  
    }

    for (auto line = vec.begin(); line !=vec.end(); line++)
    {
        /* code */
        cout << (*line);
    }
    
    
}

int main()
{
    lines();
    return 0;
}