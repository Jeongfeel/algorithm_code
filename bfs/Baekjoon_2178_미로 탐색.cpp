/*
	problem site	:	baekjoon
	problem number	:	2178
	problem name	:	미로 탐색
	algorithm		:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;
const char IMPOSSIBLE_POSITION = '0';
const int NUMBER_OF_DIRECTION = 4;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

char maze[MAX_NUMBER + 1][MAX_NUMBER + 1];
int countOfMoving[MAX_NUMBER + 1][MAX_NUMBER + 1];

void checkMinimumCountOfMoving(queue<pair<int, int>> possibleMovingCoordinateQueue);

int N, M;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	queue<pair<int, int>> possibleMovingCoordinateQueue;
	pair<int, int> startCoordinate = make_pair(1, 1);

	possibleMovingCoordinateQueue.push(startCoordinate);
	countOfMoving[1][1] = 1;

	checkMinimumCountOfMoving(possibleMovingCoordinateQueue);

	cout << countOfMoving[N][M] << '\n';
}

void checkMinimumCountOfMoving(queue<pair<int, int>> possibleMovingCoordinateQueue) {
	while (!possibleMovingCoordinateQueue.empty()) {
		pair<int,int> currentCoordinate = possibleMovingCoordinateQueue.front();
		possibleMovingCoordinateQueue.pop();

		int currentXCoordinate = currentCoordinate.first;
		int currentYCoordinate = currentCoordinate.second;

		for (int i = 0; i < NUMBER_OF_DIRECTION; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < MIN_NUMBER || nextXCoordinate > N || nextYCoordinate < MIN_NUMBER || nextYCoordinate > M) {
				continue;
			}
			if (maze[nextXCoordinate][nextYCoordinate] == IMPOSSIBLE_POSITION) {
				continue;
			}
			if (countOfMoving[nextXCoordinate][nextYCoordinate] != 0) {
				continue;
			}

			countOfMoving[nextXCoordinate][nextYCoordinate] = countOfMoving[currentXCoordinate][currentYCoordinate] + 1;
			
			pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
			possibleMovingCoordinateQueue.push(nextCoordinate);
		}
	}
}