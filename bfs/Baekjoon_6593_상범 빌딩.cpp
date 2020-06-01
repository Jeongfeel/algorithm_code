/*
	problem site	:	baekjoon
	problem number	:	6593
	problem name	:	상범 빌딩
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX_NUMBER_OF_BUILDING = 30;
const char START = 'S';
const char END = 'E';
const char WALL = '#';

int moveZCoordinate[] = { 1,-1,0,0,0,0 };
int moveYCoordinate[] = { 0,0,1,-1,0,0 };
int moveXCoordinate[] = { 0,0,0,0,1,-1 };

char building[MAX_NUMBER_OF_BUILDING][MAX_NUMBER_OF_BUILDING][MAX_NUMBER_OF_BUILDING];
int placeArriveTime[MAX_NUMBER_OF_BUILDING][MAX_NUMBER_OF_BUILDING][MAX_NUMBER_OF_BUILDING];

bool isCloseCondition(int L, int R, int C);
void printMinimumQuitTime();
void initPlaceArriveTime();
tuple<int, int, int> getStartCoordinate();

int L, R, C;
int main() {
	while (true) {
		cin >> L >> R >> C;

		if (isCloseCondition(L, R, C) == true) {
			break;
		}

		printMinimumQuitTime();
	}
}

bool isCloseCondition(int L, int R, int C) {
	if (L == 0 && R == 0 && C == 0) {
		return true;
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> building[i][j][k];
			}
		}
	}

	return false;
}

void printMinimumQuitTime() {
	initPlaceArriveTime();

	tuple<int, int, int> startCoordinate = getStartCoordinate();
	queue<tuple<int, int, int>> coordinateQueue;
	coordinateQueue.push(startCoordinate);

	while (!coordinateQueue.empty()) {
		int zCoordinate = get<0>(coordinateQueue.front());
		int yCoordinate = get<1>(coordinateQueue.front());
		int xCoordinate = get<2>(coordinateQueue.front());
		coordinateQueue.pop();

		if (building[zCoordinate][yCoordinate][xCoordinate] == END) {
			cout << "Escaped in "<<placeArriveTime[zCoordinate][yCoordinate][xCoordinate] <<" minute(s)." << '\n';
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nextZCoordinate = zCoordinate + moveZCoordinate[i];
			int nextYCoordinate = yCoordinate + moveYCoordinate[i];
			int nextXCoordinate = xCoordinate + moveXCoordinate[i];

			if (nextZCoordinate < 0 || nextZCoordinate == L || nextYCoordinate < 0 || nextYCoordinate == R || nextXCoordinate < 0 || nextXCoordinate == C) {
				continue;
			}
			if (building[nextZCoordinate][nextYCoordinate][nextXCoordinate] == WALL) {
				continue;
			}
			if (placeArriveTime[nextZCoordinate][nextYCoordinate][nextXCoordinate] != 0) {
				continue;
			}

			placeArriveTime[nextZCoordinate][nextYCoordinate][nextXCoordinate] = placeArriveTime[zCoordinate][yCoordinate][xCoordinate] + 1;
			coordinateQueue.push(make_tuple(nextZCoordinate, nextYCoordinate, nextXCoordinate));
		}
	}

	cout << "Trapped!" << '\n';
}

void initPlaceArriveTime() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				placeArriveTime[i][j][k] = 0;
			}
		}
	}
}

tuple<int, int, int> getStartCoordinate() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (building[i][j][k] == START) {
					return make_tuple(i, j, k);
				}
			}
		}
	}
}