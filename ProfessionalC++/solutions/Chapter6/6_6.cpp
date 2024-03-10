// 중복된 생서자들을 디폴트 매개 변수를 이용한 간소화 연습
#include <iostream>
using namespace std;

class MyVector
{
    int *p;
    int size;

public:
    MyVector(int n = 100)
    {
        p = new int[n];
        size = n;
    }

    ~MyVector() { delete[] p; }
};

int main()
{
    MyVector *v1, *v2;
    // 디폴트로 정수 배열 100 동적 할당
    v1 = new MyVector();
    // 정수 배열 1024 동적 배열
    v2 = new MyVector(1024);

    delete v1;
    delete v2;
}