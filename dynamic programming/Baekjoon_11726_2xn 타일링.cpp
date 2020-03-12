//baekjoon #11726
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000 + 1;
const int DIVIDE_NUMBER = 10007;

int numberOfFilledSquare[MAX_NUMBER];

void getNumberOfFilledSquare(int number);

int main() {
	int number;
	cin >> number;

	getNumberOfFilledSquare(number);

	cout << numberOfFilledSquare[number];
}

void getNumberOfFilledSquare(int number) {
	numberOfFilledSquare[1] = 1;
	numberOfFilledSquare[2] = 2;

	for (int i = 3; i <= number; i++) {
		numberOfFilledSquare[i] = numberOfFilledSquare[i - 2] + numberOfFilledSquare[i - 1];
		numberOfFilledSquare[i] %= DIVIDE_NUMBER;
	}
}
