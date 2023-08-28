#include <stdio.h>

void main(void)
{
  int nInput = 0;
  scanf("%d", &nInput);

  do
  {
    printf("%dth printf()\n", nInput);
    nInput--;
  }
  while(nInput > 0);
}

// -1를 입력
// -1th printf( )