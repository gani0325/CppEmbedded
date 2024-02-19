// 객체 포인터 선언 및 활용
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    Circle donut;
    Circle pizza(30);

    // 객체 이름으로 멤버 접근
    cout << donut.getArea() << endl;

    // 객체 포인터로 멤버 접근
    Circle *p;
    p = &donut;

    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;

    p = &pizza;
    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;
}

/*
3.14
3.14
3.14
2826
2826

- 객체 포인터
객체의 멤버 함수를 읽고 값을 쓰거나 멤버 함수를 호출할 수 있다
- 객체에 대한 포인터 변수 선언
Circle *p;
- 포인터 변수에 객체 주소 지정
객체의 주소는 객체 이름 앞에 & 연산자를 사용하여 표현한다
p = &donut;
- 포인터를 이용한 객체 멤버 접근
객체 이름으로 멤버를 접근할 때 점(.) 연산자를 이용한다
d = donut.getArea();
객체 포인터로 멤버를 접근할 때 -> 연산자를 이용한다
d = p -> getArea();
d = (*p).getArea();
*/