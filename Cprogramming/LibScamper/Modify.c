#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 4) scaMper 소문자면 대문자, 대문자면 소문자
char* Modify(char* const  source, int chapital) { // 0=대문자, 1=소문자
	char* temp = malloc(strlen(source) + 1);
	memset(temp, 0, strlen(source) + 1);

	if (chapital == 0) {
		for (int i = 0; i < strlen(source); i++) {
			temp[i] = toupper(source[i]);
		}
	}
	else {
		for (int i = 0; i < strlen(source); i++) {
			temp[i] = tolower(source[i]);
		}
	}

	puts(temp);
	return temp;
}
