// Chapter1_9

#include <iostream>
using namespace std;

int main()
{
	// º°Âï±â
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}