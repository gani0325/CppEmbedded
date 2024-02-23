// 값에 의한 호출 시 매개 변수의 생성자 실행되지 않음
#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius)
{
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

// 객체 c 의 생성자 실행되지 않음 + 객체 c 의 소멸자 실행됨
void increase(Circle c)
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}

int main()
{
    Circle waffle(30);
    // 생성자 호출은 안되고, 소멸자 호출은 된다
    increase(waffle);
    cout << waffle.getRadius() << endl;
}

/*
- 함수 호출 시 객체 전달
1) 값에 의한 호출 과정
함수 안에서 매개 변수 객체에 어떤 변화가 일어나도 실인자 (원본 객체) 를 훼손시키지 않는 장점
실인자 객체의 크기가 크면 객체를 복사하는 시간이 커지는 단점

객체가 함수에 전달되면, 함수의 매개 변수 객체가 생성되고, 함수가 종료하면 매개 변수 객체가 소멸된다
매개 변수 객체의 생성자와 소멸자가 모두 실행되는가? -> 아니다
객체를 매개 변수로 가지는 함수의 경우 C++ 컴파일러는 매개 변수 객체의 생성자는 실행되지 않고 소멸자만 실행되도록 컴파일 한다

컴파일러는 매개 변수 객체의 생성자가 실행되지 않도록 한다
소멸자의 경우는 다르다

매개 변수 객체의 생성자가 실행되지 ㅇ낳고 소멸자만 실행되는 비대칭 구조는, 함수 호출 시 원본 객체의 상태를 그래도 매개 변수 객체에 전달되로고 하기 위한 것

@복사 생성자
값에 의한 호출 시 컴파일러는 매개 변수 객체의 생성자 대신 복사 생성자가 호출되도록 컴파일하기 때문에 생성자가 실행되지 않는 것이다
컴파일러는 클래스에 복사 생성자가 작성되어 있지 않은 경우, 실인자 객체의 멤버 변수를 1:1로 매개 변수 객체에 복사하는 디폴트 복사 생성자를 자동으로 삽입한다
*/