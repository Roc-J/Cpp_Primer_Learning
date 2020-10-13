#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        return -1;
    }
    ifstream ifile(argv[1]);
    ofstream of_odd(argv[2]), of_even(argv[3]);

    istream_iterator<int> in_(ifile), in_eof;
    ostream_iterator<int> out_odd(of_odd, " "), out_even(of_even, "\n");

    for_each(in_, in_eof, [&out_odd, &out_even] (const int i) {
        *(i%2==0?out_odd:out_even)++ = i;
    });

    return 0;
}