#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    cout << "문자열 입력>>";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < i+1; j++) {
            cout << s[j];
        }
        cout << endl;
    }
}