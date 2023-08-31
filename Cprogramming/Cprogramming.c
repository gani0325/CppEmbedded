#include <stdio.h>

void main(void)
{
	// 사용자로부터 두 문자열을 입력받은 후, 
	// 두 문자열 중에서 길이가 긴 문자열이 출력되는 프로그램을 작성하세요

	char ch1[15] = { 0, };
	char ch2[15] = { 0, };
	gets(ch1);
	gets(ch2);

	if (strlen(ch1) > strlen(ch2)) {
		puts(ch1);
	}
	else {
		puts(ch2);
	}
}