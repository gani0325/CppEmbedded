#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>


// 6) scampEr Ÿ�� ���������� �����ϱ�
char* Eliminate(char* const  source, char* target) {
	char* szBuffer = malloc(strlen(source) * sizeof(source) + 1);
	memset(szBuffer, 0, (strlen(source) * sizeof(source) + 1));
	int pt = 0;

	for (int i = 0; i < strlen(source); i++) {
		if (source[i] == *target) {
			continue;
		}
		else {
			szBuffer[pt] = source[i];
			pt++;
		}
	}

	return szBuffer;
}