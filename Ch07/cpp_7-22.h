#include<iostream>
#include<string>
using namespace std;

class Person
{
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);

    public:
    Person() = default;
    Person(const std::string &name, const std::string &address):name(name), address(address) {}
    Person(std::istream &is) { read(is, *this); }

    string getName() const {return this -> name;}
    string getAddress() const {return this -> address;}
    
    private:
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << "  " << person.getAddress() << endl;
    return os;
}
