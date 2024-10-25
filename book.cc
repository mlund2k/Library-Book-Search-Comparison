#include "book.h"

int Book::getISBN(){
    return this->ISBN;
}

string Book::getLanguage(){
    return this->language;
}

string Book::getType(){
    return this->type;
}

Book::Book(){}

Book::Book(int ISBN,string language,string type){
    this->ISBN = ISBN;
    this->language = language;
    this->type = type;
}