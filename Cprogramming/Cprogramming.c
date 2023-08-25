#include <stdio.h>

void main(void)
{
	// if 문을 사용하여 사용자로부터 입력받은 다섯 정수 중 최댓값을 출력하는 프로그램을 작성하세요.
	// 단, 다섯 개의 정수를 한 줄로 한 번에 입력받는 것이 아니라 5회에 걸쳐서 입력받는 형태로 작성하세요.

	int num, max = 0;

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &num);
		if (max < num) {
			max = num;
		}
	}

	printf("가장 큰 숫자는 : %d", max);
}