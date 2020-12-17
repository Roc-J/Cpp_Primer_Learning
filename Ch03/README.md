### 习题3-1

使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。
```
#include<iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 50, sum = 0;
    while (i<=100)
    {
        sum +=i;
        i++;
    }
    cout << "the sum of 50-100 is " << sum << endl;
    return 0;
}
```

```
#include<iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 10;
    while (i>=0)
    {
        cout << i << endl;
        i--;
    }
    return 0;
}
```

```
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int x,y,temp;
    cout << "input two numbers: " << endl;
    cin >> x >> y;
    if (x>y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    while (x <= y)
    {
        cout << x << endl;
        x++;
    }
    return 0;
}
```

```
#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct Sales_data
{
    /* data */
    string bookNo;
    unsigned sales_count = 0;
    double revense = 0.0;
};

void test_1()
{
    cout << "input first sales_data data:" << endl;
    Sales_data item1;
    double price1;
    cin >> item1.bookNo >> item1.sales_count >> price1;
    item1.revense = price1 * item1.sales_count;
    cout << "output sales_data data is :" << endl;
    cout << item1.bookNo << " " << item1.sales_count 
         << " " << price1 << " " << item1.revense << endl;

}

void test_2()
{
    cout << "input first sales_data data:" << endl;
    Sales_data item1, item2;
    double price1, price2;
    cin >> item1.bookNo >> item1.sales_count >> price1;
    cout << "input second sales_data data:" << endl;
    cin >> item2.bookNo >> item2.sales_count >> price2;

    item1.revense = price1 * item1.sales_count;
    item2.revense = price2 * item2.sales_count;

    if (item1.bookNo == item2.bookNo)
    {
        int total_count = item1.sales_count + item2.sales_count;
        double total_revense = item1.revense + item2.revense;
        cout << "the total sales_count is : " << total_count << endl;
        cout << "the total sales_price is : " << total_revense << endl;
        if (total_count)
        {
            double avg_price = total_revense/total_count;
            cout << "avg price is : " << avg_price << endl;
        }
    }
    else
    {
        cout << "the two isbn is different!" << endl;
    }
    

}

int main()
{
    test_2();
    return 0;
}
```

### 习题3-2

编写一段程序从标准输入中一次读入一行，然后修改该程序使其一次读入一个词。
```
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

int main()
{
    string line;
    cout << "input a line: " << endl;
    while(getline(cin, line))
    {
        cout << "output: " << line << endl;
        cout << "input a line: " << endl;
    }
    return 0;
}
```

```
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string word;
    cout << "input a word: " << endl;
    while(cin >> word)
    {
        cout << "output: " << word << endl;
        cout << "input a word: " << endl;
    }
    return 0;
}
```

### 习题3-3

请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

* is>>s 从is中读取字符串赋给s, 字符串以空白分割，返回is；在执行读取操作时，string对象会自动忽略开头的空白（即空格符、换行符、制表符等）并从第一个真正的字符开始读取，直到遇到下一处空白为止。  
* getline函数从给定的输入流中读入内容，直到遇到换行符为止  

### 习题3-4

编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
```
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void first()
{
    string s1, s2;
    cout << "input first string : " << endl;
    cin >> s1;
    cout << "input second string : " << endl;
    cin >> s2;

    if (s1 == s2)
    {
        cout << "s1 is same to s2" << endl;
    }
    else
    {
        if(s1 > s2)
        {
            cout << s1 << " is biger" << endl;
        }
        else
        {
            cout << s2 << " is biger" << endl;
        }
        
    }
}

void second()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        if (s1 == s2)
        {
            cout << "s1 is same s2" << endl;
        }
        else
        {
            cout << "the bigger is: " << ((s1>s2)?s1:s2) << endl;
        }
        
    }
}

int main()
{
    second();
    return 0;
}
```

```
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        if (s1.size() == s2.size())
        {
            cout << "s1 is same length with s2" << endl;
        }
        else
        {
            cout << "the bigger is: " << ((s1.size()>s2.size())?s1:s2) << endl;
        }
        
    }
    return 0;
}
```

### 习题3-5

编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。
```
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s, output;
    while (cin >> s)
    {
        output += s;
    }
    cout << output << endl;

    return 0;
}
```

```
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string s, output;
    while (cin >> s)
    {
        output += s;
        output += " ";
    }
    cout << output << endl;

    return 0;
}
```

### 习题3-6

编写一段程序，使用范围for语句将字符串内所有字符用X代替。
```
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s = "abgyjenehejem";
    for(auto &c: s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}
```

### 习题3-7
就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？先估计一下结果，然后实际编程进行验证。

字符串不会发生变化。

