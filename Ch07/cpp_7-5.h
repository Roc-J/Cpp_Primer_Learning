#include<iostream>
using namespace std;

struct Person
{
    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    std::string name;
    std::string address;
};