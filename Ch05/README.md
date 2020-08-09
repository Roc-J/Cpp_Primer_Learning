## 第五章的习题

### 习题5.1
什么是空语句？什么时候会用到空语句？

* 最简单的语句是空语句(null statement),空语句中只含有一个单独的分号: ;空语句
* 如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该需要使用空语句。一种常见的情况是，当循环的全部工作在条件部分就可以完成时，我们通常会用到空语句。

### 习题5.2
什么是块？什么时候会用到块？
* 复合语句(compound statement)是指用花括号括起来的语句和声明的序列，复合语句也被称作块。
* 如果在程序的某个地方，语法上需要一条语句，但是逻辑上需要多条语句，则应该使用复合语句。

### 习题5.3
使用逗号运算符重写1.4.1节的 while 循环，使它不再需要块，观察改写之后的代码可读性提高了还是降低了。
```
#include<iostream>

using namespace std;

int main()
{
    int sum=0, val=1;
    while (val <=10)
        sum+=val, ++val;
    cout << "sum is " << sum << endl;
    return 0;
}
```
这样代码可读性降低了。

### 习题5.4
说明下列例子的含义，如果存在问题，试着修改它。
```
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
		if (!status) { /* . . . */ }
```
(a) 语句声明string的一个迭代器来遍历，但是声明迭代器语句放在while条件中，每次都会重新声明一个变量，需要将变量的定义放在循环的外面进行初始化

(b) 语句的if语句的status和while语句的status不在同一个作用块内，不能访问到，应该把if语句放在while语句复合语句内。

### 习题5.5
写一段自己的程序，使用if else 语句实现把数字转换为字母成绩的要求。
```
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};
    int score;
    while(cin >> score)
    {
        string gradelevel;
        if(score<60)
        {
            gradelevel = grades[0];
        }
        else
        {
            gradelevel = grades[(score - 50)/10];
            if (score%10 > 7)
            {
                gradelevel += "+";
            }
            else if (score%10 < 3)
            {
                gradelevel += "-";
            }
        }
        cout << "your score is : " << score << " your gradelevel is : " << gradelevel << endl;
        
    }
    return 0;
}
```

### 习题5.6
改写上一题的程序，使用条件运算符代替if else语句。
```
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};
    int score;
    while(cin >> score && (score <=100) && (score >=0))
    {
        string gradelevel;
        score < 60?gradelevel = grades[0]:gradelevel = grades[(score - 50)/10],(score%10 > 7)?gradelevel += "+":(score%10 < 3)?gradelevel += "-":"";
        cout << "your score is : " << score << " your gradelevel is : " << gradelevel << endl;
        
    }
    return 0;
}
```

### 习题5.7
改写下列代码段中的错误。
```
(a) if (ival1 != ival2) 
		ival1 = ival2
    else 
    	ival1 = ival2 = 0;
(b) if (ival < minval) 
		minval = ival;
    	occurs = 1;
(c) if (int ival = get_value())
    	cout << "ival = " << ival << endl;
    if (!ival)
    	cout << "ival = 0\n";
(d) if (ival = 0)
    	ival = get_value();
```

(a) if语句的后面缺少;
(b) if后的复合语句缺少{}
(c) if(!val) 应该是else语句
(d) if判断语句应该是ival == 0

### 习题5.8
什么是“悬垂else”？C++语言是如何处理else子句的？
* 当一个if语句嵌套在另一个if语句内部时，很可能if分支会多于else分支。这时候问题出现了，怎么知道某个给定的else是和哪个if匹配呢？这个问题通常称为悬垂else
* C++规定else与离它最近的尚未匹配的if匹配，从而消除了程序的二义性。

### 习题5.9
编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。
```
#include<iostream>

using namespace std;

int main()
{
    char ch;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0;
    while (cin >> ch)
    {
        if(ch == 'a')
        {
            aCnt += 1;
        }
        else if(ch == 'e')
        {
            eCnt += 1;
        }
        else if(ch == 'i')
        {
            iCnt += 1;
        } 
        else if(ch == 'o')
        {
            oCnt += 1;
        }
        else if(ch == 'u')
        { 
            uCnt += 1;
        }
        else
        {
            otherCnt +=1;
        }
        
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl;
    return 0;
}
```