### 习题3-8
分别用while循环和传统for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？
```
#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s = "abgyjenehejem";
    decltype(s.size()) i=0;
    while (i<s.size())
    {
        s[i] = 'X';
        i++;
    }
    cout << s << endl;

    for(i; i<s.size();i++)
    {
        s[i] = 'X';
    }
    cout << s << endl;
    for(auto &c: s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}
```
范围for语句更简洁更方便。

### 习题3-9
下面的程序有何作用？它合法吗？如果不合法？为什么？
```
string s;
cout << s[0] << endl;
```

不合法，没有判断字符串是否为空，直接访问下标访问字符串是非法操作。

### 习题3-10
编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
```
#include<iostream>
#include<string>
#include<cctype>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string s;
    while (cin >> s)
    {
        string result;
        for(auto c:s)
        {
            if(!ispunct(c))
            {
                result += c;
            }
        }
        cout << result << endl;
    }
    return 0;
}
```

### 习题3-11
下面的范围for语句合法吗？如果合法，c的类型是什么？
```
const string s = "Keep out!";
for(auto &c : s){ /* ... */ }
```

声明了一个字符串常量s,范围for语句循环遍历该字符串，如果引用对每一个字符赋值改变，则非法，如果只是输出，合法。

### 习题3-12
下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。
```
vector<vector<int>> ivec;         // 合法
vector<string> svec = ivec;       // 不合法，类型不一样
vector<string> svec(10, "null");  // 合法
```

### 习题3-13
下列的vector对象各包含多少个元素？这些元素的值分别是多少？
```
vector<int> v1;         
// size:0,  no values.
vector<int> v2(10);     
// size:10, value:0
vector<int> v3(10, 42); 
// size:10, value:42
vector<int> v4{ 10 };     
// size:1,  value:10
vector<int> v5{ 10, 42 }; 
// size:2,  value:10, 42
vector<string> v6{ 10 };  
// size:10, value:""
vector<string> v7{ 10, "hi" };  
// size:10, value:"hi"
```

### 习题3-14
编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
```
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int s;
    vector<int> obj;
    while(cin >> s)
    {
        obj.push_back(s);
    }
    return 0;
}
```

### 习题3-15
改写上题程序，不过这次读入的是字符串。
```
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string s;
    vector<string> obj;
    while(cin >> s)
    {
        obj.push_back(s);
    }
    return 0;
}
```

### 习题3-16
编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来
```
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    cout << "v1 size: " << v1.size() << endl;
    for(auto &r: v1)
    {
        cout << r << endl;
    }
    cout << "v2 size: " << v2.size() << endl;
    for(auto &r: v2)
    {
        cout << r << endl;
    }
    cout << "v3 size: " << v3.size() << endl;
    for(auto &r: v3)
    {
        cout << r << endl;
    }
    cout << "v4 size: " << v4.size() << endl;
    for(auto &r: v4)
    {
        cout << r << endl;
    }
    cout << "v5 size: " << v5.size() << endl;
    for(auto &r: v5)
    {
        cout << r << endl;
    }
    cout << "v6 size: " << v6.size() << endl;
    for(auto &r: v6)
    {
        cout << r << endl;
    }
    cout << "v7 size: " << v7.size() << endl;
    for(auto &r: v7)
    {
        cout << r << endl;
    }
    return 0;
}
```

### 习题3-17
从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。输出改变后的结果，每个词占一行。
```
#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;
    vector<string> v;
    while (cin >> word)
    {
        v.push_back(word);
    }
    cout << "input all words" << endl;

    for (auto &i : v)
    {
        for (auto &j : i)
        {
            j = toupper(j);
        }
    }
    
    cout << "all words is toupper" << endl;
    for (auto &i : v)
    {
        cout << i << endl;
    }
    return 0;
}
```

### 习题3-18 
下面的程序合法吗？如果不合法，你准备如何修改
```
vector<int> ivec;
ivec[0] = 42;
```

不合法，未初始化，不能引用下标访问
改为ivec.push_back(42);

### 习题3-19
如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请例举三种不同的实现方法，哪种方式更好呢？
```
vector<int> v1(10,42);
vector<int> v2{42,42,42,42,42,42,42,42,42,42};
vector<int> v3;
for(int i =0; i< 10; i++)
{
    v3.push_back(42);
}
```
第一种最简单方便。

### 习题3-20
读入一组整数并把他们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，接着输入第二个和倒数第二个元素的和，以此类推。
```
#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int x;
    vector<int> v;
    while(cin >> x)
    {
        v.push_back(x);
    }

    decltype(v.size()) index = 0;
    for (index ; index < v.size()-1; index++)
    {
        /* code */
        cout << v[index] + v[index+1] << endl;
    }

    auto length = v.size()-1;
    for (index =0; index < v.size(); index++)
    {
        /* code */
        cout << v[index] + v[length-index] << endl;
    }
    
    return 0;
}
```

