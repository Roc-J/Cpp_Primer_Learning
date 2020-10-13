#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
 
using namespace std;  

int main()
{
    string path = "test.txt";
    ifstream ifile(path);
    istream_iterator<string> in(ifile), eof;
    vector<string> svec;
    copy(in, eof, back_inserter(svec));

    copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}