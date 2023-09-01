#include <stdio.h>

// 외부변수 지정
extern int g_nCounter;

// 함수 선언
void InitCounter(int nData);

void IncreaseCounter();

void main(void)
{
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
}