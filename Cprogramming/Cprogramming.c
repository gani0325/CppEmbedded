﻿#include <stdio.h>

// 전역변수
int nResult = 10;
int TestFunc()
{	// 정적변수 (전역변수 처럼 특정 스코프에서 가능)
	// 정적은 한번만 초기화해줌 (반복해도 무시~할듯)
	static int nResult = 10;
	nResult++;
	return nResult;
}

int TestFunc2()
{	// 정적변수 (전역변수 처럼 특정 스코프에서 가능)
	// 정적은 한번만 초기화해줌 (반복해도 무시~할듯)
	static int nResult = 10;
	nResult++;
	return nResult;
}

void main(void)
{
	printf("%d\n", TestFunc());
	printf("%d\n", TestFunc());
	printf("%d\n", TestFunc());

	// 변수명 같아도 Data 영역에 다른 주소가 저장됨
	printf("%d\n", TestFunc2());
	printf("%d\n", TestFunc2());
	printf("%d\n", TestFunc2());
	printf("%d", nResult);
}