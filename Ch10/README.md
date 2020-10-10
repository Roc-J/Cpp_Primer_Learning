### 习题10.1  
头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入vector中，打印有多少个元素的值等于给定值。
```
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec;
    int val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }
    int value = 5;
    auto total_sum = count(ivec.cbegin(), ivec.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.2  
重做上一题，但读取 string 序列存入 list 中。
```
#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    list<string> slist;
    string val;
    while(cin >> val)
    {
        slist.push_back(val);
    }
    string value = "123";
    auto total_sum = count(slist.cbegin(), slist.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.3  
用 accumulate求一个 vector 中元素之和。
```
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<int> ivec;
    int val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }

    auto total_sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "accumulate in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.4   
假定 v 是一个vector<double>，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？

结果是int类型
```
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<double> ivec;
    double val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }

    auto total_sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "accumulate in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.5  
在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

会比较指针地址，不会比较字符串的内容。

### 习题10.6  
编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。
```
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    fill_n(ivec.begin(), ivec.size(), 0); 
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题10.7  
下面程序是否有错误？如果有，请改正：  
```
(a) vector<int> vec; list<int> lst; int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());
(b) vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
```

(a)需要加一句 vec.resize(lst.size())  确保目标序列至少和输入序列一样大  
(b) 没有什么错误，不过将vec.reserve(10)改为vec.resize(10)  

### 习题10.8  
本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？

back_iterator是插入迭代器，不是标准库的算法。

### 习题10.9  
实现你自己的 elimDups。分别在读取输入后、调用 unique后以及调用erase后打印vector的内容。
```
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
```

### 习题10.10  
你认为算法不改变容器大小的原因是什么？

算法的接口是迭代器，迭代器操作容器，具有通用性。

### 习题10.11  
编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector的内容，验证你的程序的正确性。
```
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
```

### 习题10.12  
编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的isbn() 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。

```
#include<iostream>
#include<vector>
#include<algorithm>
#include "../Ch07/cpp_7-12.h"

using namespace std;

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{
    vector<Sales_data> svec;
    Sales_data val;
    while (read(cin, val))
    {
        svec.push_back(val);
    }

    sort(svec.begin(), svec.end(), compareIsbn);
    
    for (auto &x : svec)
    {
        print(cout, x);
    }
    
    return 0;
}
```

### 习题10.13  
标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。

```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool MoreString(const string& s1)
{
    return s1.size() >= 5;
}

int main()
{
    vector<string> svec ={"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    auto it = partition(svec.begin(), svec.end(), MoreString);
    
    for (auto itr = svec.cbegin(); itr != it; ++itr)
		std::cout << *itr << " ";
    cout << endl;
    
    while (it != svec.end())
    {
        cout << *it << " ";
        ++it;
    }
    return 0;
}
```

### 习题10.14  
编写一个 lambda ，接受两个int，返回它们的和。
```
auto f = [] (int i, int j) { return i+j;} ;
```

### 习题10.15  
编写一个 lambda ，捕获它所在函数的 int，并接受一个 int参数。lambda 应该返回捕获的 int 和 int 参数的和。
```
int x = 10;
auto f = [x] (int y) { return x+y; } ;
```

### 习题10.16  
使用 lambda 编写你自己版本的 biggies。
```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
     elimDups(words);

     stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size() ;});

     auto wc = find_if(words.begin(), words.end(), [sz] (const string &a) {return a.size() >= sz; });
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
```

### 习题10.17  
重写10.3.1节练习10.12的程序，在对sort的调用中使用 lambda 来代替函数 compareIsbn。  
```
#include<iostream>
#include<vector>
#include<algorithm>
#include "../Ch07/cpp_7-12.h"

using namespace std;

int main()
{
    vector<Sales_data> svec;
    Sales_data val;
    while (read(cin, val))
    {
        svec.push_back(val);
    }

    sort(svec.begin(), svec.end(), [](const Sales_data& s1, const Sales_data& s2) {return s1.isbn() < s2.isbn();});
    
    for (auto &x : svec)
    {
        print(cout, x);
    }
    
    return 0;
}
```

### 习题10.18  
重写 biggies，用 partition 代替 find_if。我们在10.3.1节练习10.13中介绍了 partition 算法。 
```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
     elimDups(words);

     stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size() ;});

     //auto wc = find_if(words.begin(), words.end(), [sz] (const string &a) {return a.size() >= sz; });
     auto wc = partition(words.begin(), words.end(), [sz] (const string &a) {return a.size() < sz; });
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
```

### 习题10.19  
用 stable_partition 重写前一题的程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。  
```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
     elimDups(words);

     auto wc = stable_partition(words.begin(), words.end(), [sz] (const string &a) {return a.size() < sz; });
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
```

### 习题10.20  
标准库定义了一个名为 count_if 的算法。类似 find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。

```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
     elimDups(words);
     stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size() ;});

     /*
     auto wc = find_if(words.begin(), words.end(), [sz] (const string &a) {return a.size() >= sz; });
     auto count = words.end() - wc;

     cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl; 

     for_each(wc, words.end(), [] (const string & s) { cout << s << " " ;});

     cout << endl;
     */
    auto ret = count_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz ;});

    cout << ret << " " << make_plural(ret, "word", "s") << " of length " << sz << " or longer " << endl; 
}

int main()
{
    vector<string> ivec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    biggies(ivec, 6);
    return 0;
}
```

### 习题10.21  
编写一个 lambda，捕获一个局部 int 变量，并递减变量值，直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0。
```
#include<iostream>

using namespace std;

int main()
{
    int i = 10;
    auto f = [&i] () -> bool { return (i==0?true:!(--i)); };
    while(!f())
        cout << i << " ";
    cout << endl;
    return 0;
}
```

