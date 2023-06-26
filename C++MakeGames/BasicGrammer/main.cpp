// #include : 헤더 파일을 여기에 포함시키는 기능
#include <iostream>
using namespace std;
// 실행 과정 : 컴파일(번역 작업) -> 빌드 -> 실행

// 시작점은 main 함수
int main() {
	// std 라는 namespace -> 이름 겹치는거 방지
	// cout : 콘솔창에 출력
	// endl : 개행 기능
	std::cout << "hi" << std:endl;

	/*
	변수 : 변하는 수, 값이 바뀔 수 있음
	용량의 최소단위 : bit
	1byte = 8bit
	1kbyte = 1024byte
	1mbyte = 1024kbyte
	1gbyte = 1024mbyte
	1tbyte = 1024gbyte

	문자를 표현하는 방법 : ASCII 코드 
	false : 0
	true : 0 이 아닌 모든 수
	unsigned : 부호가 없음

	종류	|	용량	|	데이터	|	표현범위	|	unsigned
	char		1byte		문자		-128 ~ 127		0 ~ 255
	bool		1byte		참/거짓		true/false		true/false
	short		2byte		정수		-32768 ~ 32767	0 ~ 65535
	int			4byte		정수		-22억 ~ 21억	0 ~ 약 43억
	float		4byte		실수		
	double		8byte		실수

	= : 대입연산자, 오른쪽 있는 값을 왼쪽으로 대입함

	영문이나 숫자는 1byte 차지
	한글이나 한문 등 문자들은 2byte 를 차지하므로 char 변수 하나에 저장 x
	*/
	float fNumber = 3.25f;
	cout << fNumber << endl;

	double dNumber = 123.4567;
	cout << dNumber << endl;

	return 0;
}
