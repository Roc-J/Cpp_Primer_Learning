[TOC]

### 习题4-1
表达式 5 + 10 * 20 / 2 的求值结果是多少？

105

### 习题4-2
根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。
(a) *vec.begin()
(b) *vec.begin() + 1

(a) *(vec.begin())
(b) (*(vec.begin())) + 1
成员选择. 优先级 > 解引用 > 加法

### 习题4-3
C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。

可以接受。
优先级规定了运算对象的组合方式，但是没有说明运算对象按照什么顺序求值。
>只要求值顺序对最终结果不造成影响，都可以接受，因为在同一表达式中，同时出现了许多二元运算符，编译器可以选择一个一个去求解，也可以分开单独来运算，但只要最后的结果正确就可以。
引用：https://blog.csdn.net/fengzhanghao23/article/details/48441089

### 习题4-4
在下面的表达式中添加括号，说明其求值过程及最终结果。编写程序编译该（不加括号的）表达式并输出结果验证之前的推断。
```
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2

(((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)
16+75=91
```
### 习题4-5
写出下列表达式的求值结果。
-30 * 3 + 21 / 5  
-30 + 3 * 21 / 5  
30 / 3 * 21 % 5   
-30 / 3 * 21 % 4  

// -90+4 = -86
// -30+63/5 = -30+12 = -18
// 10*21%5 = 210%5 = 0
// -10*21%4 = -210%4 = -2

### 习题4-6
写出一条表达式用于确定一个整数是奇数还是偶数。
```
int i;
if (i%2 == 0)
{
    cout << "偶数" ;
}
```

### 习题4-7
溢出是何含义？写出三条将导致溢出的表达式。

溢出是当计算的结果超出该类型所能表示的范围时就会产生溢出。
```
//1 超出计算范围
short short_value = 32767;
short_value += 1;
cout << "short_value" << short_value << endl;
//2  除数为0，发生溢出
10/0  
//3  有符号整数不能为负数，溢出
unsigned value = 0;
value --;

```

### 习题4-8
说明在逻辑与、逻辑或及相等性运算符中运算对象的求值顺序。
逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，当且仅当左侧运算对象无法确定表达式的结果时才会计算右侧运算对象的值。这种策略是短路求值。
* 对于逻辑与运算符来说，当且仅当左侧运算对象为真时才对右侧运算对象求值。
* 对于逻辑或运算符来说，当且仅当左侧运算对象为假时才对右侧运算符对象求值。

相等性运算符未定义求值顺序。

### 习题4-9
解释在下面的if语句中条件部分的判断过程。
```
const char *cp = "Hello World";
if (cp && *cp)
```
先判断cp指针是否为空，cp不是空指针，所以为真，然后判断*cp ，指针cp所指的第一个元素是否为空，实际上是H，不为空，所以为真，整个if语句判断为真。

### 习题4-10
为while 循环写一个条件，使其从标准输入中读取整数，遇到 42 时停止。
```
#include<iostream>
using namespace std;

int main()
{
    int x;
    while (cin >> x && x != 42);
    return 0;
}
```

### 习题4-11
书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。
```
if (a > b && b > c && c > d)
{

}
```

### 习题4-12
假设i、j 和k 是三个整数，说明表达式 i != j < k 的含义。

逻辑运算符<先执行，i != (j < k)  j< k 取值可能为false or true, 0 or 1
在判断i不等于 0 或者 1 ，最终结果为true or false

### 习题4-13
在下述语句中，当赋值完成后 i 和 d 的值分别是多少？
```
int i;   double d;
d = i = 3.5; 
i = d = 3.5; 
```
// i = 3, d = 3.0
// d = 3.5, i = 3

### 习题4-14
执行下述 if 语句后将发生什么情况？
```
if (42 = i)   
if (i = 42)   
```
第一个条件编译错误。赋值运算符左侧必须是一个可修改的左值。而字面值是右值。
第二个条件i被赋值为42，判断布尔值为真。

### 习题4-15
下面的赋值是非法的，为什么？应该如何修改？
```
double dval; int ival; int *pi;
dval = ival = pi = 0;
```
int* 类型不能给int型指针赋值
dval = ival = 0;
pi = 0;

