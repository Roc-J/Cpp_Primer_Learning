#include<iostream>

using namespace std;
//使用标记指定数组长度
void print(const char *cp)
{
    if (cp)
    {
        while (*cp)
        {
            cout << *cp++;
        }
    }
}
//使用标准库规范
void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}
//显示传递一个表示数组大小的形参
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

//数组引用形参
void print(int (&arr)[2])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}

int main()
{
    int i = 0, j[2] = { 0, 1 };
    //print(j);
    //print(begin(j), end(j));
    //print(j, end(j) - begin(j));
    print(j);
    return 0;
}