### 习题3-21
请使用迭代器重做3.3.3节的第一个练习。
编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来
```
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print_int(const vector<int>& v)
{
    cout << "size: " << v.size() << endl;
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ((it!=v.end()-1)?",":"");
    }
    cout << endl;
}

void print_string(const vector<string>& v)
{
    cout << "size: " << v.size() << endl;
    for(auto it = v.begin(); it!=v.end(); ++it)
    {
        cout << *it << ((it!=v.end()-1)?",":"");
    }
    cout << endl;
}

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    print_int(v1);
    print_int(v2);
    print_int(v3);
    print_int(v4);
    print_int(v5);
    print_string(v6);
    print_string(v7);
    return 0;
}
```

### 习题3-22
修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后输出它。
```
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
```

### 习题3-23
编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。
```
#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(i+1);
    }
    cout << "origin vector is :" << endl;
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto it = vec.begin(); it !=vec.end(); it++)
    {
        /* code */
        (*it) = (*it)*2;
    }

    cout << "now vector is :" << endl;
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    return 0;
}
```

### 习题3-24
请使用迭代器重做3.3.3节的最后一个练习。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;
    int x;
    while(cin >> x)
    {
        vec.push_back(x);
    }

    //output
    for (auto it = vec.begin(); it != vec.end()-1; ++it)
    {
        /* code */
        cout << (*it) + *(it+1) << " ";
    }
    cout << endl;
    for (auto p = vec.begin(), q = vec.end()-1; p != vec.end(); p++,q--)
    {
        /* code */
        cout << (*p) + (*q) << " ";
    }
    
    
    return 0;
}
```

### 习题3-25
3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。
```
#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> socres(11,0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++socres[grade/10];
    }
    for (auto i : socres)
    {
        cout << i << " ";
    }
    cout << endl;

    while (cin>> grade)
    {
        if (grade <= 100)
            ++*(socres.begin() + grade/10);
    }
    for (auto i : socres)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

### 习题3-26
在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?

两个迭代器之间只能进行相减操作，代表他们之间的距离，没有相加操作。

### 习题3-27
假设txt_size 是一个无参函数，它的返回值是int。请回答下列哪个定义是非法的，为什么？
```
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```
(a)非法，数组维度必须为常量
(b)合法
(c)非法，数组维度必须为常量，txt_size()运行时才会获取到
(d)非法，还有一个空字符，大小为12

### 习题3-28
下列数组中元素的值是什么？
```
string sa[10];
int ia[10];
int main() {
	string sa2[10];
	int ia2[10];
}
```

sa 字符串初始化为空
ia 默认为0
sa2 字符串初始化为空
ia2 未定义


### 习题3-29
相比于vector 来说，数组有哪些缺点，请例举一些。

* 大小固定，不能随意向数组中增加元素。
* 不能拷贝和赋值

### 习题3-30
指出下面代码中的索引错误。
```
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
	ia[ix] = ix;
```

for语句当ix=10的时候，下标越界错误。

### 习题3-31
编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
```
#include<iostream>

using namespace std; 

int main()
{
    int a[10] = {};
    for(size_t i=0;i<10;i++)
    {
        a[i] = i;
    }
    for (auto x : a)
    {
        cout << x << " ";
    }
    
    return 0;
}
```

### 习题3-32
将上一题刚刚创建的数组拷贝给另一数组。利用vector重写程序，实现类似的功能。
```
#include<iostream>
#include<vector>

using namespace std; 

int main()
{
    int a[10] = {};
    int b[10];
    for(size_t i=0;i<10;i++)
    {
        a[i] = i;
        b[i] = a[i];
    }
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vec(10);
    for(size_t i=0; i<10;i++)
    {
        vec[i] = i;
    }
    vector<int> vec2(vec);
    for (auto x : vec2)
    {
        cout << x << " ";
    }

    return 0;
}
```

### 习题3-33
对于104页的程序来说，如果不初始化scores将会发生什么？

数组中元素值均 未定义。

### 习题3-34
假定p1 和 p2 都指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
```
p1 += p2 - p1;
```
指针p1移动到指针p2的地方。
合法

### 习题3-35
编写一段程序，利用指针将数组中的元素置为0。
```
#include<iostream>

using namespace std;

int main()
{
    int a[10] = {};
    for (size_t i = 0; i< 10; i++)
    {
        a[i] = i;
    }
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    //first
    int *p = a;
    for (size_t i = 0; i< 10; i++)
    {
        *(p + i) = 0;
    }

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    //second
    for (auto ptr = a; ptr != a + 10; ++ptr)
    {
        *ptr = 0;
    }
    return 0;
}
```

### 习题3-36
编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。

