/*
	problem site	:	baekjoon
	problem number	:	4179
	problem name	:	불!
	algorithm	:	bfs
*/

#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

const int MAX_LENGTH_OF_MAZE = 1001;
const char WALL = '#';
const char BLANK = '.';
const char JIHOON = 'J';
const char FIRE = 'F';

char maze[MAX_LENGTH_OF_MAZE][MAX_LENGTH_OF_MAZE];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void pushFirePosition(queue<tuple<int,int, int>> &positionQueue);
void pushJihoonPosition(queue<tuple<int,int, int>> &positionQueue);
void checkEscapeTime(queue<tuple<int, int, int>> positionQueue);

int R, C;
int main() {
	cin >> R >> C;

	queue<tuple<int, int, int>> positionQueue;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
		}
	}

	pushFirePosition(positionQueue);
	pushJihoonPosition(positionQueue);
	checkEscapeTime(positionQueue);
}

void pushFirePosition(queue <tuple <int, int, int>> &positionQueue) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == FIRE) {
				positionQueue.push(make_tuple(i, j, 0));
			}
		}
	}
}

void pushJihoonPosition(queue <tuple<int, int, int>> &positionQueue) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == JIHOON) {
				positionQueue.push(make_tuple(i, j, 0));
			}
		}
	}
}

void checkEscapeTime(queue<tuple<int, int, int>> positionQueue) {
	while (!positionQueue.empty()) {
		int currentXCoordinate = get<0>(positionQueue.front());
		int currentYCoordinate = get<1>(positionQueue.front());
		int currentTime = get<2>(positionQueue.front());

		positionQueue.pop();

		if (maze[currentXCoordinate][currentYCoordinate] == JIHOON && (currentXCoordinate == 0 || currentYCoordinate == 0 || currentXCoordinate == R - 1 || currentYCoordinate == C - 1)) {
			cout << currentTime + 1 << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate == R || nextYCoordinate < 0 || nextYCoordinate == C) {
				continue;
			}

			if (maze[nextXCoordinate][nextYCoordinate] == WALL) {
				continue;
			}

			if (maze[currentXCoordinate][currentYCoordinate] == FIRE) {
				if (maze[nextXCoordinate][nextYCoordinate] == BLANK) {
					maze[nextXCoordinate][nextYCoordinate] = FIRE;
					positionQueue.push(make_tuple(nextXCoordinate, nextYCoordinate, currentTime + 1));
				}
			}

			if (maze[currentXCoordinate][currentYCoordinate] == JIHOON) {
				if (maze[nextXCoordinate][nextYCoordinate] == BLANK) {
					maze[nextXCoordinate][nextYCoordinate] = JIHOON;
					positionQueue.push(make_tuple(nextXCoordinate, nextYCoordinate, currentTime + 1));
				}
			}
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}