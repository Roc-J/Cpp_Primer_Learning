#include<iostream>

using namespace std;

int main()
{
    int ia[3][4] =  {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    //range for
    for (auto &row : ia)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
        
    }
    
    //for second
    for (auto i = 0; i < 3; i++)
    {
        /* code */
        for (auto j = 0; j < 4; j++)
        {
            /* code */
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
    
    //pointers
    for (auto row = ia; row != ia + 3; row++)
    {
        /* code */
        for (auto col = *row; col != *row + 4; col++)
        {
            /* code */
            cout << *col << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}