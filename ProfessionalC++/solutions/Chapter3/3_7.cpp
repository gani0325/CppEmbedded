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

int main()
{
    Circle donut;
    Circle pizza(30);
    return 0;
}

/*
반지름 1 원 생성
반지름 30 원 생성
반지름 30 원 소멸
반지름 1 원 소멸

소멸자(destructor)
- 객체가 소멸되는 시점에서 자동으로 호출되는 클래스의 멤버 함수
- 소멸자의 목적은 객체가 사라질 때 필요한 마무리 작업을 위함(메모리 운영체제에 돌리거나 파일 저장 닫기, 네트워크 해제)
- 생성된 반대순으로 객체가 소멸된다
- 소멸자의 이름은 클래스 이름 앞에 ~을 붙인다
- 소멸자는 리턴 타입이 없으며 어떤 값도 리턴해서는 안된다
- 소멸자는 오직 한 개만 존재하며 매개변수를 가지지 않는다
- 소멸자가 선언되어 있지 않으면 기본 소멸자가 자동으로 생성된다
*/