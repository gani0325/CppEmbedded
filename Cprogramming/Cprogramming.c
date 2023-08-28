#include <stdio.h>

void main(void)
{
    int nInput = 0;
    scanf_s("%d", &nInput);

    while (nInput > 0)
    {
        printf("%dth printf()\n", nInput);
        nInput--;
    }
}

// 5를 입력
// 5th printf( )
// 4th printf( )
// 3th printf( )
// 2th printf( )
// 1th printf( )