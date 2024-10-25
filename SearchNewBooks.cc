#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "book.h"
#include "timer.h"
using namespace std;

bool file2Vector(string, vector<Book>&);
ostream &operator<<(ostream&, vector<Book>&);
int linearSearch(vector<Book>&, vector<Book>&);
int binarySearch(vector<Book>&, Book, int, int);
int recursiveBinarySearch(vector<Book>&, Book, int, int);
bool operator<(Book&, Book&);

int main(int num, char** commands){
    string nfile;
    string rfile;
    string ffile;
    if((num < 3) || (num > 4)){
        cout << "Usage: ./SearchNewBooks <newBooks.dat> <request.dat> <result_file.dat>" << endl;
        return 0;
    }
    else if(num == 3){
        nfile = commands[1];
        rfile = commands[2];
        ffile = "found.dat";
        cout << nfile << " " << rfile << " " << ffile << endl;
    }
    else if(num == 4){
        nfile = commands[1];
        rfile = commands[2];
        ffile = commands[3];
        cout << nfile << " " << rfile << " " << ffile << endl;
    }
    vector<Book> newbooks;
    vector<Book> rbooks;
    file2Vector(nfile, newbooks);
    file2Vector(rfile, rbooks);
    int bsize = newbooks.size();
    int rsize = rbooks.size();
    int total = 0;
    cout << bsize << " books in the library, " << rsize << " books requested." << endl;
    ofstream output;

    char choice;
    cout << "Choice of search method ([l]inear, [b]inary, [r]ecursiveBinary?" << endl;
    cin >> choice;
    output.open(ffile);
    Timer ct;
    ct.Reset();
    while((choice != 'l') && (choice != 'b') && (choice != 'r')){
        cout << "Invalid choice\nChoice of search method ([l]inear, [b]inary, [r]ecursiveBinary?" << endl;
        cin >> choice;
    }
    switch(choice){
        case 'l': output << linearSearch(newbooks, rbooks) << endl;
                  break;
        case 'b': for (int k = 0; k<rsize; k++){
                      int r = binarySearch(newbooks, rbooks[k], 0, bsize);
                      if (r >= 0){
                          total++;
                      }
                  }
                  output << total << endl;
                  break;
        case 'r': for (int k = 0; k<rsize; k++){
                    int r = recursiveBinarySearch(newbooks, rbooks[k], 0, bsize);
                    if (r >= 0){
                        total++;
                    }
                  }
                  output << total << endl;
                  break;
        default: cout << "Invalid choice" << endl;
    }
    ct.CurrentTime();
    cout << endl;
    output.close();
    return 0;
}

bool file2Vector(string fname, vector<Book>& bvector){
    ifstream f;
    f.open(fname);
    string str;
    if(f){
        while(getline(f,str,',')){
            int tempISBN;
            string tempLanguage, tempType;

            tempISBN = stoi(str);
            getline(f, tempLanguage, ',');
            getline(f,tempType);

            Book newBook{tempISBN, tempLanguage, tempType};
            bvector.push_back(newBook);
        }
    }
    else{
        cout << "Error: cannot open file " << fname << endl;
        exit(EXIT_FAILURE);
        return false;
    }

    f.close();
    return true;
}

ostream &operator<<(ostream& o, vector<Book>& bvector){
    int size = bvector.size();
    if(size>0){
        for(int i=0; i<size; i++){
            o << bvector[i].getISBN() << "," << bvector[i].getLanguage() << "," << bvector[i].getType() << endl;
        }
    }
    
    return o;
}

int linearSearch(vector<Book>& bvector, vector<Book>& rvector){
    int rsize = rvector.size();
    int bsize = bvector.size();
    int total = 0;

    for(int i = 0; i < rsize; i++){
        for(int j = 0; j < bsize; j++){
            if((bvector[j].getISBN() == rvector[i].getISBN()) &&
               (bvector[j].getLanguage() == rvector[i].getLanguage()) &&
               (bvector[j].getType() == rvector[i].getType())){
                cout << "Found a book!" << endl;
                total++;
                cout << bvector[j].getISBN() << "," << bvector[j].getLanguage() << "," << bvector[j].getType() << endl;
            }
        }
    }
    return total;
}

int binarySearch(vector<Book>& bvector, Book request, int i, int j){
    sort(bvector.begin(),bvector.end());
    while(i<j){
        int m = (i+j)/2;
        if((bvector[m].getISBN() == request.getISBN()) &&
            (bvector[m].getLanguage() == request.getLanguage()) &&
            (bvector[m].getType() == request.getType())){
            cout << "Found a book!" << endl;
            cout << bvector[m].getISBN() << "," << bvector[m].getLanguage() << "," << bvector[m].getType() << endl;
            return m;
        }
        else if(bvector[m] < request){
            i = m+1;
        }
        else{
            j = m;
        }
    }
    return -1;
}

int recursiveBinarySearch(vector<Book>& bvector, Book request, int i, int j){
    sort(bvector.begin(),bvector.end());
    int m = (i+j)/2;
    if(i == j){
        if((bvector[i].getISBN() == request.getISBN()) &&
        (bvector[i].getLanguage() == request.getLanguage()) &&
        (bvector[i].getType() == request.getType())){
            return i;
        }
        else{
            return -1;
        }
    }
    else if(i<j){
        if((bvector[m].getISBN() == request.getISBN()) &&
        (bvector[m].getLanguage() == request.getLanguage()) &&
        (bvector[m].getType() == request.getType())){
            cout << "Found a book!" << endl;
            cout << bvector[m].getISBN() << "," << bvector[m].getLanguage() << "," << bvector[m].getType() << endl;
            return m;
        }
        else if(bvector[m] < request){
            return recursiveBinarySearch(bvector, request, m+1, j);
        }
        else{
            return recursiveBinarySearch(bvector, request, i, m);
        }
    }
    else{
        return -1;
    }
}

bool operator<(Book& book1, Book& book2){
    if(book1.getISBN() != book2.getISBN()){
        return book1.getISBN() < book2.getISBN();
    }
    else if(book1.getType() != book2.getType()){
        if(book1.getType() == "new"){
            return false;
        }
        else if(book2.getType() == "new"){
            return true;
        }
        else if(book2.getType() == "used"){
            return true;
        }
        
        else if(book1.getType() == "used"){
            return false;
        }
    }
    else{
        return book1.getLanguage() > book2.getLanguage();
    }
    return false;
}