// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// 2�ܺ��� 9�ܱ��� ������
	for (int i = 2; i < 10; i++) {
		cout << i << "������" << endl;
		for (int j = 1; j < 10; j++) {
			cout << i << " * " << j << " = " << (i * j) << endl;
		}
	}	
	return 0;
}