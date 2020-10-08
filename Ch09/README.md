### 习题9.1
对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
```
(a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
(b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
(c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。
```
(a) list 因为要频繁执行插入操作  
(b) deque 插入和删除操作在头尾频繁执行  
(c) vector 不需要插入删除操作，优先选择vector

### 习题9.2
定义一个list对象，其元素类型是int的deque。
```
std::list<std::deque<int>> var;
```

### 习题9.3
构成迭代器范围的迭代器有何限制？  
如果满足如下条件，两个迭代器begin和end构成一个迭代器范围
* 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置，且
* 可以通过反复递增begin来到达end。换句话说，end不在begin之前。  

### 习题9.4
编写函数，接受一对指向vector的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
```
#include<vector>
using namespace std;

bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin++ != end)
    {
        if(*begin == i)
            return true;
    }
    
    return false;
}
```

### 习题9.5
重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。
```
#include<vector>
using namespace std;

vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
    while (begin != end)
    {
        if(*begin == i)
            return begin;
        ++begin;
    }
    
    return end;
}
```

### 习题9.6
下面的程序有何错误？你应该如何修改它？
```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

循环控制条件改成
```
while (iter1 != iter2)
```

### 习题9.7
为了索引int 的 vector中的元素，应该使用什么类型？
```
vector<int>::size_type;
```

### 习题9.8
为了读取string 的list 中的元素，应该使用什么类型？如果写入list，又应该使用什么类型？
```
list<string>::const_iterator  //读取
list<string>::iterator //写入
```

### 习题9.9
begin 和 cbegin 两个函数有什么不同？
```
begin返回的是普通迭代器，cbegin返回的是const 迭代器
```

### 习题9.10
下面4个对象分别是什么类型？
```
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

在VScode中报错
```
error: inconsistent deduction for 'auto': '__gnu_cxx::__normal_iterator<int*, std::vector<int> >' and then '__gnu_cxx::__normal_iterator<const int*, std::vector<int> >'
 auto it1 = v1.begin(), it2 = v2.begin();


需要做一下修改
#include<vector>
using namespace std;

int main()
{
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();
    auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
    return 0;
}


it1是普通的begin迭代器
it2,it3,it4是常量的begin迭代器
```
### 习题9.11
对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。
```
vector<int> vec;
vector<int> vec(10);
vector<int> vec(10, 1);
vector<int> vec{1,2,3,4,5,6};
vector<int> vec2(vec1);
vector<int> vec2(vec1.begin(), vec1.end());
```

### 习题9.12
对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。
```
接受一个容器创建其拷贝的构造函数，两个容器的类型及其元素类型必须匹配。  
接受两个迭代器创建拷贝的构造函数,不要求容器类型是相同的,只需要元素的类型能够相互转换。
```

### 习题9.13
如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。
```
使用接受两个迭代器创建拷贝的构造函数即可。

#include<vector>
#include<list>
using namespace std;

int main()
{
    list<int> ili(5, 5);
    vector<int> ivec(5, 5);

    vector<double> dvec(ili.begin(), ili.end());
    vector<double> dvec2(ivec.begin(), ivec.end());
    return 0;
}
```

### 习题9.14
编写程序，将一个list中的char * 指针元素赋值给一个vector中的string。

list<char *> clist={"hello","world"};
vector<string> svec;
svec.assign(clist.cbegin(), clist.cend());

### 习题9.15
编写程序，判定两个vector是否相等。
```
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec1 = {1,2,3,4,5};
    vector<int> ivec2 = {1,2,3,4,5};
    vector<int> ivec3 = {1,2,3,4};

    cout << (ivec1 == ivec2?"true":"false") << endl;
    cout << (ivec1 == ivec3?"true":"false") << endl;
    return 0;
}
```

### 习题9.16
重写上一题的程序，比较一个list中的元素和一个vector中的元素。

不能直接比较的，需要做转换！
```
#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
    list<int> ili1 = {1,2,3,4,5};
    vector<int> ivec2 = {1,2,3,4,5};
    vector<int> ivec3 = {1,2,3,4};

    cout << (vector<int>(ili1.begin(),ili1.end()) == ivec2?"true":"false") << endl;
    cout << (vector<int>(ili1.begin(),ili1.end()) == ivec3?"true":"false") << endl;
    return 0;
}
```

