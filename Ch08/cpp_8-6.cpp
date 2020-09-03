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