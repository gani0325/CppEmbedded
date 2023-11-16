#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)" << endl;

    string end;

    while (end != "exit") {
        string str;
        
        cout << ">>";
        getline(cin, str);
        
        // exit 인가
        if (str == "exit") {
            end = "exit";
            break;
        }

        for (int i = str.length() - 1; i >= 0; i--) {
            cout << str[i];
        }
        cout << endl;
    }
}