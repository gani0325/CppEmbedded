// 문자열 처리 응용 - 덧셈 문자열을 입력받아 덧셈 실행
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "덧셈 문자열 입력하기" << endl;
    getline(cin, s, '\n');

    int sum = 0;
    // 문자열 내에 검색할 시작 인덱스
    int startIndex = 0;

    while (true)
    {
        // "+" 문자 검색
        int fIndex = s.find('+', startIndex);
        // "+" 문자 발견할 수 없음
        if (fIndex == -1)
        {
            string part = s.substr(startIndex);
            // "+" 으로 끝나는 경우
            if (part == "")
                break;
            cout << part << endl;
            // 문자열을 수로 변환하여 더하기
            sum += stoi(part);
            break;
        }
        // 서브스트링으로 자를 문자 개수
        int count = fIndex - startIndex;
        string part = s.substr(startIndex, count);

        cout << part << endl;
        // 문자열을 수로 변환하여 더하기
        sum += stoi(part);
        // 검색을 시작할 인덱스 전진시킴
        startIndex = fIndex + 1;
    }

    cout << "숫자들의 합은 " << sum;
}

/*
덧셈 문자열 입력하기
66+4+24+3+25
66
4
24
3
25
숫자들의 합은 122
*/