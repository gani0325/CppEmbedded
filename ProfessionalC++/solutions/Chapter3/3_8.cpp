// 지역 객체와 전역 객체의 생성 및 소멸 순서
#include <iostream>
using namespace std;

class Circle
{
public:
    int radius;
    Circle();
    Circle(int r);
    ~Circle();
    double getArea();
};

Circle::Circle()
{
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r)
{
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

// 소멸자
Circle::~Circle()
{
    cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

// 전역 객체 생성
Circle globalDonut(1000);
Circle globalPizza(2000);

// 지역 객체 생성
void f()
{
    Circle fDonut(100);
    Circle fPizza(200);
}

int main()
{
    // 지역 객체 생성
    Circle mainDonut;
    Circle mainPizza(30);
    f();
}

/*
반지름 1000 원 생성
반지름 2000 원 생성
반지름 1 원 생성
반지름 30 원 생성
반지름 100 원 생성
반지름 200 원 생성
반지름 200 원 소멸
반지름 100 원 소멸
반지름 30 원 소멸
반지름 1 원 소멸
반지름 2000 원 소멸
반지름 1000 원 소멸

생성자/소멸자 실행 순서
- 함수 내에서 선언된 객체를 지역 객체
- 함수 바깥에 선언된 객체를 전역 객체

지역 객체는 함수가 실행될 때 생성되고 함수가 종료될 때 소멸되지만,
전역 객체는 프로그램이 로딩될 때 생성되고 main() 이 종료한 뒤 프로그램 메모리가 사라질 때 소멸된다
전역 객체나 지역 객체 모두 생성된 순서의 반대순으로 소멸된다
*/