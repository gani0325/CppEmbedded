// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main()
{
	// gets()/puts( )
	char szBuffer[128] = { 0 };
	printf("Input your name: ");
	// 전체 문자열을 통째로 반환
	gets(szBuffer);

	printf("Your name is ");
	// 출력할 문자열의 길이를 따로 명시하지 않아도 알아서 출력
	puts(szBuffer);
}

// Input your name: gani
// Your name is gani