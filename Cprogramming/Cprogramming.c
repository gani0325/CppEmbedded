#include <stdio.h>
#include <stdlib.h>

void PutString(char* str) {
    if (*str == NULL) {
        return;
    }

    else
    {
        PutString(str + 1);
        printf("%c", *str);
    }
}

void main()
{
    // 인자로 char*형을 받아서 문자열을 거꾸로 출력하는 재귀 호출 함수를 작성하세요.
    // 함수의 원형은「void PutString(char* pszData); 」와 같습니다

    char* pszData[20] = { 0, };

    gets(pszData);
    puts(pszData);

    PutString(pszData);
}

/*
hello
hello
olleh
*/
