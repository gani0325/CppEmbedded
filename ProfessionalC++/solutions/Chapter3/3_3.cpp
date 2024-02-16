// 2개의 생성자를 가진 Circle 클래스
#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    // 기본 생성자
    Circle();
    Circle(int r);
    double getArea();
};

Circle::Circle()
{
    // 반지름 값 초기화
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

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
생성자 : 클래스는 객체가 생성될 때 자동으로 실행되는 생성자 라는 특별한 멤버 함수를 통해 객체를 초기화
한 클래스에 여러 개의 생성자를 둘 수 있으나, 이중 하나만 실행된다
생성자 함수의 이름은 클래스 이름과 동일하게 작성
생성자 함수의 원형에 리턴 타입 선언 X
생성자는 중복 가능함 (매개 변수 개수나 타입은 다르게)

반지름 1 원 생성
donut 면적은 3.14
반지름 30 원 생성
pizza 면적은 2826
*/