#include "cpp_7-41.h"

int main()
{
    cout << "main() Sales_data()" << endl;
    Sales_data s1;

    cout << "main() Sales_data(std::string s)" << endl;
    Sales_data s2("abc-123");

    cout << "main() Sales_data(std::string s, unsigned cnt, double price)" << endl;
    Sales_data s3("abc_123", 5, 100);

    cout << "main() Sales_data(std::istream &is)" << endl;
    Sales_data s4(std::cin);
    return 0;
}