#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book
{

public:
    int year;
    string bookName;
    string name;

    Book();
    Book(int year, string bookName, string name)
    {
        this->year = year;
        this->bookName = bookName;
        this->name = name;
    };
};

int main()
{
    vector<Book> v;
    int year_;
    string bookName_;
    string name_;

    while (1)
    {
        cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;

        cout << "년도>>";
        cin >> year_;
        cin.ignore();

        if (year_ == -1)
        {
            break;
        }

        cout << "책이름>>";
        getline(cin, bookName_);

        cout << "저자>>";
        getline(cin, name_);

        Book bookInfo(year_, bookName_, name_);
        v.push_back(bookInfo);
    }

    int n = v.size();
    cout << "총 입고된 책은 " << n << "권입니다." << endl;
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";

    cin >> bookName_;
    // Book findBook(string bookName_);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->name == bookName_)
        {
            cout << it->year << "년도, " << it->bookName << ", " << it->name << endl;
        }
    }

    cout << "검색하고자 하는 년도를 입력하세요>>";

    cin >> year_;
    // Book findBook(string bookName_);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->year == year_)
        {
            cout << it->year << "년도, " << it->bookName << ", " << it->name << endl;
        }
    }
}