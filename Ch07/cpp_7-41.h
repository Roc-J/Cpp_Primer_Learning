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