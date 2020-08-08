#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct Sales_data
{
    /* data */
    string bookNo;
    unsigned sales_count = 0;
    double revense = 0.0;
};

void test_1()
{
    cout << "input first sales_data data:" << endl;
    Sales_data item1;
    double price1;
    cin >> item1.bookNo >> item1.sales_count >> price1;
    item1.revense = price1 * item1.sales_count;
    cout << "output sales_data data is :" << endl;
    cout << item1.bookNo << " " << item1.sales_count 
         << " " << price1 << " " << item1.revense << endl;

}

void test_2()
{
    cout << "input first sales_data data:" << endl;
    Sales_data item1, item2;
    double price1, price2;
    cin >> item1.bookNo >> item1.sales_count >> price1;
    cout << "input second sales_data data:" << endl;
    cin >> item2.bookNo >> item2.sales_count >> price2;

    item1.revense = price1 * item1.sales_count;
    item2.revense = price2 * item2.sales_count;

    if (item1.bookNo == item2.bookNo)
    {
        int total_count = item1.sales_count + item2.sales_count;
        double total_revense = item1.revense + item2.revense;
        cout << "the total sales_count is : " << total_count << endl;
        cout << "the total sales_price is : " << total_revense << endl;
        if (total_count)
        {
            double avg_price = total_revense/total_count;
            cout << "avg price is : " << avg_price << endl;
        }
    }
    else
    {
        cout << "the two isbn is different!" << endl;
    }
    

}

int main()
{
    test_2();
    return 0;
}