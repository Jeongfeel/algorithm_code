/*
	problem site	:	baekjoon
	problem number	:	17144
	problem name	:	미세먼지 안녕!
	algorithm	:	simulation
*/

#include <iostream>
#include <utility>
using namespace std;

const int MAX_NUMBER = 50;
const int CLEAN_ROBOT = -1;
const int NO_DUST = 0;

int moveDustXCoordinate[] = { 1,-1,0,0 };
int moveDustYCoordinate[] = { 0,0,1,-1 };


int room[MAX_NUMBER + 1][MAX_NUMBER + 1];
int newRoom[MAX_NUMBER + 1][MAX_NUMBER + 1];

void checkDustCount();
pair<int,int> findCleanRobot();
void initNewRoom(int firstCleanRobotPosition, int secondCleanRobotPosition);
void spreadDust();
void activateFirstCleanRobot(int firstCleanRobotPosition);
void activateSecondCleanRobot(int secondCleanRobotPosition);
void printCountOfDust();

int R, C, T;
int main() {
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> room[i][j];
		}
	}

	checkDustCount();
}

void checkDustCount() {
	pair<int, int> positionOfCleanRobot = findCleanRobot();

	int firstCleanRobotPosition = positionOfCleanRobot.first;
	int secondCleanRobotPosition = positionOfCleanRobot.second;

	while (T--) {
		initNewRoom(firstCleanRobotPosition, secondCleanRobotPosition);
		spreadDust();
		activateFirstCleanRobot(firstCleanRobotPosition);
		activateSecondCleanRobot(secondCleanRobotPosition);
	}

	printCountOfDust();
}

pair<int, int> findCleanRobot() {
	for (int i = 1; i <= R; i++) {
		if (room[i][1] != CLEAN_ROBOT) {
			continue;
		}

		return make_pair(i, i + 1);
	}
}

void initNewRoom(int firstCleanRobotPosition, int secondCleanRobotPosition) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			newRoom[i][j] = NO_DUST;
		}
	}

	newRoom[firstCleanRobotPosition][1] = CLEAN_ROBOT;
	newRoom[secondCleanRobotPosition][1] = CLEAN_ROBOT;
}

void spreadDust() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (room[i][j] == NO_DUST) {
				continue;
			}

			if (room[i][j] == CLEAN_ROBOT) {
				continue;
			}

			int quantityOfDust = room[i][j] / 5;
			int quantityOfSpreadDust = 0;

			for (int k = 0; k < 4; k++) {
				int nextDustXCoordinate = i + moveDustXCoordinate[k];
				int nextDustYCoordinate = j + moveDustYCoordinate[k];

				if (nextDustXCoordinate == 0 || nextDustXCoordinate > R || nextDustYCoordinate == 0 || nextDustYCoordinate > C) {
					continue;
				}

				if (room[nextDustXCoordinate][nextDustYCoordinate] == CLEAN_ROBOT) {
					continue;
				}

				newRoom[nextDustXCoordinate][nextDustYCoordinate] += quantityOfDust;
				quantityOfSpreadDust += quantityOfDust;
			}

			newRoom[i][j] += (room[i][j] - quantityOfSpreadDust);
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			room[i][j] = newRoom[i][j];
		}
	}
}

void activateFirstCleanRobot(int firstCleanRobotPosition) {
	for (int i = firstCleanRobotPosition - 2; i >= 1; i--) {
		room[i + 1][1] = room[i][1];
	}
	for (int i = 2; i <= C; i++) {
		room[1][i - 1] = room[1][i];
	}
	for (int i = 1; i < firstCleanRobotPosition; i++) {
		room[i][C] = room[i + 1][C];
	}
	for (int i = C; i > 2; i--) {
		room[firstCleanRobotPosition][i] = room[firstCleanRobotPosition][i - 1];
	}
	room[firstCleanRobotPosition][2] = NO_DUST;
}

void activateSecondCleanRobot(int secondCleanRobotPosition) {
	for (int i = secondCleanRobotPosition + 2; i <= R; i++) {
		room[i - 1][1] = room[i][1];
	}
	for (int i = 2; i <= C; i++) {
		room[R][i - 1] = room[R][i];
	}
	for (int i = R; i > secondCleanRobotPosition; i--) {
		room[i][C] = room[i - 1][C];
	}
	for (int i = C; i > 2; i--) {
		room[secondCleanRobotPosition][i] = room[secondCleanRobotPosition][i - 1];
	}
	room[secondCleanRobotPosition][2] = NO_DUST;
}

void printCountOfDust() {
	int countOfDust = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (room[i][j] == NO_DUST) {
				continue;
			}
			if (room[i][j] == CLEAN_ROBOT) {
				continue;
			}

			countOfDust += room[i][j];
		}
	}

	cout << countOfDust << '\n';
}