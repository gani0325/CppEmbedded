// 값에 의한 호출로 swap 함수 호출
#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int tmp;

    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int m = 2, n = 9;
    swap(m, n);
    cout << m << " " << n;
}

/*
2 9
*/

/*
- 함수의 인자 전달 방식
1) 값에 의한 호출 (call by value)
호출하는 코드에서 넘겨주는 실인자 값이 함수의 매개 변수에 복사되어 전달되는 방식

실인자의 값을 복사하여 전달하므로, 함수 내에서 실인자를 손상시킬 수 없는 장점이 있다
매개 변수 a, b 가 swap() 함수의 스택에 생성되고, m, n 값이 a, b에 복사된다
a와 b값이 서로 교환되고, swap() 함수가 종료하면 swap() 스택과 함께 a, b 도 사라지지만
main() 스택에 m, n 은 변함없이 2, 9 값을 유지한다

2) 주소에 의한 호출 (call by address)
주소를 직접 포인터 타입의 매개 변수에 전달받는 방식
함수 호출 시 배열이 전달되는 경우, 배열의 이름이 전달되므로 자연스럽게 주소에 의한 호출이 이뤄진다
배열의 이름은 곧 배열의 주소이다
*/