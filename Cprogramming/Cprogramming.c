#include <stdio.h>

void main(void)
{
	// 문자열을 입력받아서 대문자는 소문자로, 
	// 소문자는 대문자로 변환하여
	// 출력하는 프로그램을 작성하세요

	char ch[15] = { 0, };
	gets(ch);

	for (int i = 0; i < strlen(ch); i++) {
		printf("%c", toupper(*(ch + i)));
	}
	printf("\n");

	for (int i = 0; i < strlen(ch); i++) {
		printf("%c", tolower(*(ch + i)));
	}
}