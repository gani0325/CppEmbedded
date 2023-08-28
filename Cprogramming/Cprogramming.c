#include <stdio.h>

void main(void)
{
	int i = 0, nInput = 0, nTotal = 0;

	for (i = 0; i < 5; ++i)
	{
		scanf_s("%d", &nInput);

		if (nInput < 0)
			continue;

		nTotal += nInput;
	}

	printf("Total: %d, i: %d\n", nTotal, i);
}
/*
1
2
3
4
-5 //실행 흐름은 조건식이 아니라 반복 실행식으로 이동되었다.
Total: 10, i: 5 //음수를 저장하지않음.
계속하려면 아무 키나 누르십시오 . . .

➡️ break문을 만난다면 반복문을 종료한다.
➡️ continue 문을 만난다
1) while 문의 경우 조건식으로 흐름 변경
2) for 문의 경우 반복 실행식으로 흐름 변경
*/