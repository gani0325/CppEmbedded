#include <iostream>

using namespace std;

int addTwoNumbers(int a, int b) {
	int sum = a + b;
	return sum;
}

int multiplyTwoNumbers(int a, int b) {
	int sum = a * b;
	return sum;
}

void printHelloWorld() {
	cout << "Hello World" << endl;
}

int main() {
	cout << addTwoNumbers(3, 4) << endl;
	cout << multiplyTwoNumbers(2, 5) << endl;
	printHelloWorld();
	return 0;
}