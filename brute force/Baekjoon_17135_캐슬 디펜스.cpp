/*
	problem site	:	baekjoon
	problem number	:	17135
	problem name	:	캐슬 디펜스
	algorithm	:	brute force
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int MAX_NUMBER = 15;
const int MAX_DISPOSED_ARCHER = 3;
const int BLANK = 0;
const int ENEMY = 1;
const int ATTACKED_ENEMY = 2;

int originalPlaceOfEnemy[MAX_NUMBER][MAX_NUMBER];
int placeOfEnemy[MAX_NUMBER][MAX_NUMBER];

void disposeArcherAndAttackEnemy();
void checkMaximumCountOfKilledEnemy(vector<pair<int, int>> archerCoordinate, int &currentKilledEnemy);
bool isRemainedEnemy();
void killedEnemy(vector<pair<int, int>> archerCoordinate);
void checkKilledEnemyByArcherCoordinateIndex(pair<int,int> archerCoordinate);
void moveForward(int &currentKilledEnemy);

int maximumKilledEnemy = 0;

int N, M, D;
int main() {
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> originalPlaceOfEnemy[i][j];
		}
	}

	disposeArcherAndAttackEnemy();
	cout << maximumKilledEnemy << '\n';
}

void disposeArcherAndAttackEnemy() {
	vector<int> permutationVector;
	
	for (int i = 0; i < M - MAX_DISPOSED_ARCHER; i++) {
		permutationVector.push_back(0);
	}
	for (int i = 0; i < MAX_DISPOSED_ARCHER; i++) {
		permutationVector.push_back(1);
	}

	do {
		vector<pair<int, int>> archerCoordinate;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				placeOfEnemy[i][j] = originalPlaceOfEnemy[i][j];
			}
		}
		
		for (int i = 0; i < M; i++) {
			if (permutationVector[i] == 0) {
				continue;
			}
			archerCoordinate.push_back(make_pair(N, i));
		}
		
		int currentKilledEnemy = 0;
		checkMaximumCountOfKilledEnemy(archerCoordinate, currentKilledEnemy);

	} while (next_permutation(permutationVector.begin(), permutationVector.end()));
}

void checkMaximumCountOfKilledEnemy(vector<pair<int, int>> archerCoordinate, int &currentKilledEnemy) {
	if (isRemainedEnemy() == true) {
		killedEnemy(archerCoordinate);
		moveForward(currentKilledEnemy);
		checkMaximumCountOfKilledEnemy(archerCoordinate, currentKilledEnemy);
	}
	else {
		if (maximumKilledEnemy < currentKilledEnemy) {
			maximumKilledEnemy = currentKilledEnemy;
		}
	}
}

bool isRemainedEnemy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (placeOfEnemy[i][j] == BLANK) {
				continue;
			}

			return true;
		}
	}

	return false;
}

void killedEnemy(vector<pair<int, int>> archerCoordinate) {
	for (int i = 0; i < archerCoordinate.size(); i++) {
		checkKilledEnemyByArcherCoordinateIndex(archerCoordinate[i]);
	}
}

void checkKilledEnemyByArcherCoordinateIndex(pair<int, int> archerCoordinate) {
	int xCoordinateOfArcher = archerCoordinate.first;
	int yCoordinateOfArcher = archerCoordinate.second;

	int xCoordinateOfEnemy = MAX_NUMBER, yCoordinateOfEnemy = MAX_NUMBER;
	int currentMinimumDistance = 100;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (placeOfEnemy[i][j] == BLANK) {
				continue;
			}

			int distanceOfEnemy = abs(i - xCoordinateOfArcher) + abs(j - yCoordinateOfArcher);
			if (distanceOfEnemy > D) {
				continue;
			}
			if (distanceOfEnemy > currentMinimumDistance) {
				continue;
			}
			if (distanceOfEnemy == currentMinimumDistance) {
				if (j > yCoordinateOfEnemy) {
					continue;
				}
			}

			currentMinimumDistance = distanceOfEnemy;
			xCoordinateOfEnemy = i;
			yCoordinateOfEnemy = j;
		}
	}

	if (xCoordinateOfEnemy != MAX_NUMBER && yCoordinateOfEnemy != MAX_NUMBER) {
		placeOfEnemy[xCoordinateOfEnemy][yCoordinateOfEnemy] = ATTACKED_ENEMY;
	}
}

void moveForward(int &currentKilledEnemy) {
	for (int i = 0; i < M; i++) {
		if (placeOfEnemy[N - 1][i] == ATTACKED_ENEMY) {
			currentKilledEnemy += 1;
		}
		placeOfEnemy[N - 1][i] = BLANK;
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (placeOfEnemy[i][j] == BLANK) {
				continue;
			}

			if (placeOfEnemy[i][j] == ATTACKED_ENEMY) {
				placeOfEnemy[i][j] = BLANK;
				currentKilledEnemy += 1;
				
				continue;
			}

			placeOfEnemy[i + 1][j] = ENEMY;
			placeOfEnemy[i][j] = BLANK;
		}
	}
}
