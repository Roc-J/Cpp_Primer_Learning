#include<iostream>
#include<string>
using namespace std;

class Account
{
public:
    void calculate() { amount += amount * interestRate;}
    static double rate() {return interestRate;}
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
}