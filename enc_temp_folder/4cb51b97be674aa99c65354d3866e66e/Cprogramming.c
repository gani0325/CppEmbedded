#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// 라이브러리를 해당 main.c 폴더 위치 내에 복사시킴
#pragma comment(lib, "LibScamper")    //<<다른 라이브러리가 사용되었음을 컴파일러에 알리고 함께 링크

void main(void)
{
	char* sourA[20] = { 0 };
	char* sourB[20] = { 0 };

	printf("결합하고 싶은 문자 : ");
	gets(sourA);
	gets(sourB);

	char* result;
	result = Combine(sourA, sourB);
	puts(result);
}


/*
결합하고 싶은 문자 : gani
hello
ganihello
*/