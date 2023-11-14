#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "로미오>>";
    cin >> s;   // 로미오가 입력한 문자열

    string t;
    cout << "줄리엣>>";
    cin >> t;  // 줄리엣이 입력한 문자열

    // 로미오
    if (s == "가위") {
        // 줄리엣
        if (t == "가위") {
            cout << "비겼습니다." << endl;
        }
        else if (t == "보") {
            cout << "로미오가 이겼습니다." << endl;
        }
        else if (t == "바위") {
            cout << "줄리엣이 이겼습니다." << endl;
        }
    }

    // 로미오
    if (s == "바위") {
        // 줄리엣
        if (t == "가위") {
            cout << "로미오가 이겼습니다." << endl;
        }
        else if (t == "보") {
            cout << "줄리엣이 이겼습니다." << endl;
        }
        else if (t == "바위") {
            cout << "비겼습니다." << endl;
        }
    }

    // 로미오
    if (s == "보") {
        // 줄리엣
        if (t == "가위") {
            cout << "줄리엣이 이겼습니다." << endl;
        }
        else if (t == "보") {
            cout << "비겼습니다." << endl;
        }
        else if (t == "바위") {
            cout << "로미오가 이겼습니다." << endl;
        }
    }
}