#include <stdio.h>
#include <string.h>

void main(void)
{
	// 다음과 같은 모양으로 숫자를 출력하는 프로그램을 작성하세요. 
	// 단, 숫자들 사이 공간은 탭(\t)으로 출력하세요.
	// 참고로 왼쪽이 비어 있는 것들은 숫자를 출력하지 않고 키만 출력한 것입니다.
    //  3)				 1
		//			  2  3
		//		   4  5  6
		//		7  8  9 10
		//	11 12 13 14 15

	int k = 1;

	for (int i = 1; i <= 5; i++) {
		for (int j = 5-i; j > 0; j--) {
			printf("\t");
		}

		for (int j = 0; j < i; j++) {
			printf("%d\t", k);
			k++;
		}		
		printf("\n");
	}
}

/*
								1
						2       3
				4       5       6
		7       8       9       10
11      12      13      14      15
*/