## 第七章的习题

### 习题7.1
使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本。
```
#include<iostream>

using namespace std;

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

### 习题7.2
曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine函数和isbn成员。
```
#include<iostream>

using namespace std;

struct Sales_data
{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    return 0;
}
```

### 习题7.3
修改7.1.1节的交易处理程序，令其使用这些成员。
```
#include<iostream>

using namespace std;

struct Sales_data
{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

### 习题7.4 
编写一个名为Person的类，使其表示人员的姓名和地址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
```
#include<iostream>
using namespace std;

struct Person
{
    std::string name;
    std::string address;
};
```

### 习题7.5
在你的Person类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是const的呢？解释原因。
```
#include<iostream>
using namespace std;

struct Person
{
    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    std::string name;
    std::string address;
};
```

函数使用const，因为在函数体内不会改变this所指的对象，所以把this设置为指向常量的指针有助于提供函数的灵活性。
常量的person对象也需要使用。

### 习题7.6
对于函数add、read和print，定义你自己的版本。
```
#include<iostream>
using namespace std;

struct Sales_data
{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const 
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0.0;
    }
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

### 习题7.7
使用这些新函数重写7.1.2节练习中的程序。
```
#include<iostream>
#include "cpp_7-6.h"
using namespace std;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

### 习题7.8
为什么read函数将其Sales_data参数定义成普通的引用，而print函数将其参数定义成常量引用？  
* read函数对传入的对象进行操作，会改变对应的值  
* print函数只是输出对应对象的值，不改变对应的值，使用常量引用即可。

### 习题7.9
对于7.1.2节练习中代码，添加读取和打印Person对象的操作。
```
#include<iostream>
using namespace std;

struct Person
{
    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << "  " << person.getAddress() << endl;
    return os;
}

```

### 习题7.10
在下面这条if语句中，条件部分的作用是什么？
```
if (read(read(cin, data1), data2))
```

read函数的返回值是istream对象，if语句中条件部分作用是用cin输入两个data对象

### 习题7.11
在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。  
cpp_7-11.h
```
#include<iostream>
#include<string>
using namespace std;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p) {}
    Sales_data(std::istream &);

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const 
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0.0;
    }
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}
```

cpp_7-11.cpp
```
#include "cpp_7-11.h"

int main()
{
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("abc");
    print(std::cout, item2) << std::endl;

    Sales_data item3("abc",5,100);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;
    return 0;
}
```

### 习题7.12
把只接受一个istream 作为参数的构造函数移到类的内部。
```
#include<iostream>
#include<string>
using namespace std;

//声明一下read函数，类中使用到
struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data
{
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p) {}
    Sales_data(std::istream &is) {read(is, *this);};

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const 
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0.0;
    }
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

### 习题7.13
使用istream构造函数重写第229页的程序
```
#include "cpp_7-12.h"

int main()
{
    Sales_data total(std::cin);
    if (!total.isbn().empty())
    {
        std::istream &is = std::cin;
        while (is)
        {
            Sales_data trans(is);
            if (total.bookNo == trans.bookNo)
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        cout << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

### 习题7.14
编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

```
Sales_data():units_sold(0),revenue(0) {}
```

### 习题7.15
为你的 Person 类添加正确的构造函数。
```
#include<iostream>
#include<string>
using namespace std;

struct Person;
std::istream &read(std::istream &, Person &);

struct Person
{
    Person() = default;
    Person(const std::string &name, const std::string &address):name(name), address(address) {}
    Person(std::istream &is) { read(is, *this); }

    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << "  " << person.getAddress() << endl;
    return os;
}

```

### 习题7.16
在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public 说明符之后？什么样的成员应该定义在private 说明符之后？

在类的定义中对于访问说明符出现的位置和次数没有限定，一个类可以包含0个或者多个访问说明符，而且对于某个访问说明符能出现多少次也没有严格限定。每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个访问说明符或者到达类的结尾处为止。

在整个程序内可被访问的成员应该定义在public说明符之后；只能被类的成员函数访问，不能被使用该类的代码访问的成员定义在private说明符之后。

### 习题7.17
使用class 和 struct 时有区别吗？如果有，是什么？

使用class和struct定义类唯一的区别就是默认的访问权限不同。

### 习题7.18
封装是何含义？它有什么用处？

封装是使用访问说明符隐藏类内部成员的细节，提供部分接口给外部使用。
封装隐藏类内部成员的细节以及具体的实现，当使用类时，只需要考虑它提供什么接口操作，而不用考虑具体实现。

### 习题7.19
在你的Person 类中，你将把哪些成员声明成public 的？哪些声明成private 的？解释你这样做的原因。

构造函数，getName(),getAddress()函数设置为public,函数提供外部使用的接口，设置为public

成员变量name和address设置为private,隐藏内部细节对外部使用者不可见。

### 习题7.20
友元在什么时候有用？请分别举出使用友元的利弊。

当其他类或者函数访问类的非公有成员时，需要令其他类或者函数成为类的友元。

利：为其他类或者函数访问类的私有成员变量提供了访问权限  
弊：破坏类的封装性和可维护性。  

### 习题7.21
修改你的Sales_data 类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。
```
#include<iostream>
#include<string>
using namespace std;

class Sales_data
{
    friend std::istream &read(istream &is, Sales_data &item);
    friend std::ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

    public:
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p) {}
    Sales_data(std::istream &is) {read(is, *this);};

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

    private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const 
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0.0;
    }
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

### 习题7.22
修改你的Person 类使其隐藏实现的细节。
```
#include<iostream>
#include<string>
using namespace std;

class Person
{
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);

    public:
    Person() = default;
    Person(const std::string &name, const std::string &address):name(name), address(address) {}
    Person(std::istream &is) { read(is, *this); }

    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    
    private:
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << "  " << person.getAddress() << endl;
    return os;
}

```

### 习题7.23
编写你自己的Screen 类型。
```
#include<string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;

    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht*wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;  //显式内联函数
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;    
    
};

inline 
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}
```

### 习题7.24
给你的Screen 类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents 初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。
```
#include<string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd),contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht*wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;  //显式内联函数
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;    
    
};

