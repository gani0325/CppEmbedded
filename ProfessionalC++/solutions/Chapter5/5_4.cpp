// 객체에 대한 참조
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

int main()
{
    Circle circle;
    // circle 객체에 대한 참조 변수 refc 선언
    Circle &refc = circle;
    refc.setRadius(10);
    // 두 호출은 동일 객체에 대한 호출
    cout << refc.getArea() << " " << circle.getArea();
}

// 314 314