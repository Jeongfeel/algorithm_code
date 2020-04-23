/*
	problem site	:	baekjoon
	problem number	:	17822
	problem name	:	원판 돌리기
	algorithm	:	simulation
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER_OF_CIRCLE = 50;
const int BLANK = 0;
const int CLOCK_WISE = 0;
const int COUNTER_CLOCK_WISE = 1;

int circle[MAX_NUMBER_OF_CIRCLE + 1][MAX_NUMBER_OF_CIRCLE + 1];
int nextCircle[MAX_NUMBER_OF_CIRCLE + 1][MAX_NUMBER_OF_CIRCLE + 1];

void spinCircle(int indexOfCircle, int direction, int spinNumber);
void checkAdjacentNumberOfCircle();
void initNextCircle();
void spinCircleClockWise(int indexOfCircle, int spinNumber);
void spinCircleCounterClockWise(int indexOfCircle, int spinNumber);
void printSumOfRemainNumber();

int N, M, T;
int main() {
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> circle[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;

		if (x != 1) {
			spinCircle(x, d, k);
		}

		checkAdjacentNumberOfCircle();
	}

	printSumOfRemainNumber();
}

void spinCircle(int indexOfCircle, int direction, int spinNumber) {
	initNextCircle();

	if (direction == CLOCK_WISE) {
		spinCircleClockWise(indexOfCircle, spinNumber);
	}
	else if (direction == COUNTER_CLOCK_WISE) {
		spinCircleCounterClockWise(indexOfCircle, spinNumber);
	}
}

void checkAdjacentNumberOfCircle() {
	bool isDeleteNumber = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] == -1) {
				continue;
			}

			int firstCircleIndex = j;
			int secondCircleIndex = j + 1;
			if (secondCircleIndex > M) {
				secondCircleIndex = 1;
			}

			if (circle[i][firstCircleIndex] == circle[i][secondCircleIndex]) {
				nextCircle[i][firstCircleIndex] = -1;
				nextCircle[i][secondCircleIndex] = -1;

				isDeleteNumber = true;
			}
		}
	}
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j < N; j++) {
			if (circle[j][i] == -1) {
				continue;
			}

			int firstCircleIndex = j;
			int secondCircleIndex = j + 1;

			if (circle[firstCircleIndex][i] == circle[secondCircleIndex][i]) {
				nextCircle[firstCircleIndex][i] = -1;
				nextCircle[secondCircleIndex][i] = -1;

				isDeleteNumber = true;
			}
		}
	}
	
	if (isDeleteNumber == true) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (nextCircle[i][j] == -1) {
					circle[i][j] = -1;
				}
			}
		}
	}
	else if (isDeleteNumber == false) {
		int countOfExistNumber = 0;
		float averageNumber = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (circle[i][j] == -1) {
					continue;
				}

				countOfExistNumber += 1;
				averageNumber += circle[i][j];
			}
		}

		averageNumber /= countOfExistNumber;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (circle[i][j] == -1) {
					continue;
				}

				if (circle[i][j] > averageNumber) {
					circle[i][j] -= 1;
				}
				else if (circle[i][j] < averageNumber) {
					circle[i][j] += 1;
				}
			}
		}
	}
}

void initNextCircle() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			nextCircle[i][j] = BLANK;
		}
	}
}

void spinCircleClockWise(int indexOfCircle, int spinNumber) {
	for (int i = indexOfCircle; i <= N; i += indexOfCircle) {
		for (int j = 1; j <= M; j++) {
			int nextPosition = j + spinNumber;

			nextPosition %= M;
			if (nextPosition == 0) {
				nextPosition = M;
			}
			nextCircle[i][nextPosition] = circle[i][j];
		}

		for (int j = 1; j <= M; j++) {
			circle[i][j] = nextCircle[i][j];
		}
	}
}

void spinCircleCounterClockWise(int indexOfCircle, int spinNumber) {
	for (int i = indexOfCircle; i <= N; i += indexOfCircle) {
		for (int j = 1; j <= M; j++) {
			int nextPosition = spinNumber % M;
			nextPosition = M - nextPosition;
			nextPosition = j + nextPosition;
			nextPosition %= M;

			if (nextPosition == 0) {
				nextPosition = M;
			}

			nextCircle[i][nextPosition] = circle[i][j];
		}

		for (int j = 1; j <= M; j++) {
			circle[i][j] = nextCircle[i][j];
		}
	}
}

void printSumOfRemainNumber() {
	int sumOfRemainNumber = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] == -1) {
				continue;
			}

			sumOfRemainNumber += circle[i][j];
		}
	}

	cout << sumOfRemainNumber << '\n';
}