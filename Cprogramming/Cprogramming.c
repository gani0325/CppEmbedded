// 사용자로부터 입력받은 크기만큼의 메모리를 동적으로 할당받은 후
// 다시 문자열을 입력받아 앞서 동적으로 할당받은 메모리에 저장하고 출력
// 메모리를 동적으로 할당받기 위해 calloc( ) 함수를 사용

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main(void)
{
	char* pszData = NULL;
	int nInput = 0;

	printf("Input length : ");
	// 사용자로부터 정수를 입력받아 nInput 변수에 저장
	scanf_s("%d\n", &nInput);
	// calloc( ) 함수를 이용하여 메모리를 동적으로 할당받고
	// 0으로 초기화한 후, 그 주소를 pszData 포인터 변수에 저장
	pszData = (char*)calloc(nInput, sizeof(char));

	// 표준 입력 장치 파일의 입출력 정보를 초기화
	fflush(stdin);
	// 사용자로부터 문자열을 입력받아서 pszData 포인터 변수에 
	// 저장된 주소의 메모리에 저장
	gets(pszData);
	puts(pszData);
	// 동적으로 할당받았던 메모리를 free( ) 함수로 해제
	free(pszData);
}

/*
Input length : //16
홍길동 // 홍길동
*/