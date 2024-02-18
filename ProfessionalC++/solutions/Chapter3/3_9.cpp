// 컴파일 오류가 발생하는 곳 (생성자를 public으로 해야한다!)
#include <iostream>
using namespace std;

class PrivateAccessError
{
private:
    int a;
    void f();
    PrivateAccessError();

public:
    int b;
    PrivateAccessError(int x);
    void g();
};

PrivateAccessError::PrivateAccessError()
{
    a = 1;
    b = 1;
}

PrivateAccessError::PrivateAccessError(int x)
{
    a = x;
    b = x;
}

void PrivateAccessError::f()
{
    a = 5;
    b = 5;
}

void PrivateAccessError::g()
{
    a = 6;
    b = 6;
}

int main()
{
    // PrivateAccessError()는 private 이므로 main() 에서 호출할 수 없음!!!!
    PrivateAccessError objA;
    PrivateAccessError objB(100);
    // a는 PrivateAccessError 클래스의 private 멤버이므로 main() 에서 호출할 수 없음!!!!
    objB.a = 10;
    objB.b = 20;
    // f() 는 PrivateAccessError 클래스의 private 멤버이므로 main() 에서 호출할 수 없음!!!!
    objB.f();
    objB.g();
}

/*
- 접근 지정자
객체를 캡슐화하고, 외부에서 접근 가능한 공개 멤버와 외부의 접근을 허용하지 않는 비공개 멤버를 구분한다
디폴트 접근 지정은 private (캡슐화의 기본 원칙이 비공개이기 때문)

- private 멤버
클래스 내의 멤버 함수들에게만 접근이 허용하지
- public 멤버
클래스 내외를 막론하고 프로그램의 모든 함수들에게 접근이 허용
- protected 멤버
클래스 내의 멤버 함수와 이 클래스를 상속받은 파생 클래스의 멤버 함수에게만 접근이 허용됨

- 멤버 보호와 생성자
멤버 변수는 private로 지정하는 것이 바람직함
클래스 외부에서 객체를 생성하기 위해서는 생성자는 public으로 선언해야 한다 (그렇지 않으면 컴파일 오류)
BUT, 외부에서 객체를 생성할 수 없도록 생성자를 private 으로 선언하기도 하고,
자식 클래스에서만 생성자를 호출하도록 protected 로 선언하기도 한다
*/