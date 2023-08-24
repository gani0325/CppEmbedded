#include <stdio.h>

void main()
{
	// 사용자로부터 한 문자를 입력받아 10진수로 출력하는 프로그램을 작성하세요.
	// 단, getch() 함수로 입력을 받고 printf() 함수로 출력하세요.
	char ch;
	ch = getch();

	printf("%d", ch);
}