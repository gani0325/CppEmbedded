// 문자열 find 및 replace
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "여러 줄의 문자열 입력하세요. 입력의 끝은 & 문자" << endl;
    getline(cin, s, '&');
    // enter 키 제거하기 위한 코드
    cin.ignore();

    string f, r;
    cout << endl
         << "find : ";
    getline(cin, f, '\n'); // 검색할 문자열 입력
    cout << "replace : ";
    getline(cin, r, '\n'); // 대치할 문자열 입력

    int startIndex = 0;
    while (true)
    {
        int fIndex = s.find(f, startIndex);
        if (fIndex == -1)
        {
            break;
        }

        // fIndex 부터 문자열 f의 길이만큼 문자열 r로 변경
        s.replace(fIndex, f.length(), r);
        startIndex = fIndex + r.length();
    }

    cout << s << endl;
}

/*
여러 줄의 문자열 입력하세요. 입력의 끝은 & 문자
hi, today is thursday! I am very hungry. And I will sleep now. say hello! hi girl~ we need to go to bed right now~ see sddsson &

find : now
replace : nooooooooow
hi, today is thursday! I am very hungry. And I will sleep nooooooooow. say hello! hi girl~ we need to go to bed right nooooooooow~ sddsson*/