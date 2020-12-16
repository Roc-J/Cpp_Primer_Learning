### 习题2-1

类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

C++语言规定一个int至少和一个short一样大，一个long至少和一个int一样大，一个long long至少和一个long一样大。其中，数据类型long long 是在C++11中新定义的。  
C++规定short和int至少是16位，long至少是32位，long long至少是64位。  

目前的操作系统已发展到64位操作系统，但因程序编译工艺不同，两者表现出不同的差异。  
* 32位编译系统中，int占4字节，与long相同。  
* 64位编译系统中，int占4字节，long是64字节  

参考链接
https://blog.csdn.net/u012223913/article/details/51181761

带符号类型能够表示正数、负数和0. 而无符号类型仅能表示大于等于0的值。

浮点型可表示单精度、双精度和扩展精度值。  
C++标准指定了一个浮点数有效位数的最小值，然而大多数编译器都实现了更高的精度。通常，float以1个字（32比特）来表示，double以2个字（64比特）来表示。  
一般来说，类型float和double分别有7和16个有效位。

### 习题2-2

计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由

利率：float  单精度足够满足使用，不存在丢失数据情况  
本金/付款：double 双精度更精确  

使用double 或者 float。因为这些是浮点数类型，才能满足金额的精确。  

### 习题2-3

读程序写结果。
```
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```
输出结果  
```
32
(-32 unsigned 类型变为) 4294967296-32=4294967264
32
-32
0
0
```

### 习题2-4

编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。
```
#include<iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    return 0;
}
```

### 习题2-5

指出下述字面值的数据类型并说明每一组内几种字面值的区别:  
```
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值
(b): 十进制整型，十进制无符号整型，十进制长整型，十进制无符号长整型，八进制整型，十六进制整型
(C): double型，float，long double
(d): 十进制整型，十进制无符号整型，double, double
```

### 习题2-6

下面两组定义是否有区别，如果有，请叙述之:  
```
int month = 9, day = 7;
int month = 09, day = 07;
```
第一行定义的是十进制整型，编译可通过。
第二行定义的是八进制整型，但是09是未定义的八进制数，编译不通过

### 习题2-7

下述字面值表示何种含义？它们各自的数据类型是什么？  
```
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L

(a) Who goes with Fergus?(换行)"  数据类型 string
(b) 3.14e1L  数据类型 long double
(c) 1024f  数据类型 定义错误，f前必须是浮点数，不能是整型
(d) 3.14L  数据类型 long double
```

### 习题2-8

请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。
```
#include<iostream>

int main()
{
    std::cout << "2\115\012";

    std::cout << "2\t\115\012";
    return 0;
}
```

### 习题2-9

解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
```
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```
(a) std::cin >> int input_value;

未定义不能使用，编译不通过

```
int input_value;
std::cin >> input_value;
```

(b) int i = { 3.14 };

使用列表初始化内置类型的变量，double -- > int 存在丢失信息的风险，编译不通过。  

使用double类型

```
double i = {3.14};
```

(c) double salary = wage = 9999.99;  

wage是未定义的变量，编译不通过
```
double wage;
double salary = wage = 9999.99;
```

(d) int i = 3.14;  
编译通过，但是会丢失信息，实际上i=3


### 习题2-10

下列变量的初值分别是什么？
```
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```
global_str 全局变量 字符串有默认值，为空字符串  
global_int 全局变量，默认值是0  
local_int 局部变量，没有初始化，是未定义的值  
local_str 局部变量，字符串有默认值，为空字符串  

但是本地编译执行是可以通过的
```
lobal_str:
global_int: 0
local_int: 0
local_str:
```

### 习题2-11

指出下面的语句是声明还是定义:  
```
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;

(a) 定义
(b) 定义
(c) 声明
```

### 习题2-12

请指出下面的名字中哪些是非法的？
```
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;

(a),(c),(d) 是错误非法定义。
```

### 习题2-13