### 习题4-16
尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？
```
if (p = getPtr() != 0)
if (i = 1024)
```
p,i实际上执行的是赋值语句，p执行是(getPtr()!=0)的布尔结果。
```
if ((p = getPtr()) != 0)
if (i == 1024)
```

### 习题4-17
说明前置递增运算符和后置递增运算符的区别。
前置版本将对象本身作为左值返回，后置版本则将对象原始值的副本作为右值返回。

### 习题4-18
如果132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

将会从第二个元素开始取值，并且最后对于v.end()进行取值，结果未定义。

### 习题4-19
假设 ptr 的类型是指向 int 的指针、vec 的类型是vector、ival 的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？
```
(a) ptr != 0 && *ptr++  
(b) ival++ && ival
(c) vec[ival++] <= vec[ival] 
```
(a) 判断ptr不是一个空指针 并且 ptr当前指向的元素也为真，然后将ptr指向下一个元素。
(b) 判断ival的值为真 并且 (ival+1) 后也为真
(c) C表达式有错误， <=没有规定运算顺序，所以 运算符左右两边不确定先执行哪一个
修改 vec[val] <= vec[val+1]

### 习题4-20
假设 iter 的类型是 vector::iterator, 说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
```
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty();
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
```
(a) 合法，返回迭代器所指的对象值，迭代器递增
(b) 不合法，vector所存的string 对象没有++操作
(c) 不合法，指针没有.操作
(d) 合法，判断指针所指对象是否为空
(e) 不合法，string对象没有++操作
(f) 合法，判断iter所指对象是否为空，然后迭代器递增

### 习题4-21
编写一段程序，使用条件运算符从 vector 中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for (auto &x : vec)
    {
        cout << (x%2 ==0 ?x:x*2);
        cout << " ";
    }
    return 0;
}
```

### 习题4-22
本节的示例程序将成绩划分为high pass、pass 和 fial 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本：一个版本只使用条件运算符；另一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？
```
#include<iostream>

using namespace std;

int main()
{
    int grade;
    while (cin >> grade && (grade >=0 && grade <=100))
    {
        /* code */
        cout << (grade >= 90?"high pass": grade >= 75?"pass": grade >= 60?"low pass":"fail") << endl;
    }
    
    return 0;
}
```

```
#include<iostream>

using namespace std;

int main()
{
    int grade;
    while (cin >> grade && (grade >=0 && grade <=100))
    {
        if (grade >= 90)
            cout << "high pass" << endl;

        else if (grade >= 75)
        {
            cout << "pass" << endl;
        }
        else if (grade >= 60)
        {
            cout << "low pass" << endl;
        }
        else
        {
            cout << "fail" << endl;
        }
    }
    
    return 0;
}
```

if-else 语句清晰明了

### 习题4-23
因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表指出它的问题在哪里？应该如何修改？
```
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```
加法运算符优先级高于 条件运算符
string pl = s + (s[s.size() - 1] == 's' ? "" : "s" );

### 习题4-24
本节的示例程序将成绩划分为 high pass、pass、和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值的过程将是怎样的？

result =  (grade > 90)?"high pass": (grade < 60)?"fail":"pass";

求值过程是先计算grade是否大于90，若大于90，输出high pass
否则，继续判断grade 是否小于60，若小于60，输出fail,否则输出pass.

### 习题4-25
如果一台机器上 int 占 32 位、char 占8位，用的是 Latin-1 字符集，其中字符'q' 的二进制形式是 01110001，那么表达式'q' << 6的值是什么？
char 先提升为int
00000000 00000000 00011100 01000000
十进制是7232

### 习题4-26
在本节关于测验成绩的例子中，如果使用unsigned int 作为quiz1 的类型会发生什么情况？

在有的机器上，unsigned int 类型可能只有 16 位，因此结果是未定义的。
因此需要声明unsigned long, 这样，quiz1在任何机器上都将至少拥有32位

### 习题4-27
下列表达式的结果是什么？
```
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2 
(b) ul1 | ul2 
(c) ul1 && ul2
(d) ul1 || ul2 
```

ul1 = 00000011
ul2 = 00000111
(a) 00000011 3
(b) 00000111 7
(c) true
(d) true

### 习题4-28
编写一段程序，输出每一种内置类型所占空间的大小。
```
#include<iostream>

