#include <stdio.h>

void main(void)
{
	// 1번에서 작성한 프로그램에서 배열 연산자를 제거하고
	// 출력 결과가 같게 나오도록 프로그램을 수정하세요.

	int Array[5] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		printf("%p\n", Array + i);
	}

}

/*
0000006B36DFFB68
0000006B36DFFB6C
0000006B36DFFB70
0000006B36DFFB74
0000006B36DFFB78
*/