#include<iostream>

using namespace std;

int main()
{
    char ch, prech ;
    unsigned aCnt = 0,eCnt = 0,iCnt = 0, oCnt =0, uCnt = 0,otherCnt = 0, spaceCnt=0, tabCnt =0, enterCnt = 0;
    unsigned ffCnt = 0, flCnt =0, fiCnt = 0;
    while (cin >> std::noskipws >> ch)
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
            if (prech == 'f') fiCnt += 1;
        case 'I':
            ++iCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++enterCnt;
            break;
        case 'f':
            if (prech == 'f') 
            {
                ffCnt += 1;
            }
            break;
        case 'l':
            if (prech == 'f')
            {
                flCnt += 1;
            }
            break;
        default:
            ++otherCnt;
            break;
        }
        //记录一下前面的字符f
        prech = ch;
    }
    cout << "numbers of a is : " << aCnt << endl
         << "numbers of e is : " << eCnt << endl
         << "numbers of i is : " << iCnt << endl
         << "numbers of o is : " << oCnt << endl
         << "numbers of u is : " << uCnt << endl
         << "numbers of other is : " << otherCnt << endl
         << "numbers of space is : " << spaceCnt << endl
         << "numbers of tab is : " << tabCnt << endl
         << "numbers of enter is : " << enterCnt << endl
         << "numbers of ff is : " << ffCnt << endl
         << "numbers of fl is : " << flCnt << endl
         << "numbers of fi is : " << fiCnt << endl;
    return 0;
}