### 习题9.17
假定c1 和 c2 是两个容器，下面的比较操作有何限制？
```
if (c1 < c2)

```
* c1和c2必须是相同类型的容器并且保存相同类型的元素  
* 元素类型要支持关系运算符  

### 习题9.18
编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。
```
#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    string s;
    deque<string> sdeq;
    while (cin >> s)
    {
        sdeq.push_back(s);
    }
    
    for (auto iter = sdeq.begin(); iter != sdeq.end(); ++iter)
    {
        cout << *iter << " ";
    }
    
}
```

### 习题9.19
重写上一题的程序，用list替代deque。列出程序要做出哪些改变。
```
改动一下声明即可

#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
    string s;
    list<string> sdeq;
    while (cin >> s)
    {
        sdeq.push_back(s);
    }
    
    for (auto iter = sdeq.begin(); iter != sdeq.end(); ++iter)
    {
        cout << *iter << " ";
    }
    
}

```

### 习题9.20
编写程序，从一个list拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。
```
#include<iostream>
#include<string>
#include<list>
#include<deque>
using namespace std;

int main()
{
    int x;
    list<int> slist;
    while (cin >> x)
    {
        slist.push_back(x);
    }
    
    deque<int> sdq1,sdq2;
    for (auto iter = slist.begin(); iter != slist.end(); ++iter)
    {
        if ((*iter)%2)
        {
            sdq1.push_back(*iter);
        }
        else
        {
            sdq2.push_back(*iter);
        }
    }
    for (auto &x : sdq1)
    {
        cout << x << " " ;
    }
    cout << endl;
    for (auto &x : sdq2)
    {
        cout << x << " " ;
    }
    cout << endl;
}
```

### 习题9.21
如果我们将第308页中使用 insert 返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

结果是一样的。
```
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int x[] = {1,2,3,4,5};
    vector<int> ivec;
    vector<int>::iterator iter = ivec.begin();
    for (auto &item : x)
    {
        iter = ivec.insert(iter, item);
    }
    
    for (auto &item : ivec)
    {
        cout << item << " ";
    }
    
}
```

在循环之前，iter初始化为vector的begin()位置。第一次调用insert会将刚刚读入的int插入到iter所指向的元素之前的位置。insert返回的迭代器恰好指向这个新元素。我们将此迭代器赋予iter并重复循环，读取下一个int。遍历int的数组，每次都会将一个新元素插入到iter之前，并将iter改变为新加入元素的位置。此元素为（新的）首元素。因此，每步循环将一个新元素插入到vector首元素之前的位置。

### 习题9.22
假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
```
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```

迭代器会失效，循环不会结束。

```
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> iv = {1,2,3,4,1,2,3,4};
    for (auto &x : iv)
    {
        cout << x << " ";
    }
    int some_val = 2;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid)
    {
    	if (*iter == some_val)
    	{
    		iter = iv.insert(iter, 2*some_val);
            mid = iv.begin() + iv.size()/2;
    		++iter;
        }
    	++iter;
    }
    cout << endl;
    for (auto x : iv)
    {
        cout << x << " ";
    }
    
    return 0;
}

```

### 习题9.23
在本节第一个程序中，若 c.size() 为1，则val、val2、val3和val4的值会是什么？

是同一个值

```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {1};
    if (!ivec.empty())
    {
        auto val = *ivec.begin(), val2 = ivec.front();
        auto last = ivec.end();
        auto val3 = *(--last);
        auto val4 = ivec.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    
    return 0;
}
```

