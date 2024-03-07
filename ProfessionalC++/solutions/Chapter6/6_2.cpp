// sum() 함수 중복 연습
#include <iostream>
using namespace std;

int sum(int a, int b)
{
    int s = 0;
    for (int i = 0; i <= b; i++)
        s += i;
    return s;
}

int sum(int a)
{
    int s = 0;
    for (int i = 0; i <= a; i++)
        s += i;
    return s;
}

int main()
{
    cout << sum(3, 5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;
}

/*
15
6
5050
*/