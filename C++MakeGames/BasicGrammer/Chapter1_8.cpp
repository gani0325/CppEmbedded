// Chapter1_8

#include <iostream>
using namespace std;

/*
열거체 : 연속된 숫자에 이름 부여하는 기능
enum 열거체명 {}
열거체명 이용해서 열거체 타입의 변수 선언 가능
즉, 열거체 자체가 사용자 정의 변수 타입 될 수 있음
열거체는 숫자에 이름을 붙여주는 기능
*/
enum NUM
{
	NUM_0,	// 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값 부여
	NUM_1,
	NUM_2,
	NUM_3,
};

#define NUM_4	4

int main()
{
	/*
	- switch 문 : 분기문의 한 종류
	값이 뭔지를 체크하는 분기문
	switch(변수) {} 코드블럭
	코드 블럭 안에는 case break 구문이 들어감
	case 상수 : 의 형태로 처리가 됨
	변수값이 무엇인지에 따라 case 뒤에 오는 상수 비교
	*/
	int iNumber;
	cout << "숫자 입력 : ";
	cin >> iNumber;

	switch (iNumber) {
	case NUM_1:		// iNumber 값이 무엇인가에 따라 실행되는 case 구문 결정
		cout << "입력한 숫자는 1" << endl;
		break;	// break 만나면 switch 문 빠져나간다
	case NUM_2:
		cout << "입력한 숫자는 2" << endl;
		// break 없을 경우, 바로 아래 있는 case 구문 강제 실행
	case NUM_3:
		cout << "입력한 숫자는 3" << endl;
		break;
	case NUM_4:
		cout << "입력한 숫자는 4" << endl;
		break;
	default:	// case 로 지정하지 않은 경우 실행된다
		cout << "그 외 숫자입니당" << endl;
		break;
	}

	// 열거체 타입의 변수 선언 (무조건 4btye 차지)
	// 열거체를 이용해서 선언한 변수는 값의 표현 범위가 열거체에 나열된 값들 안에서 선택 사용
	NUM		eNum = (NUM)10;

	// sizeof(타입 or 변수) 를 하게 되면 해당 타입 혹은 변수의 메모리 크기를 구해줌
	cout << sizeof(NUM) << endl;
	// typeid(타입 or 변수).name() typeid 안에 들어간 타입 혹은 변수의 타입을 문자열로 반환해줌
	cout << typeid(eNum).name() << endl;
	cout << eNum << endl;
	return 0;
}