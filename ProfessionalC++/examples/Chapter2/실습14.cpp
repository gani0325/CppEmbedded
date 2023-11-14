#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int sum = 0;
    int total = 0;
    string coffee;

    while(total <= 20000) {
        cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;       
        cout << "주문>>";
        cin >> coffee >> n;

        if (coffee == "에스프레소") {
            cout << 2000 * n << "원입니다. 맛있게 드세요" << endl;
            total += 2000 * n;
        }
        else if (coffee == "아메리카노") {
            cout << 2300 * n << "원입니다. 맛있게 드세요" << endl;
            total += 2300 * n;
        }
        else if (coffee == "카푸치노") {
            cout << 2500 * n << "원입니다. 맛있게 드세요" << endl;
            total += 2500 * n;
        }

        if (total >= 20000) {
            cout << "오늘 " << total << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
        }
    }
}