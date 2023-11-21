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
    bool operator ! ();
};

bool Book::operator ! () {
    if (this->price == 0) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    Book book("벼룩시장", 0, 50);

    if (!book) {
        cout << "공짜다" << endl;
    }
}