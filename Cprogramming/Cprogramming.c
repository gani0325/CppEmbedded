// 사용자로부터 입력받은 크기만큼의 메모리를 동적으로 할당받은 후
// 다시 문자열을 입력받아 앞서 동적으로 할당받은 메모리에 저장하고 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


void main(void)
{
	char* pszData = NULL;
	int nInput = 0;

	printf("Input length : ");
	// 사용자로부터 정수를 입력받아 nInput 변수에 저장
	scanf_s("%d\n", &nInput);
	// malloc( ) 함수로 입력받은 수만큼의 메모리를 동적으로 할당받고 
	// 그 주소를 pszData 포인터 변수에 저장
	pszData = (char*)malloc(sizeof(char) * nInput);

	// 표준 입력 장치 파일의 입출력 정보를 초기화
	// fflush(stdin)은 주로 개행문자 '\n'을 버리기 위해 사용
	fflush(stdin);
	// 사용자로부터 문자열을 입력받아서 pszData 포인터 변수에 
	// 저장된 주소의 메모리에 저장
	gets(pszData);
	// fgets(pszData, sizeof(pszData), stdin);
	puts(pszData);
	// 동적으로 할당받았던 메모리를 free( ) 함수로 해제
	free(pszData);
}

/*
Input length : //16
Choi ho-sung // Choi ho-sung
*/