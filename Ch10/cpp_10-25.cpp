#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace placeholders;

void elimDups(vector<string> &words)
{
     //按字典序排序words，以便查找重复单词
     sort(words.begin(), words.end());

     auto end_unique = unique(words.begin(), words.end());

     words.erase(end_unique, words.end());
}

string make_plural(int count, string s1, string s2)
{
    string result ;
    if (count>1)
    {
        result =  s1+s2;
    }
    else
    {
        result = s1;
    }
    return result;
}

bool check_size(const string &s, string::size_type sz)
{
     return s.size() < sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
     elimDups(words);

     stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size() ;});

     auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
     auto count = words.end() - wc;

     cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl; 

     for_each(wc, words.end(), [] (const string & s) { cout << s << " " ;});

     cout << endl;
}

int main()
{
    vector<string> ivec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    biggies(ivec, 5);
    return 0;
}