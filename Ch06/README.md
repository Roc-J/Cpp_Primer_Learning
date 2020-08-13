## 第六章的习题

### 习题6.1
实参和形参的区别的什么?  
* 实参是形参的初始值。
* 形参是函数定义的部分；调用函数时，用实参初始化函数的形参。

### 习题6.2
请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x; 
```

(a) 返回类型错误
```
string f() {
      string s;
      // ...
      return s;
}
```
(b)函数需要一个返回类型
```
void f2(int i) { /* ... */ }
```
(c) 函数形参不能同名
```
int calc(int v1, int v2) { /* ... */ }
```
(d) 缺失{}
```
double square (double x) {return x * x; } 
```

### 习题6.3
编写你自己的fact函数，上机检查是否正确。
```
#include<iostream>
using namespace std;

int fact(int val)
{
    int result = 1;
    while (val > 0)
    {
        result *= val--;
    }
    return result;
}


int main()
{
    int x = fact(5);
    cout << "5! = " << x << endl;
    return 0;
}
```

### 习题6.4
编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
```
#include<iostream>
using namespace std;

int fact(int val)
{
    int result = 1;
    while (val > 0)
    {
        result *= val--;
    }
    return result;
}

int main()
{
    int x;
    cout << "input a number: " << endl;
    while (cin >> x)
    {
        int ret = fact(x);
        cout << x << "! = " << ret << endl;
        cout << "input a number: " << endl;
    }
    return 0;
}
```

### 习题6.5
编写一个函数输出其实参的绝对值。
```
#include<iostream>
using namespace std;

int abs_x(int val)
{
    return val<0?-val:val;
}

int main()
{
    int x;
    cout << "input a number: " << endl;
    while (cin >> x)
    {
        int ret = abs_x(x);
        cout << x << " abs = " << ret << endl;
        cout << "input a number: " << endl;
    }
    return 0;
}
```

### 习题6.6
说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。   
* 0个或多个形参组成的列表 是函数定义的一部分。形参以逗号隔开，形参的列表位于一对圆括号之内  
* 形参和函数体内部定义的变量统称为局部变量。  
* 局部静态对象 是将局部变量定义成statis类型从而获得的对象，声明周期贯穿函数调用及之后的时间。局部静态对象在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响。  
```
#include<iostream>

using namespace std;

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i < 10; ++i)
    {
        cout << count_calls() << endl;
    }
    return 0;
}
```

### 习题6.7
编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。
```
size_t count_calls()
{
    static size_t ctr = 0;
    return ctr++;
}
```

### 习题6.8
编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。
```
#include<string>
using namespace std;

string f();
void f2(int i);
int calc(int v1, int v2);
double square(double x);
```

### 习题6.9
编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。
* fact.cpp
```
#include "Chapter6.h"

int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}
```
* factMain.cpp
```
#include<iostream>
#include "Chapter6.h"
//#include "fact.cpp"

using namespace std;

int main()
{
    cout << fact(5) << endl;
    return 0;
}
```
> 编译器编译的话，需要添加注释行，要不然就命令行编译。

### 习题6.10
编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
```
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

int main()
{
    int x = 5, y = 10;
    cout << "before: x is " << x <<" y is " << y << endl;
    swap(&x, &y);
    cout << "after: x is " << x <<" y is " << y << endl;
    return 0;
}
```

### 习题6.11
编写并验证你自己的reset函数，使其作用于引用类型的参数。
```
#include<iostream>

using namespace std;

void reset(int &i)
{
    i= 0;
}

int main()
{
    int x = 42;
    cout << "before reset x is : " << x << endl;
    reset(x);
    cout << "after reset x is : " << x << endl;
    return 0;
}
```

### 习题6.12
改写6.2.1节练习中的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
```
#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}

