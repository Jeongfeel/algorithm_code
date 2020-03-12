//baekjoon #10844
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 100;
const int DIVIDE_NUMBER = 1000000000;

int countOfStairNumber[MAX_NUMBER + 1][10];

void setCountOfStairNumber(int number) {
	int result = 0;

	for (int i = 1; i < 10; i++) {
		countOfStairNumber[1][i] = 1;
	}
	
	for (int i = 2; i < number + 1; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				countOfStairNumber[i][0] += countOfStairNumber[i - 1][1];
			}
			else if (j == 9) {
				countOfStairNumber[i][9] += countOfStairNumber[i - 1][8];
			}
			else {
				countOfStairNumber[i][j] = countOfStairNumber[i - 1][j - 1] + countOfStairNumber[i - 1][j + 1];
			}

			countOfStairNumber[i][j] %= DIVIDE_NUMBER;
		}
	}

	for (int i = 0; i < 10; i++) {
		result += countOfStairNumber[number][i];
		result %= DIVIDE_NUMBER;
	}

	cout << result;
}

int main() {
	int number;

	cin >> number;

	setCountOfStairNumber(number);
}