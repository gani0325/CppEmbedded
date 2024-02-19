// 객체 배열 초기화
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
    Circle circleArray[3] = {Circle(10), Circle(20), Circle()};

    for (int i = 0; i < 3; i++)
    {
        cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
    }
}

/*
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 3.14

- 객체 배열 선언
객체 배열 선언문은 기본 생성자를 호출한다
오직 매개 변수 없는 기본 생성자 호출한다

컴파일러가 자동으로 기본 생성자를 삽입하므로, 객체 배열 생성 시 컴파일 오류가 발생하지 않는다
매개 변수가 가진 생성자가 선언되어 있는 경우, 매개 변수 생성자 호출은 문제가 없지만, 객체 배열 선언할 경우 기본 생성자가 없으므로 컴파일 오류 발생

객체 배열을 생성할 때 기본 생성자가 있는지 확인해야한다

- 객체 배열 사용
배열의 각 원소 객체는 [] 연산자로 구분한다
원소 객체와 멤버 사이에 점(.) 연산자를 사용하는 것
클래스의 포인터를 이용하여 배열을 다룰 수 있다

- 배열 소멸과 소멸자
함수가 종료되면 함수 내에 선언된 배열도 소멸된다
배열이 소멸되면 모든 원소 객체가 소멸되며 각 원소 객체마다 소멸자가 호출된다
높은 인덱스에서부터 원소 객체가 소멸되고, 각 객체마다 ~() 소멸자가 실행된다

- 객체 배열 초기화
객체 배열을 생성할 때 생성자를 사용하여 원소 객체를 초기화 할 수 있다
배열을 선언할 때 {} 안에 호출할 생성자를 지정한다
*/