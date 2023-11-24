#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    int price;
    int page;

public:
    Book(string title = "", int price = 0, int page = 0)
    {
        this->title = title;
        this->price = price;
        this->page = page;
    }
    string getTitie();
    friend bool operator<(string ob2, Book ob1);
};

string Book::getTitie()
{
    return title;
}

bool operator<(string ob2, Book ob1)
{
    if (ob2.compare(ob1.title) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Book a("청춘", 20000, 300);
    string b;
    cout << "책 이름을 입력하세요>>";
    getline(cin, b);

    if (b < a)
    {
        // 앞에 것이 크면 1, 뒤에 것이 크면 -1
        cout << a.getTitie() << "이 " << b << "보다 뒤에 있구나!" << endl;
    }
}