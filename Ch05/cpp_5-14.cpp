#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string curstr,s,maxS;
    cin >> curstr;
    int sCnt = 0, maxCnt = 0;
    if (!curstr.empty())
    {
        sCnt = 1;
        maxCnt = 1;
        maxS = curstr;
    }
    while (cin >> s)
    {
        if ( s == curstr)
        {
            sCnt += 1;
        }
        else
        {
            if (maxCnt<sCnt)
            {
                maxCnt = sCnt;
                maxS = curstr;
            }
            curstr = s;
            sCnt = 1;
        }
        
    }
    if (maxCnt<sCnt)
    {
        maxCnt = sCnt;
        maxS = s;
    }
    if (maxCnt == 1)
    {
        cout << "No word has ever appeared in succession." << endl;
    }
    else
    {
        cout << maxS << " output " << maxCnt << endl;
    }
    return 0;
}