### 习题5.10
我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段程序，既统计元音字母的小写形式，也统计元音字母的大写形式，也就是说，新程序遇到'a'和'A'都应该递增 aCnt 的值，以此类推。
```
#include<iostream>

using namespace std;

int main()
{
    char ch;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0;
    while (cin >> ch)
    {
        if(ch == 'a' || ch == 'A')
        {
            aCnt += 1;
        }
        else if(ch == 'e' || ch == 'E')
        {
            eCnt += 1;
        }
        else if(ch == 'i' || ch == 'I')
        {
            iCnt += 1;
        } 
        else if(ch == 'o' || ch == 'O')
        {
            oCnt += 1;
        }
        else if(ch == 'u' || ch == 'U')
        { 
            uCnt += 1;
        }
        else
        {
            otherCnt +=1;
        }
        
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl;
    return 0;
}
```

```
#include<iostream>

using namespace std;

int main()
{
    char ch;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0, spaceCnt=0, tabCnt =0, enterCnt = 0;
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        default:
            ++otherCnt;
            break;
        }
        
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl;
    return 0;
}
```

### 习题5.11
修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。
> noskipws读取时不忽略任何空白字符
```
#include<iostream>

using namespace std;

int main()
{
    char ch;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0, spaceCnt=0, tabCnt =0, enterCnt = 0;
    while (cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++enterCnt;
            break;
        default:
            ++otherCnt;
            break;
        }
        
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl
         << "numbers of space is : " << spaceCnt << endl
         << "numbers of tab is : " << tabCnt << endl
         << "numbers of enter is : " << enterCnt << endl;
    return 0;
}
```

### 习题5.12
修改统计元音字母的程序，使其能统计含以下两个字符的字符序列的数量： ff、fl和fi。

>主要记录一下前面的字符f即可
```
#include<iostream>

using namespace std;

int main()
{
    char ch, prech ;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0, spaceCnt=0, tabCnt =0, enterCnt = 0;
    unsigned ffCnt = 0, flCnt =0, fiCnt = 0;
    while (cin >> std::noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
            if (prech == 'f') fiCnt += 1;
        case 'I':
            ++iCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++enterCnt;
            break;
        case 'f':
            if (prech == 'f') 
            {
                ffCnt += 1;
            }
            break;
        case 'l':
            if (prech == 'f')
            {
                flCnt += 1;
            }
            break;
        default:
            ++otherCnt;
            break;
        }
        //记录一下前面的字符f
        prech = ch;
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl
         << "numbers of space is : " << spaceCnt << endl
         << "numbers of tab is : " << tabCnt << endl
         << "numbers of enter is : " << enterCnt << endl
         << "numbers of ff is : " << ffCnt << endl
         << "numbers of fl is : " << flCnt << endl
         << "numbers of fi is : " << fiCnt << endl;
    return 0;
}
```

### 习题5.13
下面显示的每个程序都含有一个常见的编码错误，指出错误在哪里，然后修改它们。
```
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

(a) case语句后缺少break;
```
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;break;
    case 'e': eCnt++;break;
    default: iouCnt++;break;
}
```

(b) 
default 中变量ix未定义
```
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
```

(c) 
对10取余，不会得出10，改为0即可
case 使用:, 
```
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3:case 5:case 7:case 9:
        oddcnt++;
        break;
    case 0:case 2:case 4:case 6:case 8:
        evencnt++;
        break;
}
```

(d)
case标签必须是常量
```
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case 512:
        bufsize = ival * sizeof(int);
        break;
    case 1024:
        bufsize = jval * sizeof(int);
        break;
    case 4096:
        bufsize = kval * sizeof(int);
        break;
}
```

### 习题5.14
编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词，所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。例如：如果输入是：
```
how now now now brown cow cow
```
那么输出应该表明单词now连续出现了3次。

```
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string curstr,s,maxS;
    cin >> curstr;
    int sCnt = 0, maxCnt = 0;
    if (!curstr.empty())
    {
        sCnt = 1;
        maxCnt = 1;
        maxS = curstr;
    }
    while (cin >> s)
    {
        if ( s == curstr)
        {
            sCnt += 1;
        }
        else
        {
            if (maxCnt<sCnt)
            {
                maxCnt = sCnt;
                maxS = curstr;
            }
            curstr = s;
            sCnt = 1;
        }
        
    }
    if (maxCnt<sCnt)
    {
        maxCnt = sCnt;
        maxS = s;
    }
    if (maxCnt == 1)
    {
        cout << "No word has ever appeared in succession." << endl;
    }
    else
    {
        cout << maxS << " output " << maxCnt << endl;
    }
    return 0;
}
```

### 习题5.15
说明下列循环的含义并改正其中的错误。
```
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)
    	// . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }
```

(a) ix在for循环语句结束后就不存在了
```
int ix;
for (ix = 0; ix != sz; ++ix) { /* ... */ }
if (ix != sz)
	// . . .
