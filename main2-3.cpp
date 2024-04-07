#include <iostream>
#include <string> 
//----------------------------------------------------------------------------------------------------
class Date {
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}


    const Date& getNewer(const Date& other) const {
        if (year > other.year)
            return *this;
        else if (year < other.year)
            return other;
        else {
            if (month > other.month)
                return *this;
            else if (month < other.month)
                return other;
            else {
                if (day > other.day)
                    return *this;
                else
                    return other;
            }
        }
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};
//----------------------------------------------------------------------------------------------------
class Book {
    std::string author;
    std::string title;
    int year;
    int pageCount;

public:
    Book(const std::string& a, const std::string& t, int y, int pc)
        : author(a), title(t), year(y), pageCount(pc) {}

    Book(const Book& other)
        : author(other.author), title(other.title), year(other.year), pageCount(other.pageCount) {}

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Page Count: " << pageCount << std::endl;
    }
};
//----------------------------------------------------------------------------------------------------
int main() {
    // Testing Date class
    Date date1(7, 4, 2022);
    Date date2(12, 8, 2023);
    const Date& newerDate = date1.getNewer(date2);
    std::cout << "Newer Date: ";
    newerDate.display();
    //----------------------------------------------------------------------------------------------------
    // Testing Book class
    Book book1("John Doe", "Sample Book", 2020, 300);
    Book book2 = book1;
    book2.display();

    return 0;
}
