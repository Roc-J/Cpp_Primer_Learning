#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace std;

int main()
{
    
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, "\n");
    vector<int> ivec;
    copy(in, eof, back_inserter(ivec));

    sort(ivec.begin(), ivec.end());
    unique_copy(ivec.cbegin(), ivec.cend(), out);
    return 0;
}