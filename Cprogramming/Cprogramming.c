#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char x;
	char y;

	printf("문자를 두 번 입력하세요. \n");
		
	// scanf(&x)에서 a + Enter를 입력받으면 버퍼에 a와 \n를 저장
	// getchar()라는 함수가 버퍼에 저장된 \n 문자를 받아서 버퍼가 초기화
	scanf("%c", &x);
	getchar(); //버퍼 초기화

	// getchar() 없으면 버퍼는 scanf(&x)에는 a를 주고, 
	// scanf(&y)에는 \n를 주기 때문에 실행되지 않고 바로 종료
	scanf("%c", &y);

}