#include <stdio.h>

void main(void)
{
	int nResult = 0x11223344;

	// nResult 변수에 저장된 32비트 정수와 32비트 16진수 FFFF0000를 비트 AND
	printf("%X\n", nResult & 0xFFFF0000);

	// 각각 오른쪽, 왼쪽 쉬프트(Shift) 연산
	printf("%X\n", nResult >> 16);
	printf("%X\n", nResult << 8);

	// nResult 변수에 저장된 32비트 정수와 32비트 16진수 2211FFFF를 비트 OR 연산
	printf("%X\n", nResult | 0x2211FFFF);
	// nResult 변수에 저장된 32비트 정수와 32비트 16진수 2211FFFF를 비트 XOR 연산
	printf("%X\n", nResult ^ 0x2211FFFF);
	// nResult 변수에 저장된 32비트 정수에 대한 1의 보수를 출력
	printf("%X\n", ~nResult);
}

// 11220000
// 1122
// 22334400
// 3333FFFF
// 3333CCBB
// EEDDCCBB