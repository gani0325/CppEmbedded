// string 배열과 문자열 키 입력 응용
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string names[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "이름 >> ";
        getline(cin, names[i], '\n');
    }

    string latter = names[0];
    for (int i = 1; i < 5; i++)
    {
        if (latter < names[i])
        {
            latter = names[i];
        }
    }

    cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
}

/*
이름 >> kim nam jun
이름 >> lee ga eun
이름 >> lee a rin
이름 >> tae hoon
이름 >> jung kook
사전에서 가장 뒤에 나오는 문자열은 tae hoon

- string 객체에 문자열 입력
cin >> 을 이용하여 키보드로부터 string 객체에 문자열을 입력받기
공백 문자가 입력되면 그 앞까지 하나의 문자열로 다루기 때문에 공백 문자를 포함하는 문자열 읽어들일 수 없음
getline() 전역 변수로 긴 라인의 문자열 입력받기

// '\n' 을 만날 때까지 키보드 (cin) 로부터 문자열 읽어들어 저장하기
string name;
getline(cin, name, '\n');
*/