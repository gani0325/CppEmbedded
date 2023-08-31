#include <stdio.h>

void main(void)
{
	// 3번 문제의 답을 수정하여 sprintf( ) 함수 대신 strcat( ) 함수를 사용하여
	// 같은 결과가 나오도록 코드를 변경하세요.

	char ch1[15] = { 0, };
	char ch2[15] = { 0, };
	gets(ch1);
	gets(ch2);

	strcat(ch1, ch2);
	puts(ch1);
}