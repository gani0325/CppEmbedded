#include <iostream>

using namespace std;

int main() {
	int x = 0;
	cout << x << " " << &x << endl;

	{
		// ���� ���� : ���� ����� ��� X
		// �����ϰ� �ִ� �޸𸮴� ���� �޸𸮷� �ݳ�
		// x == 0; �̸� �� ���� ����!!
		int x = 0;
		cout << x << " " << &x << endl; 
		// x�� �ּҰ��� �ٸ�!!
	}
}