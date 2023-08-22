// <stdio.h> : 핵심 입력과 출력 함수들을 정의
#include <stdio.h>

// #4. 단순 대입 연산자
int main(void)
{
    // 메모리의 주소를 저장 (변수 성향의 문자열, 값 변환 가능)
    char* szName[3];
    szName[0] = "HelloWorld";
    szName[1] = "C Programming";
    szName[2] = "Studying";

    for (int i = 0; i < 3; i++)
    {
        printf("szName[%d] -> %s\n", i, szName[i]);
        printf("szName[%d] -> %d\n", i, &szName[i]);
    }

    // char형 배열에 각각의 문자가 그대로 저장 (상수 성향의 문자열, 값 변환 불가능)
    char szName2[3];
    printf("szName2 -> %s\n", szName2);
    printf("szName2 -> %d\n", &szName2);

    char szName3[3];
    szName3[0] = 'a';
    szName3[1] = 'b';
    szName3[2] = NULL;

    printf("%s", szName3);
    printf("%c", szName3[1]);

    return 0;
}