// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

void main()
{
	int nInput = 0;
	printf("Input number: ");
	// scanf_s() 함수 : 형식 문자열을 사용하지만 이어지는 가변 인자로는 전부 주소가 와야 한다
	// → 사용자의 입력을 인자로 전달 받은 주소에 저장한다는 뜻
	scanf_s("%d", &nInput);
	printf("%d\n", nInput);
}

//Input number: 10 
//10