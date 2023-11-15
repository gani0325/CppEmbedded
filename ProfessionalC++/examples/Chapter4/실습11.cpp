#include <iostream>
#include <string>
using namespace std;

class CoffeeVendingMachine {
    // 커피 자판기
    Container tong[3];          // tong[0] : 커피, tong[1] : 물, tong[2] : 설탕통
    void fill();                // 3개의 통을 모두 10으로 채움
    void selectEspresso();      // 커피 1, 물 1 소모
    void selectAmerican();      // 커피 1, 물 2 소모
    void selectSugarCoffee();   // 커피 1, 물 2, 설탕 1 소모
    void show();                // 현재 커피, 물, 설탕 잔량 출력
public:
    void run(); // 커피 자판기 작동
};

void CoffeeVendingMachine::fill() {
    tong[0].fill();
    tong[1].fill();
    tong[2].fill();
}

void CoffeeVendingMachine::selectEspresso() {
    tong[0].consume();
    tong[1].consume();

    if (tong[0].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else if (tong[1].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else {
        cout << "에스프레소 드세요" << endl;
    }
}

void CoffeeVendingMachine::selectAmerican() {
    tong[0].consume();
    tong[1].consume();
    tong[1].consume();

    if (tong[0].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else if (tong[1].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else {
        cout << "아메리카노 드세요" << endl;
    }
}

void CoffeeVendingMachine::selectSugarCoffee() {
    tong[0].consume();
    tong[1].consume();
    tong[1].consume();
    tong[2].consume();

    if (tong[0].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else if (tong[1].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else if (tong[2].getSzie() <= 0) {
        cout << "원료가 부족합니다." << endl;
    }
    else {
        cout << "설탕커피 드세요" << endl;
    }
}

void CoffeeVendingMachine::show() {
    cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << " , 설탕 " << tong[2].getSize() << endl; 
}

void CoffeeVendingMachine::run() {
    cout << "***** 커피자판기를 작동합니다. *****" << endl;
    cout << "메뉴를 눌러주세요 (1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";

    int menu;
    cin >> menu;
    
    // 커피, 물, 설탕통
    tong[3] = {Container(), Container(), Container()};
    
    if (menu == 1) {
        // 커피 1, 물 1 소모
        selectEspresso();
    }
    else if (menu == 2) {
        // 커피 1, 물 2 소모
        selectAmerican();
    }
    else if (menu == 3) {
        // 커피 1, 물 2, 설탕 1 소모
        selectSugarCoffee();
    }
    else if (menu == 4) {
        // 잔량보기
        show();
    }
    else if (menu == 5) {
        // 채우기
        fill();
    }
}

class Container {
    // 통 하나를 나타내는 클래스
    int size;           // 현재 저장량, 최대 저장량은 10
public:
    Container() {size = 10;}
    void fill();        // 최대량 (10) 으로 채우기
    void consume();     // 1 만큼 소모하기
    int getSize();      // 현재 크기 리턴
};

void Container::fill() {
    size = 10;
}

void Container::consume() {
    size -= 1;
}

int Container::getSize() {
    return size;
}

int main() {
    while(1) {
        CoffeeVendingMachine run();
    }
}