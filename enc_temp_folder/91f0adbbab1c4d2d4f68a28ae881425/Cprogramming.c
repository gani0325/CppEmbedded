#include <stdio.h>

int UpSorted(int* array, int num) {
	int min = 0;
	int temp = 0;

	printf("#####%p\n", array);
	printf("^^^^^^%d", *(array + 1));
	for (int i = 0; i < num; i++) {
		min = array[i];
		for (int j = i + 1; j < num; j++) {
			if (min > *(array + j)) {
				temp = *(array + j);
				*(array + j) = array[i];
				array[i] = temp;
			}
			else {
				continue;
			}
		}
	}
	printf("^^^^^^%p", array);

	return 0;
}

void main(void)
{
	// 인자로 int형 배열(혹은 주소)과 요소의 개수를 받은 후, 
	// 오름차순으로 정렬하는 함수를 작성하세요

	int Arr[] = { 0, };
	int num = 0;
	int n = 0;

	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d", &n);
		Arr[i] = n;
	}

	//printf("#####%d", *Arr);
	printf("#####%p", &Arr);
	printf("^^^^^^%d", *Arr);
	UpSorted(Arr, num);

}