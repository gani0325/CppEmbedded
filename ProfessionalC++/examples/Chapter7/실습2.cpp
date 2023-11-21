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
    bool operator == (int op2);
    bool operator == (string op2);
    bool operator == (Book op2);
};

bool Book::operator == (int op2) {
    if (this->price == op2)
        return true;
    else 
        return false;
}

bool Book::operator == (string op2) {
    if (this->title.compare(op2) == 0)
        return true;
    else 
        return false;
}

bool Book::operator == (Book op2) {
    if ((this->title.compare(op2.title) == 0) && (this->price == op2.price) && (this->page == op2.page))
        return true;
    else 
        return false;
}

int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++", 20000, 500);

    if (a == 30000) {
        cout << "정가 30000원" << endl;
    }
    if (a == "명품 C++") {
        cout << "명품 C++ 입니다." << endl;
    }
    if (a == b) {
        cout << "두 책이 같은 책입니다." << endl;
    }
}