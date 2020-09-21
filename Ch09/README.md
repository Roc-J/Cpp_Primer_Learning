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