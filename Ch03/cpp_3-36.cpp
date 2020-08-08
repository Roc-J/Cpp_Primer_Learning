#include<iostream>
#include<vector>

using namespace std;

void compare_arr()
{
    int a[] = {2,5,2};
    int b[] = {2,9};
    int *p_beg = begin(a), *p_end = end(a);
    int *q_beg = begin(b), *q_end = end(b);
    if ((p_end - p_beg) != (q_end - q_beg))
    {
        cout << "array a is different b." << endl;
    }
    else
    {
        for (int *i=p_beg,*j=q_beg; i!=p_end && j!=q_end; i++,j++)
        {
            if ((*i) != (*j))
                cout << "array a is different b." << endl;
        }
        cout << "array a is same to b." << endl;
    }

    
}

int main()
{
    //两个数组大小一样了
    const int size = 10;
    int a[size], b[size];
    for(size_t i=0;i<size;i++)
        a[i] = i;
    for(size_t i=0;i<size;i++)
        b[i] = i+1;
    //compare
    int *p=a,*q=b;
    int flag = 0;
    for(int i=0;i<size; i++)
    {
        if (*p != *q)
        {
            cout << "array a is different b." << endl;
            flag = 1;
            break;
        }
        p++;
        q++;
    }
    if (!flag)
        cout << "a is same to b." << endl;

    //vector
    vector<int> v1 = {2,1,4};
    vector<int> v2 = {2,1,4};
    if (v1 == v2)
    {
        cout << "vector v1 equal v2" << endl;
    }
    else
    {
        cout << "vector v1 is different v2" << endl;
    }
    
    //
    compare_arr();
    return 0;
}