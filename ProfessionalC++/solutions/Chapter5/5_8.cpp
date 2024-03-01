// 참조 리턴
#include <iostream>
using namespace std;

// 배열 s의 index 원소 공간에 대한 참조를 리턴하는 함수
char &find(char s[], int index)
{
    return s[index];
}

int main()
{
    char name[] = "Gani";
    cout << name << endl;

    // find() 가 리턴한 위치에 문자 저장
    find(name, 0) = 'S';
    cout << name << endl;

    char &ref = find(name, 2);
    ref = 't';
    cout << name << endl;
}

/*
Gani
Sani
Sati
*/