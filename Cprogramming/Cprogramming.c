// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main()
{
	char* pszData = "Test string!";

	// pszData 변수에 저장된 주소를 근거로 문자열을 출력
	printf("%s\n", pszData);	// 0x00007FF7DCCC9C10
	// pszData 변수에 저장된 주소를 주소 형식으로 출력
	printf("%p\n", pszData); 
	// &는 주소 연산자
	// &pszData는 pszData라는 이름의 변수의 주소
	// 주소 형식으로 출력되는 것은 pszData라는 이름의 메모리 주소
	printf("%p\n", &pszData);	// 0x00000090DEFCF7C8
}

/*
Test string!
00007FF63BE69C10
00000066C233FC48
계속하려면 아무 키나 누르십시오 . . .
*/