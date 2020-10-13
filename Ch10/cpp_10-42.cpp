#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void elimDups(list<string> &words)
{
    //按字典序排序words，以便查找重复单词
    words.sort();
    words.unique();
}

int main()
{
    list<string> slst = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(slst);
    for (auto &x : slst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}