// 정수형 배열의 동적 할당 및 반환
#include <iostream>
using namespace std;

int main()
{
    cout << "입력할 정수의 개수는?";
    int n;
    cin >> n;

    if (n <= 0)
        return 0;
    // n 개의 정수 배열 및 동적 할당
    int *p = new int[n];
    if (!p)
    {
        cout << "메모리를 할당할 수 없습니다.";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "번째 정수 : ";
        cin >> p[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i];
    }

    cout << "평균 = " << sum / n << endl;

    // 배열 메모리 반환
    delete[] p;
}

/*
입력할 정수의 개수는?4
1번째 정수 : 3
2번째 정수 : 5
3번째 정수 : -23
4번째 정수 : 5
평균 = -2

- 배열의 동적 할당 및 반환
new 와 delete 연산자로 배열을 할당받고 반환할 수 있다

- 배열의 동적 할당/반환의 기본 형식
// 배열의 동적 할당
데이터타입 *포인터변수 = new 데이터타입 [배열의 크기]
// 배열 메모리 반환
delte [] 포인터변수;

new 연산자는 '배열의 크기' 만한 배열을 할당받아 주소를 리턴하며,
delete 는 '포인터변수' 가 가리키는 배열 메모리를 반환한다

new 를 이용하면 int, char 등의 기본 타입과 구조체, 클래스 등 사용자가 정의한 타입의 배열을 할당받을 수 있다
*/