int main()
{
    int x = 5, y = 10;
    cout << "before: x is " << x <<" y is " << y << endl;
    swap(x, y);
    cout << "after: x is " << x <<" y is " << y << endl;
    return 0;
}
```

很显然是引用更易于使用，指针过于复杂的会难以理解。

### 习题6.13
假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。  
* void f(T) 形参是通过值传递，在函数T中生成副本操作，改变T并不影响实参的值。  
* void f(&T) 形参是通过引用传递，在函数T中对T的修改，会同步改变实参的值，相当于实参的别名使用。  

### 习题6.14
举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。
* 引用类型交换变量
```
void swap(int &a, int &b)
{
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}
```
* 不能是引用类型 求fact,要求不改变该值。
```
int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}
```

### 习题6.15
说明find_char 函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？   
* 因为string对象可能会非常长，避免直接拷贝，使用引用形参是比较明智的选择；又因为无需改变string对象的内容，所以把形参定义成对常量的引用。  
* occurs是要传到函数体外的变量，所以用引用，并且occurs的值是变的，所以是普通引用。  
* 因为我们只需要 c 的值，这个值不确定是否是变量还是字符字面值，所以不适用引用。  
* 如果s是普通引用，可能会改变原有字符串的内容。  
* 令occurs是常量引用的话，该变量就不能改变了。  

### 习题6.16
下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
```
bool is_empty(string& s) { return s.empty(); }
```
* 局限性是定义的形参是字符串引用，对于字符串常量和字符串字面值是不能作为实参传递的。  
* 优化
```
bool is_empty(const string& s) { return s.empty(); }
```

### 习题6.17
编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？
```
#include<iostream>
#include<string>

using namespace std;

bool isUpper(const string &s)
{
    for (auto &i : s)
    {
        if (isupper(i))
            return true;
    }
    return false;
}

void chg_lowwer(string &s)
{
    for (auto &i : s)
    {
        i = tolower(i);
    }
}

int main()
{
    string s1;
    while (cin >> s1)
    {
        bool ret = isUpper(s1);
        if (ret)
        {
            cout << s1 << " has upper alpha" << endl;
            chg_lowwer(s1);
            cout << s1 << endl;
        }
        else
        {
            cout << s1 << " has't upper alpha" <<endl;
        }   
    }
    return 0;
}
```

两个函数的形参不一样，第一个函数是对string的常量引用，第二个函数是对字符串的普通引用。

### 习题6.18
为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。  
(a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。    
(b) 名为 change_val 的函数，返回vector的迭代器，有两个参数：一个是int，另一个是vector的迭代器。  
```
bool compare(matrix &x1, matrix &x2);
vector<int>::iterator change_val(int, vector<int>::iterator);
```

### 习题6.19
假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```
(a) 不合法，传参个数不对
(b) 合法
(c) 合法
(d) 合法

### 习题6.20
引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

把函数不会改变的形参定义成普通的引用是一种比较常见的错误，这么做带给函数的调用者一种误导，即函数可以修改它的实参的值。此外，使用引用而非常量引用也会极大地限制函数所能接受的实参类型（不能把const对象、字面值或者需要类型转换的对象传递给普通的引用形参。

### 习题6.21
编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？
```
#include<iostream>

using namespace std;

int compare(const int x, const int *p)
{
    return x>(*p)?x:(*p);
}

int main()
{
    int x,y;
    int *p=&y;
    while (cin >> x >> y)
    {
        int ret = compare(x, &y);
        cout << x << " and " << (*p) << " max is " << ret << endl;
    }
    return 0;
}
```

const int *类型

### 习题6.22
编写一个函数，令其交换两个int指针。
```
#include<iostream>

using namespace std;

void swap(int * &p, int * &q)
{
    auto tmp = p;
    p = q;
    q = tmp; 
}

int main()
{
    int x,y;
    int *p=&x, *q = &y;
    while (cin >> x >> y)
    {
        cout << "p is " << (*p) << " q is " << (*q) << endl;
        swap(p, q);
        cout << "p is " << (*p) << " q is " << (*q) << endl;
    }
    return 0;
}
```

### 习题6.23
参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:
```
int i = 0, j[2] = { 0, 1 };
```
```
#include<iostream>

using namespace std;
//使用标记指定数组长度
void print(const char *cp)
{
    if (cp)
    {
        while (*cp)
        {
            cout << *cp++;
        }
    }
}
//使用标准库规范
void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}
//显示传递一个表示数组大小的形参
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

//数组引用形参
void print(int (&arr)[2])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}

int main()
{
    int i = 0, j[2] = { 0, 1 };
    //print(j);
    //print(begin(j), end(j));
    //print(j, end(j) - begin(j));
    print(j);
    return 0;
}
```

