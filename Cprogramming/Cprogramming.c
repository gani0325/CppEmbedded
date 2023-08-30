#include <stdio.h>

void main(void)
{
	// 요소의 개수가 5인 int형 배열을 선언(초깃값은 임의로 설정)하고,
	// 각 요소의 주소를 출력하는 프로그램을 작성하세요.
	// 단, 각 요소는 배열 연산자로 접근해야 합니다

	int Array[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		printf("%p\n", &Array[i]);
	}

}

/*
0000006B36DFFB68
0000006B36DFFB6C
0000006B36DFFB70
0000006B36DFFB74
0000006B36DFFB78
*/