/*
	problem site	:	baekjoon
	problem number	:	2503
	problem name	:	숫자야구
	algorithm	:	brute force
*/

#include <iostream>
#include <string>
using namespace std;

bool possibleNumberBaseball[10][10][10];

void initPossibleNumberBaseball();
void checkPossibleNumberBaseball(string threeDigitNumber, int countOfStrike, int countOfBall);
void printPossibleNumber();

int main() {
	int countOfQuestion;
	cin >> countOfQuestion;
	
	initPossibleNumberBaseball();
	while (countOfQuestion--) {
		string threeDigitNumber;
		cin >> threeDigitNumber;

		int countOfStrike, countOfBall;
		cin >> countOfStrike >> countOfBall;

		checkPossibleNumberBaseball(threeDigitNumber, countOfStrike, countOfBall);
	}

	printPossibleNumber();
}

void initPossibleNumberBaseball() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (i == j || j == k || k == i) {
					continue;
				}

				possibleNumberBaseball[i][j][k] = true;
			}
		}
	}
}

void checkPossibleNumberBaseball(string threeDigitNumber, int countOfStrike, int countOfBall) {
	int currentFirstNumber = threeDigitNumber[0] - '0';
	int currentSecondNumber = threeDigitNumber[1] - '0';
	int currentThirdNumber = threeDigitNumber[2] - '0';

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				int currentCountOfStrike = 0;
				int currentCountOfBall = 0;

				if (currentFirstNumber == i) {
					currentCountOfStrike += 1;
				}
				else if (currentFirstNumber == j || currentFirstNumber == k) {
					currentCountOfBall += 1;
				}

				if (currentSecondNumber == j) {
					currentCountOfStrike += 1;
				}
				else if (currentSecondNumber == i || currentSecondNumber == k) {
					currentCountOfBall += 1;
				}

				if (currentThirdNumber == k) {
					currentCountOfStrike += 1;
				}
				else if (currentThirdNumber == i || currentThirdNumber == j) {
					currentCountOfBall += 1;
				}

				if (currentCountOfStrike == countOfStrike && currentCountOfBall == countOfBall) {
					continue;
				}

				possibleNumberBaseball[i][j][k] = false;
			}
		}
	}
}

void printPossibleNumber() {
	int countOfPossibleNumber = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (possibleNumberBaseball[i][j][k] == true) {
					countOfPossibleNumber += 1;
				}
			}
		}
	}

	cout << countOfPossibleNumber << endl;
}