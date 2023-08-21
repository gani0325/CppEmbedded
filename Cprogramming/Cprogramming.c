// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

// #1. Hello world
//int main()
//{
//    printf("Hello World!\n");
//}

// #2. 상수와 자료형
void main()
{	
	// 문자 상수
	char ch = 'A';

	// 정수 상수
	int x = 1;
	int y = -1;
	char ch2 = '1';

	// 실수 상수
	double dblData = 123.45;
	float flData = 123.45f;

	// sizeof : 피연산자를 저장하는 데 필요한 메모리의 크기를 바이트 단위로 계산
	printf("%d \n", sizeof(dblData));
	printf("%d \n", sizeof(flData));

	// 문자열 상수
	char* pszData = "ABC";		// * :  주소가 저장되는 포인터 변수
	char ch3 = 'A';		// 1바이트 (pointer은 4 아님 8바이트)
}