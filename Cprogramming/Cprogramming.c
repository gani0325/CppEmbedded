// 주소를 계산하는 것뿐만 아니라 
// 계산된 주소를 간접 지정하여 문자를 출력

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main(void)
{
	// char형 포인터 변수 pszData를 선언, 문자열 상수의 주소로 초기화
	char* pszData = "Test string!";

	// pszData라는 포인터 변수에 저장된 주소
	// 그 주소를 간접 지정한 메모리의 내용을 각각 주소와 문자 형식으로 출력
	printf("[%p] %c\n", pszData, *pszData);
	printf("[%p] %c\n", pszData + 1, *(pszData + 1));
	printf("[%p] %c\n", pszData + 2, *(pszData + 2));
	printf("[%p] %c\n", pszData + 3, *(pszData + 3));

	// pszData라는 포인터 변수에 저장된 주소와 옵셋을 수행하여 그 주소를 출력
	// 옵셋 결과에 해당하는 주소를 간접 지정하여 메모리에 저장된 값을 출력
	printf("[%p] %c\n", pszData + 5, *(pszData + 5));
	printf("[%p] %c\n", pszData + 11, *(pszData + 11));
}

/*
[00007FF65F929C28] T
[00007FF65F929C29] e
[00007FF65F929C2A] s
[00007FF65F929C2B] t
[00007FF65F929C2D] s
[00007FF65F929C33] !
*/