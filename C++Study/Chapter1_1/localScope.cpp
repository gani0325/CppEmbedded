#include <iostream>

using namespace std;

int main() {
	int x = 0;
	cout << x << " " << &x << endl;

	{
		// 지역 변수 : 영역 벗어나면 사용 X
		// 차지하고 있던 메모리는 스택 메모리로 반납
		// x == 0; 이면 값 같게 나옴!!
		int x = 0;
		cout << x << " " << &x << endl; 
		// x의 주소값이 다름!!
	}
}