```
#include<iostream>
#include<vector>

using namespace std;

void compare_arr()
{
    int a[] = {2,5,2};
    int b[] = {2,9};
    int *p_beg = begin(a), *p_end = end(a);
    int *q_beg = begin(b), *q_end = end(b);
    if ((p_end - p_beg) != (q_end - q_beg))
    {
        cout << "array a is different b." << endl;
    }
    else
    {
        for (int *i=p_beg,*j=q_beg; i!=p_end && j!=q_end; i++,j++)
        {
            if ((*i) != (*j))
                cout << "array a is different b." << endl;
        }
        cout << "array a is same to b." << endl;
    }

    
}

int main()
{
    //两个数组大小一样了
    const int size = 10;
    int a[size], b[size];
    for(size_t i=0;i<size;i++)
        a[i] = i;
    for(size_t i=0;i<size;i++)
        b[i] = i+1;
    //compare
    int *p=a,*q=b;
    int flag = 0;
    for(int i=0;i<size; i++)
    {
        if (*p != *q)
        {
            cout << "array a is different b." << endl;
            flag = 1;
            break;
        }
        p++;
        q++;
    }
    if (!flag)
        cout << "a is same to b." << endl;

    //vector
    vector<int> v1 = {2,1,4};
    vector<int> v2 = {2,1,4};
    if (v1 == v2)
    {
        cout << "vector v1 equal v2" << endl;
    }
    else
    {
        cout << "vector v1 is different v2" << endl;
    }
    
    //
    compare_arr();
    return 0;
}
```

### 习题3-37
下面的程序是何含义，程序的输出结果是什么？
```
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```
输出字符数组ca的元素，但是没有结束符，程序不会退出循环。

### 习题3-38
在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有意义？

指针可以单个指针相加，往前移动一位，单个指针-1，往后移动一位
指向同一个数组的两个指针相减表示两个指针之间的距离；
两个指针相加是没有逻辑上的意义。

### 习题3-39
编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
```
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a = "sgghshyjn";
    string b = "agwhswn";
    if (a == b)
    {
        cout << "string a is same to b" << endl;
    }
    else
    {
        if (a < b)
        {
            cout << "string a is lager to b" << endl;
        }
        else
        {
            cout << "string a is smaller to b" << endl;
        }
        
    }
    //C 
    const char * c1 = "aaaa";
    const char * c2 = "aaaa";
    auto result = strcmp(c1, c2);
    if (result == 0)
    {
        cout << "string c1 is same to c2" << endl;
    }
    else if (result < 0)
    {
        cout << "string c1 is samller to c2" << endl;
    }
    else
    {
        cout << "string c1 is lager to c2" << endl;
    }
    return 0;
}
```

### 习题3-40
编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。
```
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    const char a[] = "hello";
    const char b[] = "world";
    char c[100];
    strcpy(c, a);
    strcat(c, b);
    cout << c << endl;
    return 0;
}
```

### 习题3-41
编写一段程序，用整型数组初始化一个vector对象。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int a[] = {2,5,7,2,4,7,10};
    vector<int> vec(a, a+7);
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vec2(begin(a), end(a));

    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题3-42
编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec = {0,4,2,6,7};
    const size_t vec_t = vec.size();
    int arr[vec_t];
    for (size_t i = 0; i < vec_t; i++)
    {
        /* code */
        arr[i] = vec[i];
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

### 习题3-43
编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通for语句，其中版本2要求使用下标运算符，版本3要求使用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字和decltype关键字。
```
#include<iostream>

using namespace std;

int main()
{
    int ia[3][4] =  {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    //range for
    for (const int (&row)[4] : ia)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
        
    }
    
    //for second
    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        for (size_t j = 0; j < 4; j++)
        {
            /* code */
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    
    //pointers
    for (int (*row)[4] = ia; row != ia + 3; row++)
    {
        /* code */
        for (int *col = *row; col != *row + 4; col++)
        {
            /* code */
            cout << *col << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
```

### 习题3-44
改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
```
#include<iostream>

using namespace std;

int main()
{
    int ia[3][4] =  {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    using int_arr = int[4];

    //range for
    for (int_arr &row : ia)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
        
    }
    
    //for second
    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        for (size_t j = 0; j < 4; j++)
        {
            /* code */
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    
    //pointers
    for (int_arr *row = ia; row != ia + 3; row++)
    {
        /* code */
        for (int *col = *row; col != *row + 4; col++)
        {
            /* code */
            cout << *col << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
```

### 习题3-45
再一次改写程序，这次使用auto关键字。
```
#include<iostream>

using namespace std;

int main()
{
    int ia[3][4] =  {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    //range for
    for (auto &row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
        
    }
    
    //for second
    for (auto i = 0; i < 3; i++)
    {
        /* code */
        for (auto j = 0; j < 4; j++)
        {
            /* code */
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    
    //pointers
    for (auto row = ia; row != ia + 3; row++)
    {
        /* code */
        for (auto col = *row; col != *row + 4; col++)
        {
            /* code */
            cout << *col << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
```