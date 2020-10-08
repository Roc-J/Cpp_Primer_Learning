#include<iostream>
#include<vector>

using namespace std;

void printInfo(vector<int> &vec)
{
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
}

int main()
{
    vector<int> ivec;
    printInfo(ivec);

    for (vector<int>::size_type i = 0; i <= 100; ++i)
    {
        ivec.push_back(i);
        printInfo(ivec);
    }
    
    return 0;
}