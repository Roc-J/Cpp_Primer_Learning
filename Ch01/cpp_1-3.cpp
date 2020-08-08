#if 0
@File    :   cpp_1-3.cpp
@Time    :   2020/07/26 13:46:06
@Author  :   qinjingkun 
@Version :   1.0
@Contact :   qinjingkun@yuewen.com
#endif 
//here put the include header file

#include<iostream>

int main()
{
    std::cout << "Input two numbers :" << std::endl;
    int x, y;
    std::cin >> x >> y;
    std::cout << "X is : " << x << std::endl; 
    std::cout << "y is : " << y << std::endl; 
    std::cout << "X + y = " << x+y << std::endl;
    return 0;
}