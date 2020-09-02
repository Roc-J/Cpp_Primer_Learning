#include<string>

class Book {
    public:
        Book(const std::string & bookno, const std::string & bookname, const std::string & author, double price):
            bookNo(bookno), bookName(bookname), author(author), price(price) {}

        Book(std::string & bookno): Book(bookno, "", "", 0.0) {}

        Book(std::istream &is) 
        {
            is >> bookNo >> bookName >> author >> price;
        }
            
    private:
        std::string bookNo;
        std::string bookName;
        std::string author;
        double price = 0.0;

};