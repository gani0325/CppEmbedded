// 참조 매개 변수를 가진 함수 만들기 연습
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

void readRadius(Circle &c)
{
    int r;
    cout << "정수 값으로 반지름을 입력하세요 >>";
    cin >> r;
    c.setRadius(r);
}

int main()
{
    Circle donut;
    readRadius(donut);
    cout << "donut 의 면적 = " << donut.getArea() << endl;
}

/*
정수 값으로 반지름을 입력하세요 >>5
donut 의 면적 = 78.5
*/