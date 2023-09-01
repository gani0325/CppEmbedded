
#include <stdio.h>
// 전역변수 지정
int g_nCounter = 0;

// 함수 정의
void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter()
{
	g_nCounter++;
}