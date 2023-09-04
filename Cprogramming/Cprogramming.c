#include <stdio.h>

int fibo(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1 || i == 2) {
        return 1;
    }
    return fibo(i - 1) + fibo(i - 2);
}

int max = _CRT_INT_MAX;
void main()
{
    // 재귀 호출을 이용하여 값이 60 이하인 
    // 피보나치(Fibonacci) 수열을 출력하는 프로그램을 작성하세요.
    // 참고로 피보나치 수열은 다음과 같이 앞뒤 숫자의 합이 이어지는 모습을 하고 있습니다+
    // 1 1 2 3 5 8 13 21 34 55  

    for (int j = 1; j < 60; j++) {
        if (fibo(j) > 60) {
            break;
        }
        printf("%d ", fibo(j));
    }
}