#include <stdio.h>
#include <stdlib.h> 

int max = _CRT_INT_MAX;

char GetReverse(char* ch) {
	char reverse[16];
	
	/*printf("%p", ch);
	printf("%c", *ch);
	printf("%c", *(ch + 1));
	printf("%c", *(ch + 2));*/

	for (int i = 0; i < strlen(ch); i++) {
		*(reverse + i) = *(ch + (strlen(ch) - 1 - i));
	}
	printf("%c", *reverse);
	printf("%c", *(reverse + 1));
	printf("%c", *(reverse + 2));
	printf("%c", *(reverse + 3));
	printf("%c", *(reverse + 4));

	// printf("%p", reverse);

	return reverse;
}

void main(void)
{
	// 인자로 char*형을 받아서 문자열을 거꾸로 출력하는 함수를 작성하세요.
	// 문제를 해결하기 위해서 strlen() 함수를 사용하거나 1번 문제에서 작성한 함수를 사용해도 좋습니다.

	char ch[16];
	printf("문자열 입력하세요 : ");
	gets(ch);
	
	GetReverse(ch);
	//printf("문자열 거꾸로 : %c", GetReverse(ch));
}

/*

*/