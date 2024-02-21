// string 클래스를 이용한 문자열 생성 및 출력
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 스트링 생성
    string str;
    string address("경기도 시흥시");
    string copyAdress(address);

    char text[] = {'L', 'O', 'V', 'E', '\0'};
    string title(text);

    // 스트링 출력
    cout << str << endl;
    cout << address << endl;
    cout << copyAdress << endl;
    cout << title << endl;
}

/*
경기도 시흥시
경기도 시흥시
LOVE

- this 는 객체 자신에 대한 포인터
클래스의 멤버 함수 내에서만 사용된다
this 는 전역 변수도 아니고 함수 내에 선언된 지역 변수도 아니다
this 는 객체의 멤버 함수가 호출될 때, 컴파일러에 의해 보이지 않게 전달되는 객체에 대한 주소이다

- this 와 객체
this 는 객체 자신에 대한 포인터
생성자 함수의 경우 this-> 는 생략 가능

this 의 필요한 경우
1) 멤버 변수의 이름과 동일한 이름으로 매개 변수 이름을 짓고자 하는 경우
매개 변수의 이름은 소스 프로그램의 강력한 주석 역할이다

2) 객체의 멤버 함수에서 객체 자신의 주소를 리턴할 때 필요하다
연산자 중복을 구현할 때, 많이 발생한다

- this 의 제약 조건
this 는 클래스의 멤버 함수에서만 사용할 수 있다
멤버 함수라도 정적 멤버 함수는 this 를 사용할 수 없다
정적 멤버 함수는 객체가 생성되기 전에 호출될 수 있으며, 정적 멤버 함수가 실행되는 시점에서 현재 객체는 존재하지 않을 수 있기 때문이다

- 컴파일러는 this 를 어떻게 처리하는가
this 는 컴파일러에 의해 탄생하는 변수이다
this 는 컴파일러에 의해 묵시적으로 삽입된 매개 변수이다
컴파일러는 객체의 멤버 함수를 호출하는 문장을 변환하여, 해당 객체의 주소가 매개 변수로 전달되도록 만든다

- string 클래스를 이용한 문자열 사용
1) C-스트링
'\0' 로 끝나는 문자 배열을 문자열로 취급하는 방법
초기에 할당받은 메모리 크기 이상의 문자열을 저장할 수 없기 때문에 어려움이 있음

2) string
C++ 표준 라이브러리에서 제공하는 클래스
문자열을 저장하는 버퍼와 함께, 문자열을 다루는 함수와 연산자들을 멤버로 가지고 있음
문자열의 크기에 맞추어 스스로 메모리 크기를 조절하므로 편리하다
str 에 저장되는 문자열의 크기를 염려하지 않아도 된다

- string 객체 생성 및 출력
string str;
string address("경기도 시흥시");
string copyAddress(address);

- string 객체가 가진 문자열 출력
cout << str;

- string 객체의 동적 생성
new 와 delete 연산자를 이용하여 동적으로 생성하고 반환할 수 있다
string *p = new string("C++");
p->append("great");
delete p;




*/