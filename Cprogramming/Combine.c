#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ


void Combine_main() {
	// ���̺귯�� ���� - SCAMPER

	// 2) sCamper ���ڿ� ��ġ��
	char* sourA[20] = { 0 };
	char* sourB[20] = { 0 };

	printf("�����ϰ� ���� ���� : ");
	gets(sourA);
	gets(sourB);

	char* result2 = Combine(sourA, sourB);
	printf("sCamper ��� : ");
	printf("%s\n", result2);
	free(result2);
}