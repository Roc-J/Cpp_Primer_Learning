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

### 习题7.32
定义你自己的Screen 和 Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。
```
#include<vector>
#include<string>

class Screen;

class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;

        void clear(ScreenIndex);
    private:
        std::vector<Screen> screens;   //这里不能够初始化
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
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

//友元函数定义 在class Screen后
inline void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

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

inline Screen &Screen::move(pos r, pos c)
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

### 习题7.33
如果我们给Screen 添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。
```
pos Screen::size() const
{
	return height * width;
}
```

返回类型pos未定义  
修改为
```
Screen::pos Screen::size() const
{
	return height * width;
}
```

### 习题7.34
如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？
```
#include<string>

int height;
class Screen {
public:
    //typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height;
    }
    typedef std::string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
};
```

如果放到public的最后，那么函数dummy_fcn 中的pos是未定义的。

>类型名的定义通常出现在类的开始处，这样就能确保所有使用该类型的成员都出现在类名的定义之后。

### 习题7.35
解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
```
typedef string Type;
Type initVal(); 
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(); 
private:
    int val;
};
Type Exercise::setVal(Type parm) { 
    val = parm + initVal();     
    return val;
}
```

错误是重复定义Type。

一般来说，内层作用域可以重新定义外层作用域中的名字，即使该名字已经在内层作用域中使用过。然而在类中，如果成员使用了外层作用域中的某个名字，而该名字代表一种类型，则类不能在之后重新定义该名字。

不过lz在自己机器上，修改了函数定义的返回类型，编译通过了。
```
#include<string>
using namespace std;

typedef string Type;
Type initVal(); 
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal(); 
private:
    int val;
};
Exercise::Type Exercise::setVal(Type parm) { 
    val = parm + initVal();     
    return val;
}
```

尽管重新定义类型名字是一种错误的行为，但是编译器并不为此负责。一些编译器仍能顺利通过这样的代码，而忽略代码有错的事实。

### 习题7.36
下面的初始值是错误的，请找出问题所在并尝试修改它。
```
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int rem, base;
};
```

```
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int base, rem;
};
```

### 习题7.37
使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。
```
Sales_data first_item(cin); 
int main() {
	Sales_data next;
	Sales_data last("9-999-99999-9"); 
}
```

第一个使用Sales_data(std::istream &is) ; 各成员值从输入流读入  
第二个使用默认构造函数  bookNo = "", cnt = 0, revenue = 0.0  
第三个使用Sales_data(std::string s = "");bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0  

### 习题7.38
有些情况下我们希望提供cin作为接受istream& 参数的构造函数的默认实参，请声明这样的构造函数。
```
Sales_data(std::istream &is) {read(is, *this);};
```

### 习题7.39
如果接受string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法。调用Sales_data()构造函数，无法区分哪个重载

### 习题7.40
从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
```
(a) Book
(b) Data
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
```

```
#include<string>

class Book {
    public:
        Book() = default;
        Book(const std::string & bookno, const std::string & bookname,const std::string & author, double price):
            bookNo(bookno), bookName(bookname), author(author), price(price) {}
            
    private:
        std::string bookNo;
        std::string bookName;
        std::string author;
        double price = 0.0;

};
```

### 习题7.41
使用委托构造函数重新编写你的Sales_data 类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

.h
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
    Sales_data(std::string s, unsigned cnt, double price):bookNo(s),units_sold(cnt),revenue(cnt*price) 
    {
        std::cout << "Sales_data(std::string s, unsigned cnt, double price)" << std::endl;
    }

    Sales_data(): Sales_data("", 0, 0) 
    {
        std::cout << "Sales_data()" << std::endl;
    }
    Sales_data(std::string s): Sales_data(s, 0, 0) 
    {
        std::cout << "Sales_data(std::string s)" << std::endl;
    }

    Sales_data(std::istream &is): Sales_data() 
    {
        std::cout << "Sales_data(std::istream &is)" << std::endl;
        read(is, *this);
    }

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
.cpp
```
#include "cpp_7-41.h"

int main()
{
    cout << "main() Sales_data()" << endl;
    Sales_data s1;

    cout << "main() Sales_data(std::string s)" << endl;
    Sales_data s2("abc-123");

    cout << "main() Sales_data(std::string s, unsigned cnt, double price)" << endl;
    Sales_data s3("abc_123", 5, 100);

    cout << "main() Sales_data(std::istream &is)" << endl;
    Sales_data s4(std::cin);
    return 0;
}
```

### 习题7.42
对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
```
#include<string>

class Book {
    public:
        Book(std::string & bookno, std::string & bookname, std::string & author, double price):
            bookNo(bookno), bookName(bookname), author(author), price(price) {}