using namespace std;

int main()
{
    cout << "char \t" << sizeof(char) << " bytes." << endl;
    cout << "wchar_t \t" << sizeof(wchar_t) << " bytes." << endl;
    cout << "char16_t \t" << sizeof(char16_t) << " bytes." << endl;
    cout << "char32_t \t" << sizeof(char32_t) << " bytes." << endl;
    cout << "char \t" << sizeof(char) << " bytes." << endl;
    cout << "char \t" << sizeof(char) << " bytes." << endl;
    cout << "short \t" << sizeof(short) << " bytes." << endl;
    cout << "int \t" << sizeof(int) << " bytes." << endl;
    cout << "long \t" << sizeof(long) << " bytes." << endl;
    cout << "long long \t" << sizeof(long long) << " bytes." << endl;
    cout << "float \t" << sizeof(float) << " bytes." << endl;
    cout << "double \t" << sizeof(double) << " bytes." << endl;
    cout << "long double \t" << sizeof(long double) << " bytes." << endl;
    cout << "bool \t" << sizeof(bool) << " bytes" << endl;
    return 0;
}
```

### 习题4-29
推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如不一样，为什么？
```
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

第一条输出语句是数组x的大小 =10
第二条语句未定义

### 习题4-30
根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。
(a) sizeof x + y      
(b) sizeof p->mem[i]  
(c) sizeof a < b     
(d) sizeof f()  

(a) (sizeof x) + y
(b) sizeof (p->mem[i])
(c) (sizeof a) < b     
(d) sizeof (f())

### 习题4-31
本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

建议:除非必须，否则不用递增递减运算符的后置版本
原因非常简单
前置版本的递增运算符避免了不必要的工作，它把值加1后直接返回改变了的运算对象。与之相比，后置版本需要将原始值存储下来以便于返回这个未修改的内容。如果我们不需要修改前的值，那么后置版本的操作就是一种浪费。

不需要改

### 习题4-32
解释下面这个循环的含义。
```
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```
for循环遍历数组ia，ix和ptr都是循环遍历计数器作用，一个相当于下标，一个是指向指针的移动。

### 习题4-33
根据4.12节中的表说明下面这条表达式的含义。
someValue ? ++x, ++y : --x, --y

判断someValue值，如果true, x递增加1，舍弃，y递增加1，然后舍弃，y递增1，返回。
如果为false,x递增1，舍弃，y递减1，返回
> ,逗号运算符

### 习题4-34
根据本节给出的变量定义，说明在下面的表达式中奖发生什么样的类型转换：
```
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;

(a) float -> bool
(b) ival int->float  相加后 float ->double
(c) cval char -> int 相乘后 int -> double
```

### 习题4-35
假设有如下的定义：
```
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```
请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
```
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;
```
(a) 'a' char->int 相加后int -> char
(b) ival int -> double 相乘后 ui->double 相减后->float
(c) ui unsigned ->float  相乘后 float ->double
(d) ival ->float 相加 float ->double 最后double ->int -> char


### 习题4-36
假设 i 是int类型，d 是double类型，书写表达式 i*=d 使其执行整数类型的乘法而非浮点类型的乘法。
```
i *= static_cast<int>d;
```

### 习题4-37
用命名的强制类型转换改写下列旧式的转换语句。
```
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);
(c) pv = &d;
(d) pc = (char*)pv;
```

(a) pv = static_cast<void*>(const_cast<string*>(ps));
(b) i = static_cast<int>(*pc);
(c) pv = static_cast<void*>(&d);
(d) pc = static_cast<char*>(pv)

### 习题4-38
说明下面这条表达式的含义。
```
double slope = static_cast<double>(j/i);
```

将 j/i 的结果值转换为 double，然后赋值给slope。