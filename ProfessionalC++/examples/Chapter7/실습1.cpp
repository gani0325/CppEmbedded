#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price;
    int page;

public:
    Book(string title = "", int price = 0, int page = 0) {
        this -> title = title;
        this -> price = price;
        this -> page = page;
    }
    Book& operator += (int op2);
    Book& operator -= (int op2);
    void show();
};

void Book::show() {
    cout << title << " " << price << "원 " << page << " 페이지" << endl;
}

Book& Book::operator+=(int op2) {
    price = price + op2;
    return *this;
}

Book& Book::operator-=(int op2) {
    price = price - op2;
    return *this;
}

int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500), c;
    c = a += 300;
    c.show();
    c = b -= 500;
    c.show();
}