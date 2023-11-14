#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    int total;

    cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
    cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
    getline(cin, text, ';');

    // cout << text << endl;

    // // 65, 97
    for (int i = 0; i < 26; i++) {
        int cnt = 0;

        for (int j = 0; j < text.length(); j++) {
            if (isalpha(text[j]) != 0) {
                if (char(i + 97) == char(tolower(char(text[j])))) {   
                    cnt += 1;
                }
            }
        }

        string temp;
        for (int k = 0; k < cnt; k++) {
            temp.push_back('*');
        }
        total += cnt;
        cout << char(i+97) << " (" << cnt << ") \t: " << temp << endl;
    }   
    cout << "총 알파벳 수 " << total << endl;
}