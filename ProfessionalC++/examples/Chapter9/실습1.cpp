#include <iostream>
#include <string>

using namespace std;

class Converter {
protected:
    double ratio;
    virtual double convert(double src) = 0;
    virtual string getSourceString() = 0;
    virtual string getDestString() = 0;
public:
    // Converter(){}
    Converter(double ratio) { this->ratio = ratio; }
    void run() {
        double src;
        cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
        cout << getSourceString() << "을 입력하세요>> ";
        cin >> src;
        cout << "변환 결과 : " << convert(src) << getDestString() << endl;
    }
};

class WonToDollar : public Converter {
    double a;
    double ratio2;
    string str1;
    string str2;
public:
    WonToDollar(double ratio) : Converter(ratio) { ratio2=ratio;};
    // WonToDollar(double ratio)  { this->ratio=ratio;};

    virtual double convert(double src) {
        a = src / ratio;
        return a; 
    };
    virtual string getSourceString() {
        str1 = "원";
        return str1;
    };
    virtual string getDestString() {
        str2 = "달러";
        return str2;
    };
};


int main() {
    WonToDollar wd(1010);
    wd.run();
}