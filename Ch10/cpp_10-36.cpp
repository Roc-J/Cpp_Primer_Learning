#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main()
{ 
    list<int> ilst = {0,1,2,3,0,4,5,6,7,0,8,9};
    auto it = find(ilst.crbegin(), ilst.crend(), 0);
    cout << *it << endl;
    auto beg = it.base();
    while (beg != ilst.cend())
    {
        /* code */
        cout << *beg++ << " ";
    }
    
    return 0;
}