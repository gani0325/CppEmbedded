#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>


// 3) scAmper �־� �ް� ���������� ���ڿ� ������ֱ�
char* Adapt(char* const source) {
	char* szBuffer = malloc(strlen(source) * sizeof(source) + 15);
	memset(szBuffer, 0, (strlen(source) * sizeof(source) + 15));
	strcpy(szBuffer, source);

	// ������ ����
	srand((unsigned)time(NULL));
	int num = 0;
	num = rand() % 3;

	// ����� ������
	char* verb[3] = { " think", " love", " look" };
	char* object[3] = { " book", " dog", " you" };

	// ���ڿ� ��ġ��
	strcat(szBuffer, verb[num]);
	strcat(szBuffer, object[num]);

	return szBuffer;
}