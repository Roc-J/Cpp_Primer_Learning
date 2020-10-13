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

### 习题10.22  
重写统计长度小于等于6的单词数量的程序，使用函数代替 lambda。

```
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
     return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) { return a.size() < b.size() ;});

    auto ret = count_if(words.begin(), words.end(), bind(check_size, _1, sz));

    cout << ret << " " << make_plural(ret, "word", "s") << " of length " << sz << " or longer " << endl; 
}

int main()
{
    vector<string> ivec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    biggies(ivec, 6);
    return 0;
}
```

### 习题10.23   
bind 接受几个参数？

bind调用形式  
auto newCallable = bind(callable, arg_list);  
arg_list参数个数+callable 个参数  

### 习题10.24  
给定一个string，使用 bind 和 check_size 在一个 int 的vector 中查找第一个大于string长度的值。
```
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace placeholders;

bool check_size(int x, const string &a)
{
    return x > a.size();
}

int main()
{
    vector<int> ivec = {1,2,4,5,6,7,8,9};
    string s1 = "hello";

    auto f = find_if(ivec.cbegin(), ivec.cend(), bind(check_size, _1, s1));
    if(f!=ivec.end())
        cout << *f << endl;
    return 0;
}
```

### 习题10.25  
在10.3.2节的练习中，编写了一个使用partition 的biggies版本。使用 check_size 和 bind 重写此函数。
```
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
```


### 习题10.26  
解释三种迭代器的不同之处。

back_inserter 创建一个使用push_back的迭代器  
front_inserter 创建一个使用push_front的迭代器  
inserter 创建一个使用insert的迭代器。此函数接受第二个参数，这个参数 必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。  

### 习题10.27  
除了 unique 之外，标准库还定义了名为 unique_copy 的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 unique_copy将一个vector中不重复的元素拷贝到一个初始化为空的list中。
```
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,3,4,5,6,6,7,8,9};
    list<int> ilst;
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
    for (auto &x : ilst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题10.28  

一个vector 中保存 1 到 9，将其拷贝到三个其他容器中。分别使用inserter、back_inserter 和 front_inserter 将元素添加到三个容器中。对每种 inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。
```
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    list<int> ivec2, ivec3, ivec4;
    copy(ivec.begin(), ivec.end(), inserter(ivec2, ivec2.begin()));
    copy(ivec.begin(), ivec.end(), back_inserter(ivec3));
    copy(ivec.begin(), ivec.end(), front_inserter(ivec4));

    for (auto &x : ivec2)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : ivec3)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : ivec4)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题10.29  
编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里 
```
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
```

### 习题10.30  
使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。  
```
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
    copy(ivec.cbegin(), ivec.cend(), out);
    return 0;
}

```

### 习题10.31  
修改前一题的程序，使其只打印不重复的元素。你的程序应该使用 unique_copy。
```
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
```

### 习题10.32  
重写1.6节中的书店程序，使用一个vector保存交易记录，使用不同算法完成处理。使用 sort 和10.3.1节中的 compareIsbn 函数来排序交易记录，然后使用 find 和 accumulate 求和。  

```
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream:980:5: note: candidate: 'template<class _Istream, class _Tp> typename std::enable_if<std::__and_<std::__not_<std::is_lvalue_reference<_Tp> >, std::__is_convertible_to_basic_istream<_Istream>, std::__is_extractable<typename std::__is_convertible_to_basic_istream<_Tp>::__istream_type, _Tp&&, void> >::value, typename std::__is_convertible_to_basic_istream<_Tp>::__istream_type>::type std::operator>>(_Istream&&, _Tp&&)'
     operator>>(_Istream&& __is, _Tp&& __x)
     ^~~~~~~~
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream:980:5: note:   template argument deduction/substitution failed:
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream: In substitution of 'template<class _Istream, class _Tp> typename std::enable_if<std::__and_<std::__not_<std::is_lvalue_reference<_Tp> >, std::__is_convertible_to_basic_istream<_Istream>, std::__is_extractable<typename std::__is_convertible_to_basic_istream<_Tp>::__istream_type, _Tp&&, void> >::value, typename std::__is_convertible_to_basic_istream<_Tp>::__istream_type>::type std::operator>>(_Istream&&, _Tp&&) [with _Istream = std::basic_istream<char>&; _Tp = Sales_data&]':
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stream_iterator.h:121:17:   required from 'void std::istream_iterator<_Tp, _CharT, _Traits, _Dist>::_M_read() [with _Tp = Sales_data; _CharT = char; _Traits = std::char_traits<char>; _Dist = long long int]'
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/stream_iterator.h:70:9:   required from 'std::istream_iterator<_Tp, _CharT, _Traits, _Dist>::istream_iterator(std::istream_iterator<_Tp, _CharT, _Traits, _Dist>::istream_type&) [with _Tp = Sales_data; _CharT = char; _Traits = std::char_traits<char>; _Dist = long long int; std::istream_iterator<_Tp, _CharT, _Traits, _Dist>::istream_type = std::basic_istream<char>]'
cpp_10-32.cpp:18:52:   required from here
G:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/istream:980:5: error: no type named 'type' in 'struct std::enable_if<false, std::basic_istream<char>&>'
```

