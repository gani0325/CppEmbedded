#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
    int a[] = { 10,20,30,40,50 };
    printf("배열 a[0]의 주소값 = %p \n", a);

    // a+i는 a가 포인터이므로 배열 시작 주소에 (i*배열요소의 크기)이 더해짐
    printf("배열 a[1]의 주소값 = %p \n", a + 1);
    printf("배열 a[0]의 값 = %d \n", *a);

    // a+i는 &a[i]와 같고 또한 *(a+i)는 a[i]와 완전히 동일
    printf("배열 a[1]의 값 = %d \n", *(a + 1));
    return 0;
}