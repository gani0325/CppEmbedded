#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int cnt = 0;

    while(n != 4) {
        cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
        cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
        
        cin >> n;

        if (n == 1) {
            cout << "몇인분?";
            cin >> cnt;
            cout << "짬뽕 " << cnt << "인분 나왔습니다" << endl;
        }
        else if (n == 2) {
            cout << "몇인분?";
            cin >> cnt;
            cout << "짜장 " << cnt << "인분 나왔습니다" << endl;
        }
        else if (n == 3) {
            cout << "몇인분?";
            cin >> cnt;
            cout << "군만두 " << cnt << "인분 나왔습니다" << endl;
        }
        else if (n == 4) {
            cout << "오늘 영업은 끝났습니다." << endl;
        }
        else {
            cout << "다시 주문하세요!!" << endl;
        }
    }
}