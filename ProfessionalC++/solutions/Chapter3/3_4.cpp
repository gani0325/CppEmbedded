// 생성자에서 다른 생성자 호출 연습 (위임 생성자 만들기)
#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    // 위임 생성자
    Circle();
    // 타겟 생성자
    Circle(int r);
    double getArea();
};

// 위임 생성자 (delegating constructor) : 생성자가 다른 생성자 호출
// 중복된 초기화 코드를 하나의 생성자로 몰고, 다른 생성자에게 이 생성자를 호출하게 함
Circle::Circle() : Circle(1) {}

// 타겟 생성자 : 객체 초기화를 전담시킴으로써 객체의 생성 과정이 명료해지고 단순해짐
Circle::Circle(int r)
{
    // 반지름 값 초기화
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
}

/*
객체 초기화를 전담하는 타겟 생성자와 타겟 생성자에 객체 초기화를 위임하는 위임 생성자

반지름 1 원 생성
donut 면적은 3.14
반지름 30 원 생성
pizza 면적은 2826
*/