windows win10 VScode mingw64编译器，使用姿势不太对。

### 习题10.33  
编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用 istream_iterator 读取输入文件。使用 ostream_iterator 将奇数写入第一个输入文件，每个值后面都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。  
```
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        return -1;
    }
    ifstream ifile(argv[1]);
    ofstream of_odd(argv[2]), of_even(argv[3]);

    istream_iterator<int> in_(ifile), in_eof;
    ostream_iterator<int> out_odd(of_odd, " "), out_even(of_even, "\n");

    for_each(in_, in_eof, [&out_odd, &out_even] (const int i) {
        *(i%2==0?out_odd:out_even)++ = i;
    });

    return 0;
}
```

### 习题10.34  
使用 reverse_iterator 逆序打印一个vector。  
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    for (auto it = ivec.crbegin(); it != ivec.crend(); ++it)
    {
        /* code */
        cout << *it << " ";
    }
    
    return 0;
}
```

### 习题10.35  
使用普通迭代器逆序打印一个vector。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    for (auto it = prev(ivec.cend()); it != ivec.cbegin(); --it)
    {
        /* code */
        cout << *it << " ";
    }
    
    return 0;
}

使用prev函数
```

### 习题10.36  
使用 find 在一个 int 的list 中查找最后一个值为0的元素。  
```
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{ 
    list<int> ilst = {0,1,2,3,0,4,5,6,7,0,8,9};
    auto it = find(ilst.crbegin(), ilst.crend(), 0);
    cout << *it << endl;
    auto beg = it.base();
    while (beg != ilst.cend())
    {
        /* code */
        cout << *beg++ << " ";
    }
    
    return 0;
}
```

### 习题10.37  
给定一个包含10 个元素的vector，将位置3到7之间的元素按逆序拷贝到一个list中。
```
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    list<int> ilst;
    auto beg = find(ivec.cbegin(), ivec.cend(), 3);
    auto end = find(ivec.cbegin(), ivec.cend(), 7);
    copy(beg, end, front_inserter(ilst));
    for (auto &x : ilst)
    {
        cout << x << " ";
    }
    
    return 0;
}
```

### 习题10.38  
列出5个迭代器类别，以及每类迭代器所支持的操作。  

* 输入迭代器 ==、!=、++、*、->  
* 输出迭代器 ++、*  
* 前向迭代器 ==、!=、++、*、->  
* 双向迭代器 ==、!=、++、--、*、->  
* 随机访问迭代器 ==、!=、++、--、*、->、<=、<、>、>=、+、+=、-、-=、（减法）-、下标运算符


### 习题10.39  
list 上的迭代器属于哪类？vector呢？  
* list 上的迭代器是 双向迭代器
* vector 上的迭代器是 随机访问迭代器

### 习题10.40  
你认为 copy 要求哪类迭代器？reverse 和 unique 呢？  
* copy 需要两个输入迭代器，一个输出迭代器
* reverse 需要双向迭代器
* unique需要随机访问迭代器

### 习题10.41  
仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
```
replace(beg, end, old_val, new_val);
replace_if(beg, end, pred, new_val);
replace_copy(beg, end, dest, old_val, new_val);
replace_copy_if(beg, end, dest, pred, new_val);

replace 在输入范围内用新值替换旧值
replace_if 在输入范围内 满足谓词条件的 用新值替换旧值
replace_copy 在输入范围内，复制元素到目标迭代器位置，用新值替换旧值  
replace_copy_if 在输入范围内，复制元素到目标迭代器位置，满足谓词条件的，用新值替换旧值  
```

### 习题10.42  
使用 list 代替 vector 重新实现10.2.3节中的去除重复单词的程序。
```
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
```