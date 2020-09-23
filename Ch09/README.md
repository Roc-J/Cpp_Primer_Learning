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
