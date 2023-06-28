// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// 2단부터 9단까지 구구단
	for (int i = 2; i < 10; i++) {
		cout << i << "구구단" << endl;
		for (int j = 1; j < 10; j++) {
			cout << i << " * " << j << " = " << (i * j) << endl;
		}
	}	
	return 0;
}