#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Random {

public:
    Random();
    int next();
    int nextInRange(int a, int b);
};

Random::Random() {
    srand((unsigned)time(0));
}

int Random::next() {
    // rand() % (마지막 값 - 시작 값 + 1) + 시작 값
    int n = rand();
    return n;
}

int Random::nextInRange(int a, int b) {
    // rand() % (마지막 값 - 시작 값 + 1) + 시작 값
    int n = rand() % (b - a + 1) + a;
    return n;
}

int main() {
    Random r;
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 점수 10 개--" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.next();     // 0에서 RAND_MAX (32767) 사이의 랜덤한 정수
        cout << n << " ";
    }

    cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
    for (int i = 0; i < 10; i++) {
        int n = r.nextInRange(2, 4);   // 2에서 4 사이의 랜덤한 정수
        cout << n << " ";
    }

    cout << endl;
}