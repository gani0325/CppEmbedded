#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// 포인터의 장점은 어느곳에 있든지 주소를 직접적으로 참조함으로써 값을 가져올 수 있고 변경할 수 있다

// Call by value
// 함수에서 값을 복사해서 전달하는 방식으로, 인자로 전달되는 변수를 함수의 매개변수에 복사한다. 
// 원본 값을 바꿀 필요가 없는 경우
void swap1(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Call by reference
// 함수에서 값을 전달하는 대신 주소값을 전달하는 방식
void swap2(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 50;

    printf("call by value\n");
    swap1(a, b);
    printf("결과 a : %d, b : %d\n\n", a, b);

    // call by reference 함수를 사용하면 원래 변수의 값도 바뀌게 됨
    printf("call by refernce\n");
    swap2(&a, &b);
    printf("결과 a : %d, b : %d\n\n", a, b);

    return 0;
}

//call by value
//결과 a : 10, b : 50
//
//call by refernce
//결과 a : 50, b : 10