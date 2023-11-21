#include <iostream>
#include <string>
using namespace std;

class Statistics {
    int arr[10];
public:
    Statistics();
    ~Statistics();

    bool operator ! ();
    Statistics& operator << (int op2);
    Statistics& operator >> (int * ob2);
    void operator ~ ();
};

Statistics::Statistics() {

}

Statistics::~Statistics() {
    for (int i = 0; i < 10; i++) {
        delete arr[i];
    }
};

bool Statistics::operator ! () {
    if (arr) {
        return true;
    }
    else {
        return false;
    }
}

Statistics& Statistics::operator << (int op2) {
    int *p = new int;
    *p = op2;

    for (int i = 0; i < 5; i++) {
        arr[i] = *p;
    }
    return *this;
}

Statistics& Statistics::operator >> (int * op2) {
    int average = 0;
    for (int i = 0; i < 5; i++) {
        average += arr[i];
    }
    
    *op2 = average;
    return *this;
}

void Statistics::operator ~ () {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    Statistics stat;
    if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하라>>";
    for (int i = 0; i < 5; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < 5; i++) {
        stat << x[i];
    }

    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout << "avg=" << avg << endl;
}