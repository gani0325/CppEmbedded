// Circle 클래스의 배열 선언 및 활용
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    // Circle 객체 배열 생성
    Circle circleArray[3];

    // 배열의 각 원소 객체의 멤버 접근
    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    // 배열의 각 원소 객체의 멤버 접근
    for (int i = 0; i < 3; i++)
    {
        cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
    }

    Circle *p;
    p = circleArray;
    // 객체 포인터로 배열 접근
    for (int i = 0; i < 3; i++)
    {
        cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
        // 배열의 다음 원소
        p++;
    }
}

/*
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 2826
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 2826

- 객체 배열
객체 배열은 원소가 객체
int, char 등 기본 타입의 배열을 선언하고 활용하는 방법
*/