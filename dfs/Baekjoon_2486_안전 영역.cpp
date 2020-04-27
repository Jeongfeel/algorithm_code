/*
	problem site	:	baekjoon
	problem number	:	2486
	problem name	:	안전 영역
	algorithm	:	dfs
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 100;
const int UNSAFETY_ZONE = 0;
const int SAFETY_ZONE = 1;

int moveX[] = { 1,-1,0,0 };
int moveY[] = { 0,0,1,-1 };

int map[MAX_NUMBER][MAX_NUMBER];
bool isVisitedMap[MAX_NUMBER][MAX_NUMBER];

int maximumCountOfSafetyZone = 0;

void checkMaximumSafetyZone(int precipitation);
void checkSafetyZone(int xCoordinate, int yCoordinate);

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= MAX_NUMBER; i++) {
		checkMaximumSafetyZone(i);
	}

	cout << maximumCountOfSafetyZone << '\n';
}

void checkMaximumSafetyZone(int precipitation) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > precipitation) {
				isVisitedMap[i][j] = SAFETY_ZONE;
			}
			else {
				isVisitedMap[i][j] = UNSAFETY_ZONE;
			}
		}
	}

	int countOfSafetyZone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisitedMap[i][j] == UNSAFETY_ZONE) {
				continue;
			}

			checkSafetyZone(i, j);
			countOfSafetyZone += 1;
		}
	}

	if (maximumCountOfSafetyZone < countOfSafetyZone) {
		maximumCountOfSafetyZone = countOfSafetyZone;
	}
}

void checkSafetyZone(int xCoordinate, int yCoordinate) {
	isVisitedMap[xCoordinate][yCoordinate] = UNSAFETY_ZONE;

	for (int i = 0; i < 4; i++) {
		int nextXCoordinate = xCoordinate + moveX[i];
		int nextYCoordinate = yCoordinate + moveY[i];

		if (nextXCoordinate < 0 || nextXCoordinate == N || nextYCoordinate < 0 || nextYCoordinate == N) {
			continue;
		}

		if (isVisitedMap[nextXCoordinate][nextYCoordinate] == UNSAFETY_ZONE) {
			continue;
		}

		checkSafetyZone(nextXCoordinate, nextYCoordinate);
	}
}