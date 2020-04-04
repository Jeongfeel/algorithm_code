/*
	problem site	:	baekjoon
	problem number	:	1789
	problem name	:	수들의 합
	algorithm	:	math
*/

#include <iostream>
using namespace std;

int main() {
	long long S;
	cin >> S;

	long long currentNumber = 1;
	long long currentSum = 0;

	while (currentSum + currentNumber <= S) {
		currentSum += currentNumber;
		currentNumber += 1;
	}

	cout << currentNumber - 1 << '\n';
}