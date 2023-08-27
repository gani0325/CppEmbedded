// malloc( ) 함수의 반환형이 void*형
// 포인터이긴 한데 대상 메모리를 어떤 방법으로 해석할지 결정되지 않았다

#include <stdio.h>

void main(void)
{
	// pnData라는 int형 포인터 변수를 선언
	int* pnData = NULL;
	// malloc( ) 함수를 이용하여 메모리를 동적으로 할당
	pnData = (int*)malloc(sizeof(int) * 4);
	// 동적으로 할당받은 메모리를 모두 0으로 초기화
	memset(pnData, 0, sizeof(int) * 4);

	// pnData라는 포인터 변수에 저장된 주소에 대해 옵셋과 
	// 간접 지정 연산을 수행한 후 정수형 상수를 저장
	*(pnData) = 10;
	*(pnData + 1) = 20;

	// pnData라는 포인터 변수에 저장된 주소에 대해 옵셋과 
	// 간접 지정 연산을 수행한 후 해당 메모리의 내용을 읽어 와서 출력
	printf("%d\n", *(pnData));
	printf("%d\n", *(pnData + 1));

	// 동적으로 할당받았던 메모리를 free( ) 함수를 호출하여 해제하고 운영체제에 반환
	free(pnData);
}

/*
10
20
*/