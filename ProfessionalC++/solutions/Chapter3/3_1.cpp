// Circle 클래스이 객체 생성 및 활용
#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    // 객체 생성
    Circle donut;
    // 멤버 변수
    donut.radius = 1;
    // 멤버 함수
    double area = donut.getArea();
    cout << "dount 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
}

/*
11:53:03 gani@LOVELY-GANI Chapter3 ±|master ✗|→ g++ -o 3_1 3_1.cpp
11:53:21 gani@LOVELY-GANI Chapter3 ±|master ✗|→ ./3_1
dount 면적은 3.14
pizza 면적은 2826
*/