#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

void main() {
	// ���̺귯�� ���� - SCAMPER

	// 5) scamPer ���� �̸��� �̴ϼȷ� ������ֱ�
	char* name[20] = { 0, };
	printf("���� �̸� (�̴ϼȷ� ���) : ");
	gets(name);

	char* result5 = PutToOtherUses(name);
	printf("scamPer ��� : ");
	printf("%s\n", result5);
	free(result5);
}