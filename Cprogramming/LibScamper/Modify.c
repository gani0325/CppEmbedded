#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 4) scaMper �ҹ��ڸ� �빮��, �빮�ڸ� �ҹ���
char* Modify(char* const  source, int chapital) { // 0=�빮��, 1=�ҹ���
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
