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

int main()
{
    vector<string> ivec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(ivec);
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}