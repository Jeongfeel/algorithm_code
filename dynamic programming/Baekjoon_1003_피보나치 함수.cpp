//baekjoon #1003
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 40 + 1;

int numberOfZeroOnFibonacci[MAX_NUMBER];
int numberOfOneOnFibonacci[MAX_NUMBER];

void countNumberOfFibonacci(int number); 

int main() {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int number;
		cin >> number;

		countNumberOfFibonacci(number);
		cout << numberOfZeroOnFibonacci[number] << " " << numberOfOneOnFibonacci[number] << '\n';
	}
}

void countNumberOfFibonacci(int number) {
	numberOfZeroOnFibonacci[0] = 1;
	numberOfZeroOnFibonacci[1] = 0;
	numberOfOneOnFibonacci[0] = 0;
	numberOfOneOnFibonacci[1] = 1;

	for (int i = 2; i <= number; i++) {
		numberOfZeroOnFibonacci[i] = numberOfZeroOnFibonacci[i - 2] + numberOfZeroOnFibonacci[i - 1];
		numberOfOneOnFibonacci[i] = numberOfOneOnFibonacci[i - 2] + numberOfOneOnFibonacci[i - 1];
	}
}
