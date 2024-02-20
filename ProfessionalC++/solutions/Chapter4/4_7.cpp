// Circle 객체의 동적 생성 및 반환
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r)
{
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main()
{
    Circle *p, *q;
    p = new Circle();
    q = new Circle(30);

    cout << p->getArea() << endl
         << q->getArea() << endl;

    // 생성한 순서에 관계 없이 원하는 순서대로 delete 가능
    delete p;
    delete q;
}

/*
생성자 실행 radius = 1
생성자 실행 radius = 30
3.14
2826
소멸자 실행 radius = 1
소멸자 실행 radius = 30

- 객체와 객체 배열의 동적 생성 및 반환
- new 를 이용한 객체의 동적 생성과 생성자
클래스 *포인터변수 = new 클래스이름; // 기본 생성자 호출
클래스 *포인터변수 = new 클래스이름(생성자 매개변수리스트);

new 는 클래스 크기의 메모리 할당받아 객체를 생성하며, 생성자를 호출한다

- delete 를 이용한 객체 반환과 소멸자
동적으로 생성된 객체는 객체에 대한 '포인터변수'를 이용하여 반환한다
delete 포인터변수;

delete 사용 시 '포인터변수'는 반드시 new를 이용하여 동적 할당받은 메모리의 주소여야 한다
delete 를 실행되면, 객체를 반환하기 직전에 객체의 소멸자가 실행된다
*/
