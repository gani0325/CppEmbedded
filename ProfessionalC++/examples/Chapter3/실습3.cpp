#include <iostream>
using namespace std;

class Account {
    int id;
    int balance;
    string name;

public:
    Account(string name, int id, int balance);

    void deposit(int r);
    string getOwner();
    int inquiry();
    int withdraw(int w);
};

Account::Account(string n, int i, int b) {
    name = n;
    id = i;
    balance = b;
}

// 저금하기
void Account::deposit(int r) {
    balance += r;
}

// 계좌 주인
string Account::getOwner() {
    return name;
}

// 잔액
int Account::inquiry() {
    return balance;
}

int Account::withdraw(int w) {
    balance -= w;
    return balance;
}

int main() {
    Account a("kitae", 1, 5000);
    a.deposit(50000);

    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
    int money = a.withdraw(20000);

    cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}