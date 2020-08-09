#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};
    int score;
    while(cin >> score)
    {
        string gradelevel;
        if(score<60)
        {
            gradelevel = grades[0];
        }
        else
        {
            gradelevel = grades[(score - 50)/10];
            if (score%10 > 7)
            {
                gradelevel += "+";
            }
            else if (score%10 < 3)
            {
                gradelevel += "-";
            }
        }
        cout << "your score is : " << score << " your gradelevel is : " << gradelevel << endl;
        
    }
    return 0;
}