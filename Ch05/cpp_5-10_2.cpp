#include<iostream>

using namespace std;

int main()
{
    char ch;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0;
    while (cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
        case 'u':
        case 'U':
            ++uCnt;
        case 'o':
        case 'O':
            ++oCnt;
        default:
            ++otherCnt;
            break;
        }
        
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl;
    return 0;
}