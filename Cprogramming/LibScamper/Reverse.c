#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 7) scampeR 문자열 역순으로 배열하기
char* Reverse(char* const  source) {
	char* temp = malloc(strlen(source) + 1);
	memset(temp, 0, strlen(source) + 1);

	for (int i = 0; i < strlen(source); i++) {
		temp[i] = source[strlen(source) - 1 - i];
	}

	return temp;
}