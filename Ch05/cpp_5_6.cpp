#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    const vector<string> grades = {"F", "D", "C", "B", "A", "A++"};
    int score;
    while(cin >> score && (score <=100) && (score >=0))
    {
        string gradelevel;
        score < 60?gradelevel = grades[0]:gradelevel = grades[(score - 50)/10],(score%10 > 7)?gradelevel += "+":(score%10 < 3)?gradelevel += "-":"";
        cout << "your score is : " << score << " your gradelevel is : " << gradelevel << endl;
        
    }
    return 0;
}