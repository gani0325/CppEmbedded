#include <stdio.h>

void main(void)
{
	// 10~100까지의 숫자 중에서 4의 배수가 몇 개이며, 
	// 이들의 총합이 얼마인지 알아내어 출력하는 프로그램을 작성하세요
	int sum = 0;
	int cnt = 0;
	for (int i = 10; i <= 100; i++) {
		if (i % 4 == 0) {
			sum += i;
			cnt++;
		}
	}

	printf("%d %d", sum, cnt);
}

/*
1288 23
*/