        Book(std::string & bookno): Book(bookno, "", "", 0.0) {}

        Book(std::istream &is) 
        {
            is >> bookNo >> bookName >> author >> price;
        }
            
    private:
        std::string bookNo;
        std::string bookName;
        std::string author;
        double price = 0.0;

};
```

### 习题7.43
假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义C 的默认构造函数。
```
class Nodefault 
{
public:
    Nodefault(int i) {}
};

class C
{
public:
    C():ndf(0) {}
private:
    Nodefault ndf;
};
```

### 习题7.44
下面这条声明合法吗？如果不，为什么？
```
vector<NoDefault> vec(10);
```

不合法，因为NoDefault没有默认构造函数。

### 习题7.45
如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

合法。因为C有默认构造函数。

### 习题7.46
下面哪些论断是不正确的？为什么？
```
(a) 一个类必须至少提供一个构造函数。
(b) 默认构造函数是参数列表为空的构造函数。
(c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
(d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
```

(a) 不正确，如果类没有显示的定义构造函数，那么编译器就会隐式的定义一个默认的构造函数。
(b) 不完全正确。  
> 为每个参数都提供默认值的构造函数也是默认构造函数。  
(c) 不正确。 对于类来说，哪怕没有意义的值 也需要初始化。
(d) 不正确。  只有当类没有定义任何构造函数的时候，编译器才会生成一个默认构造函数。

### 习题7.47
说明接受一个string 参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。

取决于用户选择。 
在本例中，转换为explicit是对的，null_book中的string可能表示了一个不存在的ISBN编号。  
* 优点  
可以抑制构造函数定义的隐式转换  
* 缺点  
需要显式的使用构造函数

### 习题7.48
假定Sales_data 的构造函数不是explicit的，则下述定义将执行什么样的操作？
```
string null_isbn("9-999-9999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

编译OK，定义和是不是explicit无关。

### 习题7.49
对于combine 函数的三种不同声明，当我们调用i.combine(s) 时分别发生什么情况？其中 i 是一个 Sales_data，而 s 是一个string对象。
```
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&); // error C2664: 无法将参数 1 从“std::string”转换为“Sales_data &”	
(c) Sales_data &combine(const Sales_data&) const; // 该成员函数是const 的，意味着不能改变对象。而 combine函数的本意就是要改变对象
```

第一种方式 ok  
第二种方式 错误，无法用 "std::__cxx11::string" 类型的值初始化 "Sales_data &" 类型的引用(非常量限定)
第三种方式 错误，定义成const则不能改变对象，combine函数就是要改变对象的。

### 习题7.50
确定在你的Person 类中是否有一些构造函数应该是 explicit 的。
```
explicit Person(std::istream &is){ read(is, *this); }
```

### 习题7.51
vector 将其单参数的构造函数定义成 explicit 的，而string则不是，你觉得原因何在？
* 接受一个单参数的const char* 的string构造函数不是explicit的  
* 接受一个容量参数的vector构造函数是explicit  

### 习题7.52
使用2.6.1节的 Sales_data 类，解释下面的初始化过程。如果存在问题，尝试修改它。
```
Sales_data item = {"987-0590353403", 25, 15.99};
```

Sales_data不是聚合类，修改如下
```
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

### 习题7.53
定义你自己的 Debug。
```
class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}

    constexpr bool any() {return hw || io || other;}
    void set_hw(bool b) {hw = b;}
    void set_io(bool b) {io = b;}
    void set_other(bool b) {other = b;}
private:
    bool hw;
    bool io;
    bool other;

}
```

### 习题7.54
Debug中以 set_ 开头的成员应该被声明成 constexpr 吗？如果不，为什么？

不能，constexpr必须有返回语句。

### 习题7.55
7.5.5节的 Data 类是字面值常量类吗？请解释原因。

不是，因为 std::string 不是字面值类型

### 习题7.56
什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

类的一些成员与类本身直接相关，而不是与类的各个对象保持关联 就是类的静态成员。

优点是静态成员能用于某些场景，而普通成员不能。  
类的静态成员存在于任何对象之外，对象中不包含任何与静态数据成员有关的数据。静态成员函数也不与任何对象绑定在一起，它们不包含this指针，作为结果，静态成员函数不能声明成const.

### 习题7.57
编写你自己的 Account 类。
```
#include<iostream>
#include<string>
using namespace std;

class Account
{
public:
    void calculate() { amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
}
```

### 习题7.58
下面的静态数据成员的声明和定义有错误吗？请解释原因。
```
//example.h
class Example {
public:
	static double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
//example.c
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

错误，rate应该是一个常量表达式。类内只能初始化整型类型的静态常量，所以不能初始化vector，修改后
```
//example.h
class Example {
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec;
};
//example.c
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```