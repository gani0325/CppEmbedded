#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

// 2) sCamper ���ڿ� ��ġ��
char* Combine(char* const  sourceA, char* const  sourceB) {
	char* szBuffer = malloc((strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);
	memset(szBuffer, 0, (strlen(sourceA) + strlen(sourceB)) * sizeof(sourceA) + 1);

	szBuffer = strcat(sourceA, sourceB);

	return szBuffer;
}