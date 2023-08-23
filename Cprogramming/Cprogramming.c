// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main(void)
{
	char ch = 'A';
	int nData = 15;
	float fData1 = 1.5f, fData2 = 3.4f;

	// 자료형이 char인 값을 int형으로 승격하고 나서 
	printf("%d\n", ch + 2);
	// 정수형 상수 2와 더한 결과를 각각의 형식으로 출력
	printf("%c\n", ch + 2);

	// float형과 int형 간의 연산 결과를 다시 float형과 연산
	printf("%f\n", fData1 * 100 / fData2);
	// float형과 int형 그리고 float형 간의 연산 결과는 float형 
	printf("%f\n", fData2 / fData1);

	// int형 간의 연산 결과는 int형
	// int형은 %f 형식 문자로 출력할 수 없다
	printf("%f\n", nData * 100 / 100);

	// int형 간의 연산 결과는 int형이므로 소수점 이하 정보는 절사
	// nData 변수를 10으로 나눈 결과는 1.5가 아니라 int형인 1
	printf("%f\n", nData / 10 * 100.0f);

	// int형인 nData 변수를 일시적으로 float형으로 형변환, int형과 연산
	// float형 간의 연산이 이루어졌으나 결과를 다시 int형으로 강제 형변환하여 정	수
	printf("%d\n", (int)((float)nData / 10 * 100.0f));

	// int형을 일시적으로 float형으로 강제 형변환을 하고서 int형과 연산
	printf("%f\n", (float)nData * 100 / 100);

	// int형 간의 연산 결과를 float형으로 형변환하여 int형과 연산
	printf("%f\n", (float)(nData * 100) / 100);
}

// 67
// C
// 44.117646
// 2.266667
// 0.000000
// 100.000000
// 150
// 15.000000
// 15.000000