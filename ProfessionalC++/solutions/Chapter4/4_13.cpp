// 문자열을 입력받고 회전시키기
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;

    cout << "아래에 문자열 입력하세요." << endl;
    getline(cin, s, '\n');

    for (int i = 0; i < s.length(); i++)
    {
        string first = s.substr(0, 1);
        string sub = s.substr(1, s.length() - 1);

        s = sub + first;
        cout << s << endl;
    }
}

/*
I love you
 love youI
love youI
ove youI l
ve youI lo
e youI lov
 youI love
youI love
ouI love y
uI love yo
I love you
*/