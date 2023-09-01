#include <stdio.h>

int TestFunc1(int nParam) { return nParam * 2; }
int TestFunc2(int nParam) { return nParam * 3; }

void main()
{
    int nInput = 0;
    // 함수 포인터
    int (*pfTestFunc)(int) = NULL;

    scanf_s("%d", &nInput);
    if (nInput > 5)
        pfTestFunc = TestFunc1;
    else
        pfTestFunc = TestFunc2;
    printf("%d\n", pfTestFunc(nInput));
}