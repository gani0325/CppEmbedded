#pragma once
// 함수 선언
// 1) Scamper 문자열 대체해서 변환하기
char* Substitute(char* const  orgin, char* source, char* target);
// 2) sCamper 문자열 합치기
char* Combine(char* const  sourceA, char* const  sourceB);
// 3) scAmper 주어 받고 랜덤값으로 문자열 만들어주기
char* Adapt(char* const source);
// 4) scaMper 소문자면 대문자, 대문자면 소문자
char* Modify(char* const  source, int chapital);
// 5) scamPer 영어 이름을 이니셜로 요약해주기
char* PutToOtherUses(char* const  origin);
// 6) scampEr 타겟 문자있으면 제거하기
char* Eliminate(char* const  source, char* target);
// 7) scampeR 문자열 역순으로 배열하기
char* Reverse(char* const  source);