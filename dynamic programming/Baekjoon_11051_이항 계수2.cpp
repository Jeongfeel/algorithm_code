/*
	problem site	:	baekjoon
	problem number	:	11051
	problem name	:	이항 계수2
	algorithm	:	dynamic programming
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000;
const int DIVIDE_NUMBER = 10007;

int binomialCoefficient[MAX_NUMBER + 1][MAX_NUMBER + 1];

void initBinomialCoefficient();
void checkBinomialCoefficient();

int main() {
	int N, K;
	cin >> N >> K;

	initBinomialCoefficient();
	checkBinomialCoefficient();

	cout << binomialCoefficient[N][K] << '\n';
}

void initBinomialCoefficient() {
	for (int i = 0; i <= MAX_NUMBER; i++) {
		binomialCoefficient[i][0] = 1;
	}
}

void checkBinomialCoefficient() {
	for (int i = 1; i <= MAX_NUMBER; i++) {
		for (int j = 1; j <= i; j++) {
			binomialCoefficient[i][j] = binomialCoefficient[i - 1][j - 1] + binomialCoefficient[i - 1][j];
			binomialCoefficient[i][j] %= DIVIDE_NUMBER;
		}
	}
}