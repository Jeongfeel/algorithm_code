/*
	problem site	:	baekjoon
	problem number	:	1261
	problem name	:	알고스팟
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_LENGTH_OF_MAZE = 100;
const char BLANK = '0';
const char WALL = '1';

char maze[MAX_LENGTH_OF_MAZE + 1][MAX_LENGTH_OF_MAZE + 1];
int minimumCountOfBrokenWall[MAX_LENGTH_OF_MAZE + 1][MAX_LENGTH_OF_MAZE + 1];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void initMinimumCountOfBorkenWall();
void checkMinimumCountOfBrokenWall();

int N, M;
int main() {
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	checkMinimumCountOfBrokenWall();

	cout << minimumCountOfBrokenWall[N][M] << '\n';
}

void checkMinimumCountOfBrokenWall() {
	initMinimumCountOfBorkenWall();

	queue<pair<int, int>> currentPositionQueue;

	currentPositionQueue.push(make_pair(1, 1));

	while (!currentPositionQueue.empty()) {
		pair<int, int> currentPosition = currentPositionQueue.front();
		currentPositionQueue.pop();

		int currentXCoordinate = currentPosition.first;
		int currentYCoordinate = currentPosition.second;
		int currentBrokenWallCount = minimumCountOfBrokenWall[currentXCoordinate][currentYCoordinate];

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];
			int nextBrokenWallCount = currentBrokenWallCount;

			if (nextXCoordinate == 0 || nextXCoordinate > N || nextYCoordinate == 0 || nextYCoordinate > M) {
				continue;
			}

			if (maze[nextXCoordinate][nextYCoordinate] == WALL) {
				nextBrokenWallCount += 1;
			}

			if (nextBrokenWallCount >= minimumCountOfBrokenWall[nextXCoordinate][nextYCoordinate]) {
				continue;
			}

			minimumCountOfBrokenWall[nextXCoordinate][nextYCoordinate] = nextBrokenWallCount;
			currentPositionQueue.push(make_pair(nextXCoordinate, nextYCoordinate));
		}
	}
}

void initMinimumCountOfBorkenWall() {
	for (int i = 1; i <= MAX_LENGTH_OF_MAZE; i++) {
		for (int j = 1; j <= MAX_LENGTH_OF_MAZE; j++) {
			minimumCountOfBrokenWall[i][j] = 1024 * 1024 * 1024 * 2 - 1;
		}
	}

	minimumCountOfBrokenWall[1][1] = 0;
}