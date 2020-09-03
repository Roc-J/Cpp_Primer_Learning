## 第八章的习题

### 习题8.1
编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。
```
#include<iostream>

using namespace std;

std::istream& func(std::istream &is)
{
    std::string s;
    while (is >> s)
    {
        cout << s << std::endl;
    }
    is.clear();
    return is;
}
```

### 习题8.2
测试函数，调用参数为cin。
```
#include<iostream>

using namespace std;

std::istream& func(std::istream &is)
{
    std::string s;
    while (is >> s)
    {
        cout << s << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    std::istream &is = func(std::cin);
    cout << is.rdstate() << endl;
    return 0;
}
```
is.rdstate() 值为0

### 习题8.3
什么情况下，下面的while循环会终止？
```
while (cin >> i) /*  ...    */
```

如果badbit、failbit和eofbit任一个被置位，则检测流状态的条件会失败。

### 习题8.4
编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。
```
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void readFromFile(const string & filename, vector<string> & vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
        {
            vec.push_back(buf);
        }
        
    }
}
```

### 习题8.5
重写上面的程序，将每个单词作为一个独立的元素进行存储。
```
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void readFromFile(const string & filename, vector<string> & vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
        {
            vec.push_back(buf);
        }
        
    }
}
```

### 习题8.6
重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。
```
#include<fstream>
#include "../Ch07/cpp_7-26.h"

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input,trans))
        {
            if (total.bookNo == trans.bookNo)
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

执行命令需要把文件名作为参数

### 习题8.7
修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。
```
#include<fstream>
#include "../Ch07/cpp_7-26.h"

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream out(argv[2]);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input,trans))
        {
            if (total.bookNo == trans.bookNo)
                total.combine(trans);
            else
            {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

### 习题8.8
修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留.
```
#include<fstream>
#include "../Ch07/cpp_7-26.h"

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream out(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input,trans))
        {
            if (total.bookNo == trans.bookNo)
                total.combine(trans);
            else
            {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}
```

### 习题8.9
使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。
```
#include<iostream>
#include<sstream>
using namespace std;

std::istream& func(std::istream &is)
{
    std::string s;
    while (is >> s)
    {
        cout << s << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    istringstream iss("Hi");
    func(iss);
    return 0;
}
```
输出Hi

### 习题8.10
编写程序，将来自一个文件中的行保存在一个vector中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。
```
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

void readFromFile(const string & filename, vector<string> & vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (getline(ifs, buf))
        {
            vec.push_back(buf);
        }
    }
}

int main()
{
    vector<string> vec;
    readFromFile("./test.txt", vec);
    for (auto &item : vec)
    {
        istringstream iss(item);
        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}
```


### 习题8.11
本节的程序在外层while循环中定义了istringstream 对象。如果record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while 循环之外，验证你设想的修改方法是否正确。
```
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

vector<PersonInfo> readFromFile(const string & filename, vector<PersonInfo> & people)
{
    string line, word;
    ifstream ifs(filename);
    if (ifs)
    {
        istringstream record;
        while (getline(ifs, line))
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record >> info.name;
            while (record >> word)
            {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }
    }
    return people;
}

int main(int argc, char **argv)
{
    vector<PersonInfo> people;
    readFromFile(argv[1], people);
    for (auto &person : people)
    {
        cout << person.name << " ";
        for (auto &info : person.phones)
        {
            cout << info << " ";
        }
        cout << endl;
    }
    return 0;
}
```

### 习题8.12
我们为什么没有在PersonInfo中使用类内初始化？

非必要。聚合类已经可以满足。

### 习题8.13
重写本节的电话号码程序，从一个命名文件而非cin读取数据。
```
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

vector<PersonInfo> readFromFile(const string & filename, vector<PersonInfo> & people)
{
    string line, word;
    ifstream ifs(filename);
    if (ifs)
    {
        istringstream record;
        while (getline(ifs, line))
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record >> info.name;
            while (record >> word)
            {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }
    }
    return people;
}

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	
}

int main(int argc, char **argv)
{
    vector<PersonInfo> people;
    readFromFile(argv[1], people);
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones)
        {
            if(!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                //format?? do what?
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
        {
            cout << entry.name << " "
                 << formatted.str() << endl;
        }
        else
        {
            cout << "input error: " << entry.name 
                 << "invalid numbers " << badNums.str() << endl;
        }
        
    }
    return 0;
}
```

### 习题8.14
我们为什么将entry和nums定义为 const auto& ？

* 遍历输出，不会改变值，用const  
* 类类型 引用避免拷贝操作
