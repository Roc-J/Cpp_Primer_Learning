#include<forward_list>
#include<iostream>

using namespace std;

int main()
{
    forward_list<int> iflist = {0,1,2,3,4,5,6,7,8,9};
    auto curr = iflist.begin(), prev = iflist.before_begin();
    while (curr != iflist.end())
    {
        if(*curr %2)
        {
            curr = iflist.insert_after(prev, *curr);
            ++curr;
            ++curr;
            ++prev;
            ++prev;
        }
        else
        {
            curr = iflist.erase_after(prev);
        }
    }
    for (auto &x : iflist)
    {
        cout << x << "  ";
    }
    cout << endl;
    return 0;
}