#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: �̸� �����ϵ� ����� �ش��ϴ� �ҽ� ����
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

// ���̺귯���� �ش� main.c ���� ��ġ ���� �����Ŵ
#pragma comment(lib, "LibScamper")    //<<�ٸ� ���̺귯���� ���Ǿ����� �����Ϸ��� �˸��� �Բ� ��ũ

void Eliminate_main() {
	// ���̺귯�� ���� - SCAMPER

	// 6) scampEr Ÿ�� ���������� �����ϱ�
	char* sourA[20] = { 0 };
	char* sourB[20] = { 0 };

	printf("�����ϱ� ���� ���ڿ� : ");
	gets(sourA);
	printf("������ ���� : ");
	gets(sourB);

	char* result5 = Eliminate(sourA, sourB);
	printf("scampEr ��� : ");
	printf("%s\n", result5);
	free(result5);
}

/*
�����ϱ� ���� ���ڿ� : gHello gani
������ ���� : g
scampEr ��� : Hello ani
*/