下面程序中 j 的值是多少？
```
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```
j=100 局部变量赋值，覆盖了全局变量

### 习题2-14

下面的程序合法吗？如果合法，它将输出什么？
```
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```

合法  100 45

### 习题2-15

下面的哪个定义是不合法的？为什么？
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;

(b)和(d) 定义不合法，(b)引用必须绑定在对象上，不能是常量字面值。(d)引用必须初始化。

### 习题2-16

考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？
```
int i = 0, &r1 = i; double d = 0, &r2 = d;

(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;

(a) 合法，给d赋值
(b) 合法，int->double
(c) 合法，double->int
(d) 合法，double ->int
```

### 习题2-17

执行下面的代码段将输出什么结果？
```
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
10 10

### 习题2-18

编写代码分别改变指针的值以及指针所指对象的值。
```
#include<iostream>

int main()
{
    int i=0, j=1;
    int *p=&i, *q=p;

    p = &j;
    *q = j;
    return 0;
}
```

### 习题2-19

说明指针和引用的主要区别

* 指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象； 指针无须在定义时赋初值。  
* 引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字。引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。  

### 习题2-20

请叙述下面这段代码的作用。
```
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```
指针p1指向变量i, 然后将i的值重新赋值为42*42

### 习题2-21

请解释下述定义。在这些定义中有非法的吗？如果有，为什么？
```
int i = 0;

