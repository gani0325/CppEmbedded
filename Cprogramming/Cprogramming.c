// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main()
{
	// 부호를 표현하는 형식 활용
	int nData1 = 1234, nData2 = -4567;

	printf("%d\n", nData1);
	printf("%+d, %+d\n", nData1, nData2);

	printf("%07d\n", nData1);
	printf("%7d\n", nData1);
	printf("%-7d\n", nData1);
}

/*
1234
+1234, -4567
0001234
   1234
1234
계속하려면 아무 키나 누르십시오 . . .
*/