### 习题9.24
编写程序，分别使用 at、下标运算符、front 和 begin 提取一个vector中的第一个元素。在一个空vector上测试你的程序。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec = {1};
    if (!ivec.empty())
    {
        auto val = ivec.at(0);
        auto val2 = ivec[0];
        auto val3 = ivec.front();
        auto val4 = ivec.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    
    vector<int> ivec2;
    if (!ivec2.empty())
    {
        auto val = ivec2.at(0);
        auto val2 = ivec2[0];
        auto val3 = ivec2.front();
        auto val4 = ivec2.back();

        cout << "val: " << val << endl;
        cout << "val2: " << val2 << endl;
        cout << "val3: " << val3 << endl;
        cout << "val4: " << val4 << endl;
    }
    return 0;
}

如果不判断为空的话，会报错
terminate called after throwing an instance of 'std::out_of_range'
what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
```

### 习题9.25
对于第312页中删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？

* 如果 elem1 与 elem2 相等 循环跳出，不执行操作
* elem3是尾号迭代器，删除从elem1到最后的所有元素  
*  elem1 和 elem2 皆为尾后迭代器 循环跳出，不执行操作

### 习题9.26
使用下面代码定义的ia，将ia 拷贝到一个vector和一个list中。是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
```
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

```
#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> ivec(ia, end(ia));
    list<int> ilist(ivec.begin(), ivec.end());

    for (auto it = ilist.begin(); it != ilist.end();)
    {
        if(*it%2)
        {
            it = ilist.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    for (auto it = ivec.begin(); it != ivec.end();)
    {
        if(!(*it %2))
        {
            it = ivec.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto &x : ilist)
    {
        cout << x <<"  ";
    }
    cout << endl;
    for (auto &x : ivec)
    {
        cout << x <<"  ";
    }
    cout << endl;
    return 0;
}
```

### 习题9.27
编写程序，查找并删除forward_list中的奇数元素。
```
#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2) 
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }   
    }
    for (auto &x : flst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题9.28
编写函数，接受一个forward_list和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。
```
#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

