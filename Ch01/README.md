## 第一章 习题

### 习题1.1

 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

```
#include <iostream>

int main()
{
    return 0;
}
```

### 习题1-2

改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识  
```
int main()
{
    return -1;
}
```

### 习题1-3

编写程序，在标准输出上打印 Hello, World
```
#include<iostream>
int main()
{
    std::cout << "Hello, World."  << std::endl;
    return 0;
}
```
### 习题1-4

我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。
```
#include<iostream>

int main()
{
    std::cout << "Input two Numbers: " << std::endl;
    int x=0, y=0;
    std::cin >>  x >> y;
    std::cout << "The product of " << x << " and " << y 
        << " is " << x*y << std::endl;
    return 0;
}
```
### 习题1-5

我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。
```
#include<iostream>

int main()
{
    std::cout << "Input two Numbers: " << std::endl;
    int x=0, y=0;
    std::cin >>  x >> y;
    std::cout << "The product of " ;
    std::cout << x;
    std::cout << " and " ;
    std::cout << y ;
    std::cout << " is " ;
    std::cout << x*y << std::endl;
    return 0;
}
```

### 习题1-6

解释下面程序片段是否合法
```
std::cout << "The sum of " << v1 ;
           << " and " << v2;
           << " is "  << v1 + v2 << std::endl;
```
如果程序是合法的，它的输出是什么？如果程序不合法，原因何在？应该如何修正？  

不合法  
1）缺少std::cout 在第二行 and 第三行前添加  
2）多余;将第一行和第二行的;去掉即可。  

```
std::cout << "The sum of " << v1
           << " and " << v2
           << " is "  << v1 + v2 << std::endl;
```
或者采用
```
std::cout << "The sum of " << v1 ;
std::cout << " and " << v2;
std::cout << " is "  << v1 + v2 << std::endl;
```

###  习题1-7

编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息

就以文中的例子说明
```
/*
*   注释在这里嵌套
*	/* 这里的嵌套是错的 */
*
*/

int main()
{
	return 0;
}
```

编译器输出错误信息是
```
g:\VScode\C++Project\Ch01>cd "g:\VScode\C++Project\Ch01\" && g++ cpp_1-7.cpp -o cpp_1-7 && "g:\VScode\C++Project\Ch01\"cpp_1-7
cpp_1-7.cpp:7:2: error: expected unqualified-id before '/' token
 */
  ^
```

### 习题1-8

指出下列哪些输出语句是合法的(如果有的话)：
```
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案(编写一个小程序，每次将上述一条语句作为其主体)，改正每个编译错误。

第三行编译出错，改正方法是在结尾处增加一个引号
```
std::cout << /* "*/" */";
```
输出结果是
```
 */
```

### 习题1-9

编写程序，使用while循环将50到100的整数相加。
```
#include<iostream>
int main()
{
    int sum=0, val=50;
    while(val <=100)
    {
        sum += val;
        ++val;
    }
    std::cout << "the sum of 50~100 is " << sum << std::endl;
    return 0;
}
```

### 习题1-10

除了++运算符将运算对象的值增加1之外，还有一个递减运算符（--）实现将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
```
#include<iostream>
int main()
{
    int val = 10;
    while(val >= 0)
    {
        std::cout << val << std::endl;
        --val;
    }
    return 0;
}
```

### 习题1-11

编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数
```
#include<iostream>

int main()
{
    std::cout << "Input two numbers: " << std::endl;
    int x, y, temp;
    std::cin >> x >> y;
    if(x > y)
    {
        temp = x;
        x = y;
        y = temp;

    }
    while(x<=y)
    {
        std::cout << x << std::endl;
        ++x;
    }
    return 0;
}
```

### 习题1-12

下面的for循环完成了什么功能？sum的终值是多少？
```
int sum = 0;
for (int i = -100; i <= 100; ++i)
	sum += i;
```
从-100到100进行加和，sum的最终值是0.

### 习题1-13

使用for循环重做1.4.1节中的所有练习（第11页）  
习题1-9
```
#include<iostream>

int main()
{
    int sum=0;
    for(int val=50; val<=100; val++)
    {
        sum += val;
    }
    std::cout << "the sum of 50-100 is " << sum << std::endl;
    return 0;
}
```
习题1-10
```
#include<iostream>

int main()
{
    for(int val=10;val>=0;--val)
    {
        std::cout << val << std::endl;
    }
    return 0;
}
```
习题1-11
```
#include<iostream>

