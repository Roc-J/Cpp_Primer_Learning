#include<iostream>
#include<string>

using namespace std;

class MyDate
{
private:
    unsigned year;
    unsigned month;
    unsigned day;
public:
    MyDate();
    MyDate(const string &date);
    void print();
private:
    void init_1(const string &date);
    void init_2(const string &date);
    void init_3(const string &date);
    void process_month(const string &s);
};

MyDate::MyDate(const string &date)
{
    if(date.find_first_of("/") != string::npos)
    {
        init_1(date);
    }
    else if (date.find_first_of(",") != string::npos )
    {
        init_2(date);
    }
    else
    {
        init_3(date);
    }
}

void MyDate::print()
{
    cout << "day: " << day << " " << "month: " << month << " " << "year: " << year << endl;
}

void MyDate::init_1(const string &date)
{
    auto first = date.find_first_of("/"), last = date.find_last_of("/");
    month = stoi(date.substr(0,first));
    day = stoi(date.substr(first+1, last-first));
    year = stoi(date.substr(last+1, 4));
}

void MyDate::init_2(const string &date)
{
    auto first = date.find_first_of(",");
    auto prex = date.substr(0,first);
    process_month(prex);
    day = stoi(prex.substr(prex.find_first_of("123456789")));
    year = stoi(date.substr(first+1, 4));
}

void MyDate::init_3(const string &date)
{
    auto first = date.find_first_of("123456789"), last = date.find_last_of(" ");
    auto prex = date.substr(0,first);
    process_month(prex);
    day = stoi(date.substr(first, last-first));
    year = stoi(date.substr(last+1, 4));
}

void MyDate::process_month(const string &s)
{
    if (s.find("Jan") < s.size())  month = 1;
	if (s.find("Feb") < s.size())  month = 2;
	if (s.find("Mar") < s.size())  month = 3;
	if (s.find("Apr") < s.size())  month = 4;
	if (s.find("May") < s.size())  month = 5;
	if (s.find("Jun") < s.size())  month = 6;
	if (s.find("Jul") < s.size())  month = 7;
	if (s.find("Aug") < s.size())  month = 8;
	if (s.find("Sep") < s.size())  month = 9;
	if (s.find("Oct") < s.size())  month = 10;
	if (s.find("Nov") < s.size())  month = 11;
	if (s.find("Dec") < s.size())  month = 12;
}


//January 1,1900、1/1/1990、Jan 1 1900
int main()
{
    MyDate mdate("1/1/1990"),mdate2("January 1,1900"),mdate3("Jan 1 1900");
    mdate.print();
    mdate2.print();
    mdate3.print();
    return 0;
}