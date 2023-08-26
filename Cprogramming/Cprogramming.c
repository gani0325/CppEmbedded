// 연산의 우선순위가 달라져서 결과가 달라짐

#include <stdio.h>

void main(void)
{
	int nData = 10, nNewData = 20;
	int nResult = 0;

	printf("%d\n", ++nData);

	// nData 변수에 저장된 값을 출력시키고서 
	// nData 변수에 저장된 값을 1만큼 증가
	printf("%d\n", nData++);

	// nData 변수에 저장된 값을 1만큼 증가시키고서 
	// nNewData 변수에 저장된 값과 더하는 연산을 수행
	// 결과를 nResult 변수에 저장하고서 nNewData 변수의 값을 1만큼 증가
	nResult = ++nData + nNewData++;
	printf("%d\n", nResult);
}

// 11
// 11
// 33