int main()
{
    int num1, num2, tmp;
    std::cout << "please input two numbers: " << std::endl;
    std::cin >> num1 >> num2;

    if(num1>num2)
    {
        tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    for(num1; num1<=num2; num1++)
    {
        std::cout << num1 << std::endl;
    }

    return 0;
}
```

### 习题1-14

对比for循环和while循环，两种形式的优缺点各是什么？  

while循环常用于那种不知道循环次数是多少的情况，只有终止循环条件。或者说,在while循环中，循环控制变量的初始化一般放在while语句之前，循环控制变量的修改一般放在循环体中，形式上不如for语句简洁，但它比较适用于**循环次数不易预知的情况**（用某一条件控制循环）

for循环多用于循环次数比较明确的情况  
for循环的特征是比较直观，for循环的第一句包含变量的初始化 结束循环的条件以及每次更新的值，循环体内部才执行真正要做的事情。在for语句中，循环控制变量的初始化和修改都放在语句头部分，形式较简洁，且特别适用于循环次数已知的情况。

### 习题1-15

编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息

常见的错误有

* 语法错误
* 类型错误
* 声明错误

> 具体可以查看primer C++内容，书描述的很详细

### 习题1-16

编写程序，从cin读取一组数，输出其和
```
#include<iostream>

int main()
{
    int sum=0, val;
    std::cout << "input your numbers" << std::endl;
    while(std::cin>> val)
    {
        sum += val;
    }
    std::cout << "your numbers sum is : " << sum << std::endl;
    return 0;
}
```

### 习题1-17

如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？
```
#include<iostream> 

int main()
{
    int currval=0, val=0;
    int cnt = 0;
    std::cout << "input your numbers: " << std::endl;
    if(std::cin >> currval) 
        cnt = 1;
        while(std::cin >> val)
        {
            if (currval == val)
            {
                cnt +=1;
            }
            else
            {
                std::cout << "input value:" << currval << " times: " << cnt << std::endl;
                currval = val;
                cnt = 1;
            }
            
        }
        std::cout << "input value:" << currval << " times: " << cnt << std::endl;
    return 0;
}
```
input your numbers:  
1 2 3

input value:1 times: 1  
input value:2 times: 1  
input value:3 times: 1  

1 2 2 2  
input value:1 times: 1  
input value:2 times: 3  


### 习题1-18

编译并运行本节的程序，给它输入全都相等的值。再次运行程序，输入没有重复的值

### 习题1-19

修改你为1.4.1节练习1.11（第11页）所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况
```
#include<iostream>

int main()
{
    int num1, num2, tmp;
    std::cout << "please input two numbers: " << std::endl;
    std::cin >> num1 >> num2;

    if(num1>num2)
    {
        tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    for(num1; num1<=num2; num1++)
    {
        std::cout << num1 << std::endl;
    }

    return 0;
}
```

### 习题1-20

在网站http://www.informit.com/title/032174113 上，第1章的代码目录包含了头文件 Sales_item.h。将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。  
> 这个网址目前的Sales_item.h 获取不到，基本就是练习一下将类作为一个数据类型，进行输入输出即可  

伪代码，后续章节会补充
```
#include<iostream>
#include "Sales_item.h"

using namespace std;

int main()
{
    //for
    for(Sales_item item; cin >> item;cout << item);

    //while
    Sales_item item;
    while(cin >> item)
    {
        cout << item;
    }
    return 0;
}
```

### 习题1-21

编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。  

伪代码
```
#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
    }
    return 0;
}
```

### 习题1-22

编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。  
```
#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum, item;
    if (std::cin >> sum)
    {
        while(std::cin >> item)
        {
            if (sum.isbn() == item.isbn())
            {
                sum += item;
            }
            else
            {
                std::cout << "Total sum is :" << sum << std::endl;
                sum = item;
            }   
        }
        std::cout << "Total sum is :" << sum << std::endl;
    }
    return 0;
}
```

### 习题1-23

编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。
和之前的统计相同的数异曲同工。
```
#include<iostream>
#include "Sales_item.h"

int main()
{
    Sales_item curr, item;
    if (std::cin >> curr)
    {
        int cnt = 1;
        while(std::cin >> item)
        {
            if (curr.isbn() == item.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout << "same is :" << cnt << std::endl;
                curr = item;
                cnt = 1;
            }   
        }
        std::cout << "same is :" << cnt << std::endl;
    }
    return 0;
}
```
