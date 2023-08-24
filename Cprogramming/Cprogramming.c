#include <stdio.h>

void main()
{
	char szBuffer[128] = { 0 };
	printf("Input string: ");

	// 두번째 칸부터 받을 수 있음
	scanf_s("%s", szBuffer+1, 128);
	puts(szBuffer);
	puts(szBuffer+1);
}

//Input string: 이것은테스트문자열입니다.
//이것은테스트문자열입니다.
//계속하려면 아무 키나 누르십시오 . . .

/**********/


//Input string: 이것은 테스트 문자열입니다.
//이것은
//계속하려면 아무 키나 누르십시오 . . .