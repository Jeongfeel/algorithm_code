//baekjoon #9507
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 67;
long long koongFibonacci[MAX_NUMBER + 1];

void findKoongFibonacci(int number);

int main() {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int number;

		cin >> number;

		findKoongFibonacci(number);
	}
}

void findKoongFibonacci(int number) {
	koongFibonacci[0] = 1;
	koongFibonacci[1] = 1;
	koongFibonacci[2] = 2;
	koongFibonacci[3] = 4;

	for (int i = 4; i <= number; i++) {
		koongFibonacci[i] = koongFibonacci[i - 4] + koongFibonacci[i - 3] + koongFibonacci[i - 2] + koongFibonacci[i - 1];
	}

	cout << koongFibonacci[number] << '\n';
}