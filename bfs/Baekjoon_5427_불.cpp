/*
	problem site	:	baekjoon
	problem number	:	5427
	problem name	:	불
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX_LENGTH_OF_BUILDING = 1000;
const char BLANK = '.';
const char WALL = '#';
const char SANGEUN = '@';
const char FIRE = '*';

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

char building[MAX_LENGTH_OF_BUILDING][MAX_LENGTH_OF_BUILDING];

void printMinimumTimeToEscape(int w, int h);

int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int w, h;
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
			}
		}

		printMinimumTimeToEscape(h, w);
	}
}

void printMinimumTimeToEscape(int w, int h) {
	queue<tuple<int, int, int>> positionAndTimeQueue;

	tuple<int, int, int> sangeunPosition;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (building[i][j] == FIRE) {
				positionAndTimeQueue.push({ i,j,0 });
			}
			else if (building[i][j] == SANGEUN) {
				sangeunPosition = { i,j,0 };
			}
		}
	}
	positionAndTimeQueue.push(sangeunPosition);

	while (!positionAndTimeQueue.empty()) {
		int currentXCoordinate = get<0>(positionAndTimeQueue.front());
		int currentYCoordinate = get<1>(positionAndTimeQueue.front());
		int currentTime = get<2>(positionAndTimeQueue.front());
		positionAndTimeQueue.pop();

		if (building[currentXCoordinate][currentYCoordinate] == SANGEUN) {
			if (currentXCoordinate == 0 || currentYCoordinate == 0 || currentXCoordinate == w - 1 || currentYCoordinate == h - 1) {
				cout << currentTime + 1 << '\n';
				return;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate == w || nextYCoordinate < 0 || nextYCoordinate == h) {
				continue;
			}
			if (building[nextXCoordinate][nextYCoordinate] == WALL) {
				continue;
			}

			if (building[currentXCoordinate][currentYCoordinate] == FIRE) {
				if (building[nextXCoordinate][nextYCoordinate] == BLANK) {
					building[nextXCoordinate][nextYCoordinate] = FIRE;
					positionAndTimeQueue.push({ nextXCoordinate,nextYCoordinate,currentTime + 1 });
				}
			}
			else if (building[currentXCoordinate][currentYCoordinate] == SANGEUN) {
				if (building[nextXCoordinate][nextYCoordinate] == BLANK) {
					building[nextXCoordinate][nextYCoordinate] = SANGEUN;
					positionAndTimeQueue.push({ nextXCoordinate,nextYCoordinate,currentTime + 1 });
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE" << '\n';
}