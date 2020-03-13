//baekjoon #1904
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000000 + 1;
const int DIVIDE_NUMBER = 15746;

int numberOfMakeableTile[MAX_NUMBER];

void initNumberOfMakeableTile();

int main() {
	int number;
	cin >> number;

	initNumberOfMakeableTile();

	for (int i = 3; i <= number; i++) {
		numberOfMakeableTile[i] = numberOfMakeableTile[i - 2] + numberOfMakeableTile[i - 1];
		numberOfMakeableTile[i] %= DIVIDE_NUMBER;
	}

	cout << numberOfMakeableTile[number] << '\n';
}

void initNumberOfMakeableTile() {
	numberOfMakeableTile[1] = 1;
	numberOfMakeableTile[2] = 2;
}
