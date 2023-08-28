﻿#include <stdio.h>
#include <string.h>

void main(void)
{
	// 다음과 같은 모양으로 숫자를 출력하는 프로그램을 작성하세요. 
	// 단, 숫자들 사이 공간은 탭(\t)으로 출력하세요.
	// 참고로 왼쪽이 비어 있는 것들은 숫자를 출력하지 않고 키만 출력한 것입니다.
    //  1) 1 2 3 4 5
		// 10 9 8 7 6
		// 11 12 13 14 15
		// 20 19 18 17 16
		// 21 22 23 24 25

	for (int i = 1; i <= 25; i += 10) {
		printf("???? %d  ", i);
		if (i % 10 == 0) {
			for (int k = 10 * i; k > i - 5; k--) {
				printf("%d\t", k);
			}
			printf("\n");
		}
		else {
			for (int j = i; j < i + 5; j++) {
				printf("%d\t", j);
			}
			printf("\n");
		}
	}
}

/*
a b c d e
단어의 개수는 5개
*/