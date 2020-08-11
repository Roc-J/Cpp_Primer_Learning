## 第六章的习题

### 习题6.1
实参和形参的区别的什么？
* 实参是形参的初始值。形参是函数定义的部分；调用函数时，用实参初始化函数的形参。

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