### 习题6.24
描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
```
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```
使用数组传递参数 通常会将其转换成指针，实际上传递的是指向数组首元素的指针。
修改为
```
void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

### 习题6.25
编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。

```
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char ** argv)
{
    string s1 = argv[1], s2 = argv[2];
    cout << s1+s2 << endl;
    return 0;
}
```

### 习题6.26
编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。
```
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
    for (size_t i = 1; i < argc; i++)
    {
        cout << static_cast<string>(argv[i]) << endl;
    }
    return 0;
}
```

### 习题6.27
编写一个函数，它的参数是initializer_list类型的对象，函数的功能是计算列表中所有元素的和。
```
#include<iostream>

using namespace std;

int calc_params(initializer_list<int> const &li)
{
    int ret = 0;
    for (auto x : li)
    {
        ret += x;
    }
    return ret;
}

int main()
{
    initializer_list<int>  T = {1,2,3,4,5,6,7,8,9};
    int ret = calc_params(T);
    cout << ret << endl;
    return 0;
}
```

### 习题6.28
在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？  
elem 是const string &

### 习题6.29
在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？  
使用常量引用类型。initializer_list对象中元素都是常量，无需修改元素的值。

### 习题6.30
编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。
```
#include <iostream>
#include <string>

using namespace std;

bool str_subrange(const string& str1, const string& str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;
	}
}

int main()
{
	return 0;
}
```
```
cpp_6-30.cpp: In function 'bool str_subrange(const string&, const string&)':
cpp_6-30.cpp:15:4: error: return-statement with no value, in function returning 'bool' [-fpermissive]
    return;
    ^~~~~~
```

### 习题6.31
什么情况下返回的引用无效？什么情况下返回常量的引用无效？  
* 局部对象的引用或者指针无效。函数完成后，它所占用的存储空间也随之被释放掉，因此，函数终止意味着局部变量的引用将指向不再有效的内存区域。  
* 如果返回类型是常量引用，不能给调用的结果赋值，引用是无效的。

### 习题6.32
下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
```
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```
合法，get函数获取数组元素的引用 并赋值。

### 习题6.33
编写一个递归函数，输出vector对象的内容。  
* 想半天，用收尾指针即可。
```
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>::iterator beg, vector<int>::iterator end)
{
    if (beg == end)
    {
        cout << "done." << endl;
        return;
    }
    cout << *beg++ << endl;
    print(beg, end);
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    print(vec.begin(), vec.end());
    return 0;
}
```

### 习题6.34
如果factorial 函数的停止条件如下所示，将发生什么？
```
if (val != 0)
```
val初始为正数，结果不变，val=0时=1;如果为负数，则递归无法停止。

### 习题6.35
在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？  
val-- 传递的是val值，函数将不变。

### 习题6.36
编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名。   
string (&func())[10];

### 习题6.37
为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？
```
typedef string str_arr[10];
str_arr& func();

auto func() -> string(&)[10];

string str_arr[10];
decltype(str_arr)& func();
```
尾置返回类型最好

### 习题6.38
修改arrPtr函数，使其返回数组的引用。
```
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) & arrPtr(int i)
{
    return (i%2)? odd:even;
}
```

### 习题6.39
说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
```
(a) int calc(int, int);
	int calc(const int, const int);
(b) int get();
	double get();
(c) int *reset(int *);
	double *reset(double *);
```
(a) 非法，顶层const不影响传入函数的对象。一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来。
(b) 非法，对于重载的函数来说，它们应该在形参数量或者形参类型上有所不同，不允许两个函数除了返回类型外其他所有的要素都相同。
(c) 合法。

### 习题6.40
下面的哪个声明是错误的？为什么？
```
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);	
```
(a) 合法
(b) 非法，函数的默认形参右侧的所有的形参必须都有默认值。

### 习题6.41
下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
```
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14,'*');
```
(a) 非法，第一个形参不是默认参数，需要传递一个参数
(b) 合法
(c) 合法，但是和初衷不符，因为字符'*'被传递给第二个参数，初衷应该是第三个参数。

### 习题6.42
给make_plural函数的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。
```
#include<iostream>
#include<string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending="s")
{
    return (ctr>1)?word+ending:word;
}

