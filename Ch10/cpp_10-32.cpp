#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<functional>
#include "../Ch07/cpp_7-26.h"

using namespace std;

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
    return s1.isbn() < s2.isbn();
}

void IOreWrite()
{
    istream_iterator<Sales_data> item_iter(std::cin), eof;
    ostream_iterator<Sales_data> out_iter(cout, "\n");
    //将第一笔交易记录存在sum中，并读取下一条记录
    Sales_data sum = *item_iter++;
    while( item_iter != eof) 
    {
        if (item_iter -> isbn() == sum.isbn())
            sum.combine(*item_iter++);
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
    std::istream_iterator<Sales_data> in_iter(std::cin), in_eof;
	std::vector<Sales_data> vec;

	while (in_iter != in_eof)
		vec.push_back(*in_iter++);
    return 0;
}