inline 
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}
```

### 习题7.25
Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？

* Screen 能安全地依赖于拷贝和赋值操作的默认版本。因为Screen的成员只有声明的内置成员pos以及string。  
* 管理动态内存的类则不能依赖于拷贝和赋值操作的默认版本，而且也应该尽量使用string和vector来避免动态管理内存的复杂性。

### 习题7.26
将Sales_data::avg_price 定义成内联函数。
```
#include<iostream>
#include<string>
using namespace std;

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data
{
    Sales_data():units_sold(0),revenue(0) {}
    Sales_data(const std::string &s):bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p) {}
    Sales_data(std::istream &is) {read(is, *this);};

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline
double Sales_data::avg_price() const 
{
    if (units_sold)
    {
        return revenue/units_sold;
    }
    else
    {
        return 0.0;
    }
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

### 习题7.27
给你自己的Screen 类添加move、set 和display 函数，通过执行下面的代码检验你的类是否正确。
```
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```
cpp_7-27.h
```
#include<string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd),contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht*wd, c) {}
    
    Screen &set(char);
    Screen &set(pos, pos, char);

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;  //显式内联函数

    Screen &move(pos r, pos c);

    Screen &display(std::ostream &os) 
                    { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const 
                    { do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;    

    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this;
}

inline 
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}
```

cpp_7-27.cpp
```
#include<iostream>

#include "cpp_7-27.h"

using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}
```

### 习题7.28
如果move、set和display函数的返回类型不是Screen& 而是Screen，则在上一个练习中奖会发生什么？  

如果返回类型是Screen，那么move返回的是*this的一个副本，后续的set函数只能改变临时副本，而对原来的myScreen值没有改变。

### 习题7.29
修改你的Screen 类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？
```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX

XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

预测正确

### 习题7.30
通过this指针使用成员的做法虽然合法，但是有点多余。讨论显示使用指针访问成员的优缺点。

优点
* 程序更易于阅读，解释性好  
* 对类对象的set（设置器）来说简单易懂，可重名
```
void setName(const std::string &name) { this->name = name;}
```

缺点：  
* 有时候多余
```
std::string getName() const { return this -> name; }
```

### 习题7.31
定义一对类X 和Y，其中X 包含一个指向 Y 的指针，而Y 包含一个类型为 X 的对象。
```
class Y;

class X {
    Y* y = nullptr;
};

class Y {
    X x;
};
```