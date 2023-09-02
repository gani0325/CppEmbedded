#include <stdio.h>
#include <stdlib.h>

void PutString(char* pszData) {
    char temp[20] = { 0, };

    // temp 에 잠시 복붙.. (strcmp 도 되려나)
    for (int i = 0; i < strlen(pszData); i++) {
        *(temp + i) = *(pszData + i);
    }

    // 기존 pszData 에 거꾸로 된거로 변환한다
    for (int j = 0; j < strlen(temp); j++) {
        *(pszData + j) = *(temp + strlen(temp) - 1 - j);
    }

    return pszData;
}

void main()
{
    // 인자로 char*형을 받아서 문자열을 거꾸로 출력하는 재귀 호출 함수를 작성하세요.
    // 함수의 원형은「void PutString(char* pszData); 」와 같습니다

    char* pszData[20] = { 0, };

    gets(pszData);
    puts(pszData);

    PutString(pszData);
    puts(pszData);
}

/*
hello
hello
olleh
*/