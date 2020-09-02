#include<string>

class Book {
    public:
        Book() = default;
        Book(const std::string & bookno, const std::string & bookname,const std::string & author, double price):
            bookNo(bookno), bookName(bookname), author(author), price(price) {}
            
    private:
        std::string bookNo;
        std::string bookName;
        std::string author;
        double price = 0.0;

};