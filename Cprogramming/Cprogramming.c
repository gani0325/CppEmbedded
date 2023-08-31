#include <stdio.h>

void main(void)
{
	// 사용자로부터 두 문자열을 입력받은 후, 
	// 하나로 합쳐서 출력하는 프로그램을 작성하세요.
	// 단, 두 문자열을 합칠 때 반드시 sprintf() 함수를 사용해야 하며,
	// 첫 번째 입력받은 문자열이 저장된 메모리(배열)에 합친 결과가 저장되도록 합니다.

	char ch1[] = { 0, };
	char ch2[] = { 0, };
	gets(ch1);
	gets(ch2);
	printf("\n%d", strlen(ch1));
	printf("%d", strlen(ch2));
	printf("%p", &ch1[sizeof(strlen(ch1))]);
	//strcat(ch1, ch2);
	//puts(ch1);

	sprintf_s(&ch1[sizeof(strlen(ch1))] + 1, strlen(ch2) + 1, "%s", ch2);

}