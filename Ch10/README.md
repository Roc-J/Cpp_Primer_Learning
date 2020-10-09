### 习题10.1  
头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入vector中，打印有多少个元素的值等于给定值。
```
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> ivec;
    int val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }
    int value = 5;
    auto total_sum = count(ivec.cbegin(), ivec.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.2  
重做上一题，但读取 string 序列存入 list 中。
```
#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    list<string> slist;
    string val;
    while(cin >> val)
    {
        slist.push_back(val);
    }
    string value = "123";
    auto total_sum = count(slist.cbegin(), slist.cend(), value);
    cout << "count " << value << " in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.3  
用 accumulate求一个 vector 中元素之和。
```
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<int> ivec;
    int val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }

    auto total_sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "accumulate in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.4   
假定 v 是一个vector<double>，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？

结果是int类型
```
#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<double> ivec;
    double val;
    while(cin >> val)
    {
        ivec.push_back(val);
    }

    auto total_sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "accumulate in ivec is " << total_sum << endl;
    return 0;
}
```

### 习题10.5  
在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

会比较指针地址，不会比较字符串的内容。
