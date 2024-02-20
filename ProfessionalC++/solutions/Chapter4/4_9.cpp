// Circle 배열의 동적 생성 및 반환
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
    // 객체 배열의 동적 생성
    Circle *pArray = new Circle[3];

    pArray[0].setRadius(10);
    pArray[1].setRadius(20);
    pArray[2].setRadius(30);

    for (int i = 0; i < 3; i++)
    {
        cout << pArray[i].getArea() << endl;
    }

    // 포인터 p에 배열의 주소값 설정
    Circle *p = pArray;
    for (int i = 0; i < 3; i++)
    {
        cout << p->getArea() << endl;
        // 다음 원소의 주소 증가
        p++;
    }

    // 각 객체의 소멸자 ~Circle() 실행
    // 객체 배열 반환
    delete[] pArray;
}

/*
생성자 실행 radius = 1
생성자 실행 radius = 1
생성자 실행 radius = 1
314
1256
2826
314
1256
2826
소멸자 실행 radius = 30
소멸자 실행 radius = 20
소멸자 실행 radius = 10

- 객체 배열의 동적 생성 및 반환
객체 배열의 동적 생성과 생성자
클래스이름 *포인터변수 = new 클래스이름 [배열 크기];

new 를 이용하여 동적으로 배열을 생성할 때, 매개 변수 있는 생성자를 직접 호출할 수는 없다
배열을 각 원소 객체로는 초기화할 수 있다

- 객체 배열의 사용
동적으로 생성된 객체 배열은 객체 배열처럼 사용된다

- 배열의 반환과 소멸자
delete 연산자를 이용하여 동적으로 할당받은 배열을 반환하는 형식
delete [] 포인터변수;

delete는 배열을 반환하기 직전, 배열의 각 원소 객체의 소멸자를 진행한다
소멸자의 실행 순서는 생성의 반대 순서이다

- 동적으로 할당받은 메모리는 반드시 반환해야 하는가?
힙 heap 은 프로그램이 실행 중에 new 를 이용하여 동적으로 할당받아 사용할 수 있는 메모리
대부분 운영체제에서 프로그램마다 힙이 따로 주어지기 때문에, 한 프로그램이 동적으로 많은 메모리를 할당받는 것이 다른 프로그램 힙에 영향 주지 않는다
다만, 필요없게 된 메모리를 반환하지 않거나 메모리 누구사 생기면, 힙에 메모리가 부족하여 할당 받을 수 없다

프로그램 종료 시, 힙 전체가 운영체제에 의해 반환되므로 누수 메모리에 대한 걱정은 안해도 된다

- 동적으로 할당받은 메모리 누수
메모리의 주소를 잃어버려 힙에 반환할 수 없게 되면 메모리 누수가 발생한다
프로그램이 종료되면 누수 메모리는 모두 시스템 힙으로 자동 반환된다
*/
