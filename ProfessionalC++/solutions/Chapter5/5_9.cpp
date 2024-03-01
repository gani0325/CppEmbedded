// Circle 클래스의 복사 생성자의 객체 복사
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    // 복사 생성자 선언
    Circle(const Circle &c);

    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

// 복사 생성자 구현
Circle::Circle(const Circle &c)
{
    this->radius = c.radius;
    cout << "복사 생성자 실행 radius = " << radius << endl;
}

int main()
{
    // src 객체의 보통 생성자 호출
    Circle src(30);
    // dest 객체의 복사 생성자 호출
    Circle dest(src);

    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;
}

/*
복사 생성자 실행 radius = 30
원본의 면적 = 2826
사본의 면적 = 2826
*/