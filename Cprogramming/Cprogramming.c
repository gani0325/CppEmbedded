#include <stdio.h>

void main()
{
	int nTotal = 0;
	register int i = 0;
	for (i = 0; i < 10; ++i)
	{
		nTotal += i;
	}

	printf("%d\n", i);
	// 레지스터는 주소연산 할 수 없음 (전역, 정적 변수 사용 X)
	// printf("%p\n", &i);
}
