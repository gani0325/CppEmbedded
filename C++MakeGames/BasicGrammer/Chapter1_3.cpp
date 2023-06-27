// Chapter1_3

#include <iostream>
using namespace std;

int main()
{
	/*
	사칙 연산자 : +, -, *, /, % (나머지 연산자)
	관계 연산자 : >, >=, <, <=, ==, != (값 대 값을 연산하여 참/거짓으로 결과 반환)
	*/
	cout << "10 < 20 " << (10 < 20) << endl;
	cout << "40 < 20 " << (40 < 20) << endl;

	/*
	논리 연산자 : 참/거짓 대 참/거짓 연산하여 참/거짓으로 결과 반환
	AND(&&), OR(||), NOT(!)
	A	B	AND	OR
	0	0	0	0
	1	0	0	1
	0	1	0	1
	1	1	1	1
	
	A	NOT
	1	0
	0	1
	*/
	int Number;
	cout << "숫자 입력하세용 : ";
	cin >> Number;

	cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;
		
	return 0;
}