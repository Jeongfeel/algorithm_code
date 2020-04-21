/*
	problem site	:	baekjoon
	problem number	:	1051
	problem name	:	숫자 정사각형
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 50;

char rectangle[MAX_NUMBER][MAX_NUMBER];

void checkLargeSquare();

int N, M;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> rectangle[i][j];
		}
	}

	checkLargeSquare();
}

void checkLargeSquare() {
	int currentLargeSquare = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int currentNumber = rectangle[i][j] - '0';
			
			int startNumber = 1;
			while (true) {
				if (i + startNumber == N) {
					break;
				}
				if (j + startNumber == M) {
					break;
				}

				if ((rectangle[i][j + startNumber] - '0') != currentNumber || (rectangle[i + startNumber][j] - '0') != currentNumber || (rectangle[i + startNumber][j + startNumber] - '0') != currentNumber) {
					startNumber += 1;
					continue;
				}

				if (currentLargeSquare > startNumber + 1) {
					startNumber += 1;
					continue;
				}

				currentLargeSquare = startNumber + 1;
				startNumber += 1;
			}
		}
	}

	cout << currentLargeSquare * currentLargeSquare << '\n';
}