#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
     //按字典序排序words，以便查找重复单词
     sort(words.begin(), words.end());

     auto end_unique = unique(words.begin(), words.end());

     words.erase(end_unique, words.end());
}

bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> ivec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(ivec);
    cout << "after elimDups ..." << endl;
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;

    stable_sort(ivec.begin(), ivec.end(), isShorter);
    cout << "after stable_sort ..." << endl;
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}