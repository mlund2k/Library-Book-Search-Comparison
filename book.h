#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        int ISBN;
        string language;
        string type;
    public:
        int getISBN(); // returns book's ISBN number
        string getLanguage(); // returns language of book
        string getType(); // returns type of book
        Book(); // default constructor
        Book(int,string,string); // constructor with arguments
};

#endif