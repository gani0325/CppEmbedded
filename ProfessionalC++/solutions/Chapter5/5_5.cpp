// 참조 매개 변수로 평균 리턴하기
#include <iostream>
using namespace std;

// 리턴 타입을 bool 로 하고 평균값을 전달하기 위해 참조 매개 변수를 추가함
bool average(int a[], int size, int &avg)
{
    if (size <= 0)
        return false;

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i];

    // 참조 매개 변수 avg 에 평균값 전달
    avg = sum / size;
    return true;
}

int main()
{
    int x[] = {0, 1, 2, 3, 4, 5};
    int avg;

    // avg 값은 평균값
    if (average(x, 6, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개 변수 오류" << endl;

    // avg 값은 의미 없음
    if (average(x, -2, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개 변수 오류" << endl;
}

/*
평균은 2
매개 변수 오류
*/