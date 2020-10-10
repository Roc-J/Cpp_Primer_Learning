#include<iostream>

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

int main()
{
    func();
    func2();
    func3();
    func4();
    return 0;
}