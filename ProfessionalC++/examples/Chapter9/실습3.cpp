#include <iostream>
#include <string>

using namespace std;

class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();

protected:
    LoopAdder (string name="") {
        this->name = name;
    }
    int getX() {return x;}
    int getY() {return y;}

    virtual int calculate() = 0;

public:
    void run();
};

void LoopAdder::read() {
    cout << name << ":" << endl;
    cout << "처음 수에서 두번 째 수까지 더합니다. 두 수를 입력하세요 >>";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
    read();
    sum = calculate();
    write();
}

class ForLoopAdder : public LoopAdder {
int sum2 = 0;

public:
    ForLoopAdder(){}
    ForLoopAdder (string name="") : LoopAdder(name) { }
    
    virtual int calculate() {
        int x2 = getX();
        int y2 = getY();

        for (int i = x2; i < y2+1; i++) {
            sum2 += i;
        }
        return sum2;
    };
};

int main() {
    ForLoopAdder forLoop("For Loop");
    forLoop.run();
}