int main()
{
    cout << make_plural(1,"success","es") << endl;
    cout << make_plural(2,"success","es") << endl;
    cout << make_plural(1,"failure") << endl;
    cout << make_plural(2,"failure") << endl;
    return 0;
}
```

### 习题6.43
你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
```
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```
全部放进头文件中，(a)是内联函数，(b)是函数声明

### 习题6.44
将6.2.2节的isShorter函数改写成内联函数。
```
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

### 习题6.45
回顾在前面的练习中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。

不是，一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数。

### 习题6.46
能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constexpr函数；如果不能，说明原因。
* 不能 constexpr函数是指能用于常量表达式的函数。函数的返回类型及所有形参的类型都得是字面值类型。

### 习题6.47
改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
```
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>::iterator beg, vector<int>::iterator end)
{
    if (beg == end)
    {
        cout << "done." << endl;
        return;
    }
    cout << *beg++ << endl;
    print(beg, end);
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    print(vec.begin(), vec.end());
    return 0;
}
```

### 习题6.48
说明下面这个循环的含义，它对assert的使用合理吗？
```
string s;
while (cin >> s && s != sought) { } //空函数体
assert(cin);
```
不合理，程序while退出，assert无效，应该在assert(s == sought);

### 习题6.49
什么是候选函数？什么是可行函数？
* 候选函数具备两个特征：一是与被调的函数同名，二是其声明在调用点可见。
* 可行函数也有两个特征：一是其形参数量与本次调用的提供的实参数量相等，二是每个实参的类型与对应的形参类型相同，或者能转换成形参的类型。

### 习题6.50
已知有第217页对函数 f 的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
```
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```
(a) void f(int, int); 和 void f(double, double = 3.14); 是可行函数。该调用具有二义性而不合法
(b) void f(int) 是可行函数。调用合法
(c) void f(int, int); void double(double, double=3.14) 是可行函数。void f(int, int)是最佳匹配
(d) void f(int, int); void double(double, double=3.14) 是可行函数。void double(double, double=3.14) 是最佳匹配

### 习题6.51
编写函数f的4版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你的回答错了，反复研究本节内容直到你弄清自己错在何处。
```
#include<iostream>

using namespace std;

void f()
{
    cout << "f() " << endl;
}

void f(int x)
{
    cout << "f(int) " << x << endl;
}

void f(int x, int y)
{
    cout << "f(int,int) " << x << " " << y << endl;
}

void f(double x, double y=3.14)
{
    cout << "f(double,double) " << x <<" " << y << endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
```

```
f(int) 42
f(int,int) 42 0
f(double,double) 2.56 3.14
```

### 习题6.52
已知有如下声明：
```
void manip(int ,int);
double dobj;
```
请指出下列调用中每个类型转换的等级。
```
(a) manip('a', 'z');
(b) manip(55.4, dobj);
```
(a) 类型提升实现的匹配
(b) 算术类型转换实现的匹配

### 习题6.53
说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。
```
(a) int calc(int&, int&); 
	int calc(const int&, const int&); 
(b) int calc(char*, char*);
	int calc(const char*, const char*);
(c) int calc(char*, char*);
	int calc(char* const, char* const);
```
(a) 引用类型的形参是对int的常量引用
(b) 引用类型的形参是对char指针的常量引用
(c) 不合法，顶层const不影响传入函数的对象。

### 习题6.54
编写函数的声明，令其接受两个int形参并返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。
```
int f(int,int);
vector<decltype(f) *> vec;
auto vec(vector<int>) -> int(*)(int, int);
```

### 习题6.55
编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。
```
#include<iostream>
#include<vector>
using namespace std;

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

int mul(int x,int y)
{
    return x*y;
}

int div(int x,int y)
{
    if(y)
        return x/y;
}

int main()
{
    vector<decltype(add) *> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(div);
    return 0;
}
```

### 习题6.56
调用上述vector对象中的每个元素并输出结果。
```
#include<iostream>
#include<vector>
using namespace std;

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

int mul(int x,int y)
{
    return x*y;
}

int divide(int x,int y)
{
    if(y)
        return x/y;
    else
    {
        return 0;
    }
}

int main()
{
    vector<decltype(add)*> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(divide);

    for (auto x : vec)
    {
        cout << x(4,7) << endl;
    }
    
    return 0;
}
```