int main()
{
    string s1="Hello";
    string s2="Roc-J";
    bool flag = false;
    forward_list<string> sflst = {"Hello", "World"};
    auto prev = sflst.before_begin();
    auto curr = sflst.begin();
    while (curr != sflst.end())
    {
        if (*curr == s1) 
        {
            sflst.insert_after(curr, s2);
            flag = true;
            break;
        }
        else
        {
            prev = curr;
            ++curr;
        }   
    }
    if (!flag)
        sflst.insert_after(prev, s2);
    for (auto &x : sflst)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题9.29
假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？

```
vec.resize(100)会将75个值为0 的元素添加到vec的末尾  
vec.resize(10) 从vec的末尾删除90个元素。
```

### 习题9.30
接受单个参数的resize版本对元素类型有什么限制（如果有的话）？

元素类型必须提供默认构造函数。  

### 习题9.31
第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。

因为复合赋值语句只能用于string、vector、deque、array,所以将iter+=2改为
++iter;
++iter;

如果使用forward_list的话，需要增加一个首前迭代器prev  
```
#include<forward_list>
#include<iostream>

using namespace std;

int main()
{
    forward_list<int> iflist = {0,1,2,3,4,5,6,7,8,9};
    auto curr = iflist.begin(), prev = iflist.before_begin();
    while (curr != iflist.end())
    {
        if(*curr %2)
        {
            curr = iflist.insert_after(prev, *curr);
            ++curr;
            ++curr;
            ++prev;
            ++prev;
        }
        else
        {
            curr = iflist.erase_after(prev);
        }
    }
    for (auto &x : iflist)
    {
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}
```

### 习题9.32
在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
```
iter = vi.insert(iter, *iter++);
```

不合法。因为参数的求值顺序是未指定的。

### 习题9.33
在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

begin将无效
```
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    vector<int>::iterator begin = ivec.begin();
    while (begin != ivec.end())
    {
        ++begin;
        ivec.insert(begin, 42);
        ++begin;
    }
    for (auto &x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

### 习题9.34
假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
```
iter = vi.begin();
while (iter != vi.end())
	if (*iter % 2)
		iter = vi.insert(iter, *iter);
	++iter;
```

循环永远不会结束。

### 习题9.35
解释一个vector的capacity和size有何区别。

容器的size是指它已经保存的元素的数目  
capacity则是在不分配新的内存空间的前提下它最多可以保存多少元素。 

### 习题9.36
一个容器的capacity可能小于它的size吗？

不可能

### 习题9.37
为什么list或array没有capacity成员函数？

list是链表，array是固定数组，不允许改变容器大小

### 习题9.38
编写程序，探究在你的标准实现中，vector是如何增长的。
```
#include<iostream>
#include<vector>

using namespace std;

void printInfo(vector<int> &vec)
{
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
}

int main()
{
    vector<int> ivec;
    printInfo(ivec);

    for (vector<int>::size_type i = 0; i <= 100; ++i)
    {
        ivec.push_back(i);
        printInfo(ivec);
    }
    
    return 0;
}

size: 0 capacity: 0  
size: 1 capacity: 1  
size: 2 capacity: 2  
size: 3 capacity: 4  
size: 4 capacity: 4  
size: 5 capacity: 8  
size: 6 capacity: 8  
size: 7 capacity: 8  
size: 8 capacity: 8  
size: 9 capacity: 16 
size: 10 capacity: 16
size: 11 capacity: 16
size: 12 capacity: 16
size: 13 capacity: 16
size: 14 capacity: 16
size: 15 capacity: 16
size: 16 capacity: 16
size: 17 capacity: 32
size: 18 capacity: 32
size: 19 capacity: 32
size: 20 capacity: 32
size: 21 capacity: 32
size: 22 capacity: 32
size: 23 capacity: 32
size: 24 capacity: 32
size: 25 capacity: 32
size: 26 capacity: 32
size: 27 capacity: 32
size: 28 capacity: 32
size: 29 capacity: 32
size: 30 capacity: 32
size: 31 capacity: 32
size: 32 capacity: 32
size: 33 capacity: 64
size: 34 capacity: 64
size: 35 capacity: 64
size: 36 capacity: 64
size: 37 capacity: 64
size: 38 capacity: 64
size: 39 capacity: 64
size: 40 capacity: 64
size: 41 capacity: 64
size: 42 capacity: 64
size: 43 capacity: 64
size: 44 capacity: 64
size: 45 capacity: 64
size: 46 capacity: 64
size: 47 capacity: 64
size: 48 capacity: 64
size: 49 capacity: 64
size: 50 capacity: 64
size: 51 capacity: 64
size: 52 capacity: 64
size: 53 capacity: 64
size: 54 capacity: 64
size: 55 capacity: 64
size: 56 capacity: 64
size: 57 capacity: 64
size: 58 capacity: 64
size: 59 capacity: 64
size: 60 capacity: 64
size: 61 capacity: 64
size: 62 capacity: 64
size: 63 capacity: 64
size: 64 capacity: 64
size: 65 capacity: 128
size: 66 capacity: 128
size: 67 capacity: 128
size: 68 capacity: 128
size: 69 capacity: 128
size: 70 capacity: 128
size: 71 capacity: 128
size: 72 capacity: 128
size: 73 capacity: 128
size: 74 capacity: 128
size: 75 capacity: 128
size: 76 capacity: 128
size: 77 capacity: 128
size: 78 capacity: 128
size: 79 capacity: 128
size: 80 capacity: 128
size: 81 capacity: 128
size: 82 capacity: 128
size: 83 capacity: 128
size: 84 capacity: 128
size: 85 capacity: 128
size: 86 capacity: 128
size: 87 capacity: 128
size: 88 capacity: 128
size: 89 capacity: 128
size: 90 capacity: 128
size: 91 capacity: 128
size: 92 capacity: 128
size: 93 capacity: 128
size: 94 capacity: 128
size: 95 capacity: 128
size: 96 capacity: 128
size: 97 capacity: 128
size: 98 capacity: 128
size: 99 capacity: 128
size: 100 capacity: 128
size: 101 capacity: 128
```

### 习题9.39
解释下面程序片段做了什么：
```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```

定义了一个vector，分配1024个元素空间，然后循环读入字符串添加到vector中，循环结束后，改变vector的容器大小为原来的1.5倍，多余的元素使用默认初始化填充。如果容器超过1024，vector也会重新分配内存大小。

### 习题9.40
如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个、或1048个呢？

256 capacity：1024
512 capacity：1024
1000 capacity：1024
1048 capacity 会扩大，具体看机器实现。


### 习题9.41
编写程序，从一个vector初始化一个string。
```
vector<char> cvec={'h','e','l','l','o'};
string s(cvec.cbegin(), cvec.cend());
```

### 习题9.42
假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

使用reserve(100) 预先分配100个元素的空间。

### 习题9.43
编写一个函数，接受三个string参数是s、oldVal 和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

```
#include<iostream>
#include<string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
    auto curr = s.begin();
    while (curr != s.end()-oldVal.size())
    {
        if (oldVal == string(curr, curr + oldVal.size()))
        {
            curr = s.erase(curr, curr + oldVal.size());
			curr = s.insert(curr, newVal.begin(), newVal.end());
        }
        else
        {
            ++curr;
        }
    }
}