```
(b) for语句初始化缺少;
```
int ix;
for (;ix != sz; ++ix) { /* ... */ }
```

(c) for语句是死循环
```
for (int ix = 0; ix != sz; ++ix;) { /*...*/ }
```

### 习题5.16
while 循环特别适用于那种条件不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环更像是在按步骤迭代，它的索引值在某个范围内一次变化。根据每种循环的习惯各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于哪种？为什么？
```
#include<iostream>
using namespace std;
int main()
{
    int i;
    while(cin >> i)
    {
        cout << i << " ";
    }

    for(int i; cin >> i;)
    {
        cout << i << " ";
    }

    for(int i=0;i<10;++i)
    {
        cout << i << " ";
    }

    int i = 0;
    while(i<10)
    {
        cout << i << " ";
        ++i;
    }
    return 0;
}
```

for循环对于已知循环遍历的更友好，实际上while对于未知的步骤更好。

### 习题5.17
假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果为真。
```
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec1 = {0,1,1,2,5};
    vector<int> vec2 = {0,1,1,2,4,5,6};
    size_t indexs = vec1.size()<vec2.size()?vec1.size():vec2.size();
    size_t i;
    for (i = 0; i < indexs; ++i)
    {
        if(vec1[i] != vec2[i])
            break;
    }
    if (i == indexs)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
```

### 习题5.18
说明下列循环的含义并改正其中的错误。
```
(a) do
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    while (cin);
(b) do {
        // . . .
    } while (int ival = get_response()); 
(c) do {
        int ival = get_response();
    } while (ival); // 应该将ival 定义在循环外
```

(a) do 符合语句需要添加{}
```
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
}while (cin);
```
(b) 变量ival定义在while条件中，应该在do语句中定义。
```
int ival;
do {
    // . . .
} while (ival = get_response()); 
```
(c) 应该将ival定义在do语句外
```
int ival;
do {
    ival = get_response();
} while (ival); // 应该将ival 定义在循环外
```

### 习题5.19
编写一段程序，使用do while 循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它。
```
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1,s2;
    string resp;
    do {
        cout << "input two string " << endl;
        cin >> s1 >> s2;
        if (s1.size() < s2.size())
        {
            cout << s1 << endl;
        }
        else
        {
            cout << s2 << endl;
        }
        cout << "continue? input Yes or No " << endl;
        cin >> resp;
    } while (!resp.empty() && tolower(resp[0]) !='n');
    return 0;
}
```

### 习题5.20
编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有的单词都读完为止。使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。
```
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string pres,curs;
    int find = 0;
    while(cin >> curs)
    {
        if (curs == pres)
        {
            find = 1;
            break;
        }
        else
        {
            pres = curs;
        }
    }
    if (find)
    {
        cout << "the word " << curs << " is repeat." << endl;
    }
    else
    {
        cout << "No word is Continuous occurrence." << endl;
    }
    return 0;
}
```
> 使用cin.eof()也可以判断

### 习题5.21
修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。
```
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    string pres,curs;
    int find = 0;
    while(cin >> curs)
    {
        if (islower(curs[0]))
            continue;
        if (curs == pres)
        {
            find = 1;
            break;
        }
        else
        {
            pres = curs;
        }
    }
    if (find)
    {
        cout << "the word " << curs << " is repeat." << endl;
    }
    else
    {
        cout << "No word is Continuous occurrence." << endl;
    }
    return 0;
}
```

### 习题5.22
本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务，重写这段代码，注意不再使用goto语句。
```
// 向后跳过一个带初始化的变量定义是合法的
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

改成for循环
```
for(int sz=get_size(); sz <=0; sz = get_size());
```

### 习题5.23
编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
```
#include<iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "input two numbers: " << endl;
    cin >> x >> y;
    cout << x/y;
    return 0;
}
```

### 习题5.24
修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？
```
#include<iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "input two numbers: " << endl;
    cin >> x >> y;
    if (y == 0)
        throw runtime_error("bad number! The divisor is 0.");
    cout << x/y;
    return 0;
}

input two numbers:
6 0
terminate called after throwing an instance of 'std::runtime_error'
  what():  bad number! The divisor is 0.
```

### 习题5.25
修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。
```
#include<iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "input two numbers: " << endl;
    while( cin >> x >> y)
    {
        try
        {
            if (y == 0)
                throw runtime_error("bad number! The divisor is 0.");
            cout << x/y;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "are you sure again? y or n? " << endl;
            char c;
            cin >> c;
            if(c == 'n')
                break;
        }
    }
    
    return 0;
}
```