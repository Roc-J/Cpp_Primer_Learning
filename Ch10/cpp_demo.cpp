#include<iostream>
#include<iterator>
#include "../Ch07/cpp_7-12.h"

using namespace std;

void func()
{
     size_t v1 = 42;
     auto f = [v1] {return v1;};
     v1 = 0;
     auto j = f(); 
     cout << j << endl;
}

void func2()
{
    size_t v1 = 42;  //局部变量
    auto f2 = [&v1] { return v1; };

    v1 = 0;
    auto j = f2();
    cout << j << endl;
}

void func3()
{
     size_t v1 = 42;
     auto f = [v1] () mutable { return ++v1; };
     v1 = 0;
     auto j = f();  
     cout << j << endl;
}

void func4()
{
    size_t v1 = 42;
    auto f2 = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f2();

    cout << j << endl;
}

void IOreWrite()
{
    istream_iterator<Sales_data> item_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    //将第一笔交易记录存在sum中，并读取下一条记录
    Sales_item sum = *item_iter++;
    while( item_iter != eof) 
    {
        if (item_iter -> isbn() == sum.isbn())
            sum += *item_iter++;
        else
        {
            out_iter = sum;
            sum = *item_iter++;
        }
    }
    out_iter = sum; 
}


int main()
{
    func();
    func2();
    func3();
    func4();
    return 0;
}