int main()
{
    string s("abcdefg");
	replace(s,"ab","111");
	replace(s,"ef","222");

	cout << s;
    return 0;
}
```

### 习题9.44
重写上一题的函数，这次使用一个下标和replace。

```
#include<iostream>
#include<string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
    for (std::string::size_type i=0; i< s.size()-oldVal.size();)
    {
        if (s[i] == oldVal[0] && oldVal == s.substr(i, oldVal.size()))
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
        {
            ++i;
        }
        
    }
}

int main()
{
    string s("abcdefg");
	replace(s,"ab","111");
	replace(s,"ef","222");

	cout << s;
    return 0;
}
```

### 习题9.45
编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。
```
#include<iostream>
#include<string>

using namespace std;

string replaceAndAppend(string& s, const string &Prefix, const string& Suffix)
{
    s.insert(s.begin(), Prefix.begin(), Prefix.end());
    s.append(Suffix);
    return s;
}

int main()
{
    string s = "Roc-J", prex = "Mr.", suffix = "III" ;
    string result = replaceAndAppend(s, prex, suffix);
    cout << result << endl;
    return 0;
}
```

### 习题9.46
重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。
```
#include<iostream>
#include<string>

using namespace std;

string replaceAndAppend(string& s, const string &Prefix, const string& Suffix)
{
    string::size_type pos = 0;
    s.insert(pos, Prefix);
    s.insert(s.size(), Suffix);
    return s;
}

int main()
{
    string s = "Roc-J", prex = "Mr.", suffix = "III" ;
    string result = replaceAndAppend(s, prex, suffix);
    cout << result << endl;
    return 0;
}
```

### 习题9.47
编写程序，首先查找string"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。

```
#include<iostream>
#include<string>

using namespace std;

void _find(const string& s, const string& find_s)
{
    string::size_type pos = 0;
    while( (pos = s.find_first_of(find_s, pos)) != string::npos)
    {
        cout << pos << " ";
        ++pos;
    }
    cout << endl;
    pos = 0;
    while( (pos = s.find_first_not_of(find_s, pos)) != string::npos)
    {
        cout << pos << " ";
        ++pos;
    }
}

int main()
{
    string all = "ab2c3d7R4E6";
    string numbers = "0123456789";
    _find(all, numbers);
    return 0;
}
```

### 习题9.48
假定name和numbers的定义如325页所示，numbers.find(name)返回什么？

string::npos

### 习题9.49
如果一个字母延伸到中线之上，如d 或 f，则称其有上出头部分（ascender）。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（descender）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

```
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void _find(const string& s, string& result)
{
    string not_in("dfpg");
    if (s.find_first_of(not_in) == string::npos)
    {
        result = result.size() < s.size()?s:result;
    }
}

