// 객체 리턴
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

Circle getCircle()
{
    Circle tmp(30);
    // tmp 객체의 복사본 리턴
    return tmp;
}

int main()
{
    // 객체가 생성됨  -> radius = 1 로 초기화된다
    Circle c;
    cout << c.getArea() << endl;

    c = getCircle();
    cout << c.getArea() << endl;
}

/*
3.14
2826
*/

/*
- 객체 치환 및 객체 리턴
객체 치환 : 객체의 모든 데이터가 비트 단위로 복사된다

- 함수의 객체 리턴
return 문이 실행되면 복사본이 생기고 함수를 호출한 곳으로 전달된다
*/