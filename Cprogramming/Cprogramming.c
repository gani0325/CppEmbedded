#include <stdio.h>

void main()
{
	// getchar( ) 함수를 이용하여 세 글자 이상의 문자열을 입력받고서
	// 그중 두 번째 문자를 printf() 함수로 화면에 출력
	char ch;
	ch = getchar();
	ch = getchar();
	printf("%c", ch);
	ch = getchar();
}