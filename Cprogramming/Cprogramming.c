#include <stdio.h>
#include <stdlib.h> 

int max = _CRT_INT_MAX;

int GetLength(const char* ch) {
	int cnt = 0;

	for (int i = 0; i < max; i++) {
		if (*(ch + i) == 00) {
			break;
		}
		else {
			cnt++;
		}
	}

	return cnt;
}

void main(void)
{
	// 인자로 char*형을 받아서 문자열의 길이를 반환하는 함수를 작성하세요. 
	// 단, 절대로 strlen() 함수를 사용하지 말고 직접 계산하는 코드를 작성하세요.
	// 함수의 이름은 GetLength()로 합니다

	char ch[16];
	printf("문자열 입력하세요 : ");
	gets(ch);

	int result = 0;
	result = GetLength(ch);
	printf("문자열 길이 : %d", result);
}

/*

*/