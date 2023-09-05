#pragma once
// 함수 선언
// 1) Scamper 문자열 대체해서 변환하기
char* Substitute(char* const  orgin, char* source, char* target);
// 2) sCamper 문자열 합치기
char* Combine(char* const  sourceA, char* const  sourceB);
// 4) scaMper 소문자면 대문자, 대문자면 소문자
char* Modify(char* const  source, int chapital);
// 7) scampeR 문자열 역순으로 배열하기
char* Reverse(char* const  source);