(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;

(a) 非法，double型指针不能指向int
(b) 非法，不能将int变量指向int指针。
(c) 合法，p指针指向i
```

### 习题2-22

假设 p 是一个 int 型指针，请说明下述代码的含义。
```
if (p) // ...
if (*p) // ...
```
if(p) 判断p是不是空指针。  
if(*p)判断p指向的对象的值是不是0  

### 习题2-23

给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，因为不能判断这个指针是不是合法，只有指针是合法的才能判断它所指向对象是不是合法。

### 习题2-24

在下面这段代码中为什么 p 合法而 lp 非法？
```
int i = 42;
void *p = &i;
long *lp = &i;
```
因为void指针可以指向任何类型的对象；而其他指针类型必须和所指向的对象类型严格匹配。

### 习题2-25

说明下列变量的类型和值。
```
(a) int* ip, i, &r = i;
(b) int i, *ip = 0;
(c) int* ip, ip2;


(a) ip是一个指向int类型的指针；i是一个int, r是i 的引用。
(b) i是一个int, ip是一个指向int类型的指针，并且覆盖为0，是一个空指针
(c) ip是一个指向int的指针，ip2是一个int
```

### 习题2-26

下面哪些语句是合法的？如果不合法，请说明为什么？
```
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;

(a) 不合法, const对象必须初始化
(b) 合法
(c) 合法
(d) 不合法，sz是const对象，不能修改
```

### 习题2-27

下面的哪些初始化是合法的？请说明原因。
```
(a) int i = -1, &r = 0; 
(b) int *const p2 = &i2;
(c) const int i = -1, &r = 0;
(d) const int *const p3 = &i2;
(e) const int *p1 = &i2;   
(f) const int &const r2;
(g) const int i2 = i, &r = i;

(a) 非法, r 必须引用一个对象
(b) 合法
(c) 合法
(d) 合法
(e) 合法
(f) 非法，r2是声明常量引用
(g) 合法
```

### 习题2-28

说明下面的这些定义是什么意思，挑出其中不合法的。
```
(a) int i, *const cp;       
(b) int *p1, *const p2;     
(c) const int ic, &r = ic;  
(d) const int *const p3;    
(e) const int *p;           

(a) 不合法, const 指针必须初始化
(b) 不合法, const 指针必须初始化
(c) 不合法, const int 必须初始化
(d) 不合法, const 指针必须初始化
(e) 合法. 指向 const int的一个指针
```

### 习题2-29

假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
```
(a) i = ic;     
(b) p1 = p3;    
(c) p1 = &ic;   
(d) p3 = &ic;   
(e) p2 = p1;    
(f) ic = *p3;   

(a) 合法, 常量赋值给int
(b) 不合法, p3 是const指针不能赋值给普通指针
(c) 不合法, 普通指针不能指向常量
(d) 合法, p3 是常量指针且指向常量
(e) 合法, 可以将普通指针赋值给常量指针
(f) 合法, 对 p3 取值后是一个 int 然后赋值给 ic

```

### 习题2-30

对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
```
const int v2 = 0;   //顶层const
int v1 = v2;        //底层const
int *p1 = &v1, &r1 = v1;    //p1是底层const, r1引用底层const
const int *p2 = &v2, *const p3 = &i, &r2 = v2;   //p2是底层const;p3既是顶层const又是底层const, r2是顶层const
```

### 习题2-31

假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
```
r1 = v2; //合法
p1 = p2; //不合法
p2 = p1; //合法
p1 = p3; //不合法
p2 = p3; //合法
```
> 有点没太明白，好像是底层const拷贝必须要求是底层const

### 习题2-32

下面的代码是否合法？如果非法，请设法将其修改正确。
```
int null = 0, *p = null;
```
不能把int变量直接赋值给指针，即使int变量的值为0也不可以。

### 习题2-33

利用本节定义的变量，判断下列语句的运行结果
```
int i = 0, &r=i;
auto a = r; //a是一个整数(r是i的别名，而i是一个整数)
auto 会忽略掉顶层的const，同时底层const则会保留下来
const int ci = i, &cr = ci;
auto b = ci;  //b是一个整数（ci的顶层const特征被忽略掉了）
auto c = cr;  //c是一个整数（cr是ci的别名，ci本身是一个顶层const）
auto d = &i;  //d是一个整型指针（整数的地址就是指向整数的指针）
auto e = &ci; //e是一个指向整数常量的指针（对常量对象取地址是一种底层const)
const auto f = ci;  //ci的推演类型是int,f是const int
还可以将引用的类型设为auto,此时原来的初始化规则仍然适用
auto &g = ci;

a=42; // a 是 int
b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
c=42; // c 也是一个int
d=42; // d 是一个 int *,所以语句非法
e=42; // e 是一个 const int *, 所以语句非法
g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值
```

### 习题2-34

基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

```
#include<iostream>

int main()
{
    int i = 0, &r=i;
    auto a = r; //a是一个整数(r是i的别名，而i是一个整数)
    const int ci = i, &cr = ci;
    auto b = ci;  //b是一个整数（ci的顶层const特征被忽略掉了）
    auto c = cr;  //c是一个整数（cr是ci的别名，ci本身是一个顶层const）
    auto d = &i;  //d是一个整型指针（整数的地址就是指向整数的指针）
    auto e = &ci; //e是一个指向整数常量的指针（对常量对象取地址是一种底层const)
    const auto f = ci;  //ci的推演类型是int,f是const int
    auto &g = ci;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    
    std::cout << "----- after ------" << std::endl;
    a = 42;
    b = 42;
    c = 42;
    //d = 42;
    //e = 42;
    //g = 42;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    return 0;
}
```
基本上在IDE编写，d,e,g的赋值编译就不会通过。

### 习题2-35

判断下列定义推断出的类型是什么，然后编写程序进行验证。
```
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i; 
const auto j2 = i, &k2 = i;

j是int
k是const int 引用
p是const int*
j2是const int
k2是const int 引用
```

### 习题2-36

关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
```
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;

c 是int 4  
d 是int& 引用 4
```

### 习题2-37

赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。
```
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;

c int 3
d int& 绑定a
```

### 习题2-38

说明由decltype 指定类型和由auto指定类型有何区别。请举一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。  
* decltype处理顶层const和引用的方式与auto不同。如果decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）  
* decltype和auto的另一处重要区别是，decltype的结果类型与表达式形式密切相关  
```
#include<iostream>

int main()
{
    int i=0, &r=i;

    //same
    auto a = i;
    decltype(i) b = i;

    //different
    auto c = r;
    decltype(r) d = r;
    return 0;
}
```

### 习题2-39

编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关的信息，以后可能会有用。
```
struct Foo { /* 此处为空  */ } // 注意：没有分号
int main()
{
    return 0;
}
```

波浪线提示输入分号

### 习题2-40

根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。
```
struct Sales_data {
    std::string bookNo;
    std::string bookName;
    std::string submitTime;
    double revenus = 0.0;
    unsigned units_sold =0;
    double price;
};
```

### 习题2-41

使用你自己的Sale_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把Sales_data类的定义和main函数放在一个文件里。

用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
```
#include<iostream>

struct Sales_data
{
    /* data */
    std::string bookNo;
    double revenus = 0.0;
    unsigned units_sold =0;
};

int main()
{
    Sales_data item;
    double price;
    std::cout << "input Sales_item:" << std::endl;
    std::cin >> item.bookNo >> item.units_sold >> price;
    item.revenus = item.units_sold*price;
    std::cout << item.bookNo << " " <<  item.units_sold << " " << price << " " << item.revenus << std::endl;
    return 0;
}
```

编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。
```
#include<iostream>

struct Sales_data
{
    /* data */
    std::string bookNo;
    double revenus = 0.0;
    unsigned units_sold =0;
};

void demo1()
{
    Sales_data item;
    double price;
    std::cout << "input Sales_item:" << std::endl;
    std::cin >> item.bookNo >> item.units_sold >> price;
    item.revenus = item.units_sold*price;
    std::cout << item.bookNo << " " <<  item.units_sold << " " << price << " " << item.revenus << std::endl;
}

void demo2()
{
    //编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。
    Sales_data item1, item2;
    double price1, price2;
    std::cout << "input first Sales_item:" << std::endl;
    std::cin >> item1.bookNo >> item1.units_sold >> price1;

    std::cout << "input second Sales_item:" << std::endl;
    std::cin >> item2.bookNo >> item2.units_sold >> price2;

    if(item1.bookNo == item2.bookNo)
    {
        unsigned total_c = item1.units_sold + item2.units_sold;
        double total_p = item1.units_sold * price1 + item2.units_sold * price2;
        std::cout << "The same bookNo is " << item1.bookNo << " sales total number is : " << total_c << " total price  is " << total_p;
    }
    else
    {
        std::cout << "input items bookNo is different." << std::endl;
    }
    
}

int main()
{
    //demo1();
    demo2();
    return 0;
}
```

### 习题2-42

根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的练习。

Sales_data.h
```
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>

struct Sales_data
{
    /* data */
    std::string bookNo;
    unsigned units_sold = 0;
    double revenus = 0.0;
};


#endif
```

```
#include<iostream>
#include "Sales_data.h"

void demo1()
{
    Sales_data item;
    double price;
    std::cout << "input Sales_item:" << std::endl;
    std::cin >> item.bookNo >> item.units_sold >> price;
    item.revenus = item.units_sold*price;
    std::cout << item.bookNo << " " <<  item.units_sold << " " << price << " " << item.revenus << std::endl;
}

void demo2()
{
    //编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。
    Sales_data item1, item2;
    double price1, price2;
    std::cout << "input first Sales_item:" << std::endl;
    std::cin >> item1.bookNo >> item1.units_sold >> price1;

    std::cout << "input second Sales_item:" << std::endl;
    std::cin >> item2.bookNo >> item2.units_sold >> price2;

    if(item1.bookNo == item2.bookNo)
    {
        unsigned total_c = item1.units_sold + item2.units_sold;
        double total_p = item1.units_sold * price1 + item2.units_sold * price2;
        std::cout << "The same bookNo is " << item1.bookNo << " sales total number is : " << total_c << " total price  is " << total_p;
    }
    else
    {
        std::cout << "input items bookNo is different." << std::endl;
    }
    
}

int main()
{
    //demo1();
    demo2();
    return 0;
}
```