int main()
{
    string path = "test.txt";
    ifstream ifs(path);
    if(!ifs)
    {
        cout << "open file error!" << endl;
        return -1;
    }
    string curr="", result="";
    while (ifs >> curr)
    {
        _find(curr, result);
    }
    cout << result << endl;
    return 0;
}
```

### 习题9.50
编写程序处理一个vector<string>，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。

```
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<string> svec = {"1","2","3"};
    long result = 0;
    for (auto &x : svec)
    {
        result += stoi(x);
    }
    cout << result << endl;

    vector<string> sdvec = {"1.1","2.2","3.3"};
    double dresult = 0.0;
    for (auto &x : sdvec)
    {
        dresult += stod(x);
    }
    cout << dresult;
    return 0;
}
```

### 习题9.51
设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同的数据格式，如January 1,1900、1/1/1990、Jan 1 1900 等。

```
#include<iostream>
#include<string>

using namespace std;

class MyDate
{
private:
    unsigned year;
    unsigned month;
    unsigned day;
public:
    MyDate();
    MyDate(const string &date);
    void print();
private:
    void init_1(const string &date);
    void init_2(const string &date);
    void init_3(const string &date);
    void process_month(const string &s);
};

MyDate::MyDate(const string &date)
{
    if(date.find_first_of("/") != string::npos)
    {
        init_1(date);
    }
    else if (date.find_first_of(",") != string::npos )
    {
        init_2(date);
    }
    else
    {
        init_3(date);
    }
}

void MyDate::print()
{
    cout << "day: " << day << " " << "month: " << month << " " << "year: " << year << endl;
}

void MyDate::init_1(const string &date)
{
    auto first = date.find_first_of("/"), last = date.find_last_of("/");
    month = stoi(date.substr(0,first));
    day = stoi(date.substr(first+1, last-first));
    year = stoi(date.substr(last+1, 4));
}

void MyDate::init_2(const string &date)
{
    auto first = date.find_first_of(",");
    auto prex = date.substr(0,first);
    process_month(prex);
    day = stoi(prex.substr(prex.find_first_of("123456789")));
    year = stoi(date.substr(first+1, 4));
}

void MyDate::init_3(const string &date)
{
    auto first = date.find_first_of("123456789"), last = date.find_last_of(" ");
    auto prex = date.substr(0,first);
    process_month(prex);
    day = stoi(date.substr(first, last-first));
    year = stoi(date.substr(last+1, 4));
}

void MyDate::process_month(const string &s)
{
    if (s.find("Jan") < s.size())  month = 1;
	if (s.find("Feb") < s.size())  month = 2;
	if (s.find("Mar") < s.size())  month = 3;
	if (s.find("Apr") < s.size())  month = 4;
	if (s.find("May") < s.size())  month = 5;
	if (s.find("Jun") < s.size())  month = 6;
	if (s.find("Jul") < s.size())  month = 7;
	if (s.find("Aug") < s.size())  month = 8;
	if (s.find("Sep") < s.size())  month = 9;
	if (s.find("Oct") < s.size())  month = 10;
	if (s.find("Nov") < s.size())  month = 11;
	if (s.find("Dec") < s.size())  month = 12;
}


//January 1,1900、1/1/1990、Jan 1 1900
int main()
{
    MyDate mdate("1/1/1990"),mdate2("January 1,1900"),mdate3("Jan 1 1900");
    mdate.print();
    mdate2.print();
    mdate3.print();
    return 0;
}
```

### 习题9.52
使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。

```
#include<iostream>
#include<string>
#include<stack>

using namespace std;

string calc(string& l, string& r, const string& op)
{
    //support + -
    string s;
	if (op == "-")
    {
        s = to_string(stoi(l) - stoi(r));
    }
    if (op == "+")
    {
        s = to_string(stoi(l) + stoi(r));
    }
    
	return s;
}

int main()
{
    string s("(1+2*(7-4))");
    stack<string> stack;
    for(auto it = s.begin();it != s.end();)
    {
        if (*it == '(')
        {
            stack.push(string(1, *it));
            ++it;
            while(*it != ')')
            {
                stack.push(string(1, *it));
                ++it;
            }
        }
        else if(*it == ')')
        {
            string r = stack.top();
            stack.pop();
            string op = stack.top();
            stack.pop();
            string l = stack.top();
            stack.pop();

            stack.pop();
            stack.push(calc(l,r,op));
            ++it;
        }
        else
        {
            ++it;
        }
        
    }
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    
    return 0;
}
```

