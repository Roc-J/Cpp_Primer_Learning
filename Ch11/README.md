## 练习11.1

描述map和vector的不同。  
```
map是关联容器，vector是顺序容器。关联容器中的元素是按照关键字来保存和访问的。顺序容器中的元素是按照在容器中的位置来顺序保存和访问的。
```

## 练习11.2

分别给出最适合使用 list、vector、deque、map以及set的例子。
```
list：适合频繁的插入和删除操作，双向链表操作。
vector：适合频繁访问元素，适合增加操作，可自动扩容，一般优先选用vector。
duque: 适合在头尾插入删除操作，双端队列。
map:字典类型
set:元素去重。
```

## 练习11.3

编写你自己的单词计数程序。  

```
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << " "
             << ((w.second > 1)?"times":"time") << endl;
    }
    return 0;
}
```

## 练习11.4

扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。

```
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cctype>

using namespace std;


int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        for (auto &ch : word)
        {
            ch = tolower(ch);
        }
        word.erase(remove_if(word.begin(), word.end(),[](char i) {return ispunct(i);}),word.end());
        ++word_count[word];
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << " "
             << ((w.second > 1)?"times":"time") << std::endl;
    }
    return 0;
}
```

## 练习11.5  

解释map和set的区别。你如何选择使用哪个？
```
定义map时，必须既指明关键字类型又指明值类型；而定义一个set时，只需指明关键字类型，因为set中没有值。
```

## 练习11.6  

解释set和list的区别。你如何选择使用哪个。
```
set是有序不重复集合，底层实现是红黑树。
list是无序可重复集合，底层实现是链表。
```

## 练习11.7

定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
```
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    map<string, vector<string>> f_map;
    vector<string> svec;
    string firstName, lastName;

    cout << "input family name" << endl;
    cin >> firstName;
    while (cin >> lastName)
    {
        svec.push_back(lastName);
    }
    f_map[firstName] = svec;
    for (auto &i : f_map)
    {
        cout << "family name: " << i.first << endl;
        cout << "children names" << endl;
        for (auto &j : i.second)
        {
            cout << j << " ";
        }
        
    }
    return 0;
}
```

## 练习11.8

编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？
```
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> svec;
    set<string> sset;
    string word;
    while (cin >> word)
    {
        sset.insert(word);
        auto index = find(svec.begin(), svec.end(), word);
        if(!(index != svec.end()))
        {
            //cout << word << " is not in vector." << endl;
            svec.push_back(word);
        }
        
    }
    cout << "set content is " << endl;
    for (auto &i : sset)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "vector content is " << endl;
    for (auto &j : svec)
    {
        cout << j << " ";
    }
    return 0;
}
```
使用set的优点是集合内元素不重复，不需要人工判断。

## 练习11.9

