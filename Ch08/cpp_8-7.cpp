#include<fstream>
#include "../Ch07/cpp_7-26.h"

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream out(argv[2], ofstream::app);
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
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cout << "No data?!" << endl;
    }
    return 0;
}