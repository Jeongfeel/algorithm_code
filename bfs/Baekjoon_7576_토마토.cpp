/*
	problem site	:	baekjoon
	problem number	:	7576
	problem name	:	토마토
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_LENGTH_OF_TOMATO_BOX = 1000;
const int NOT_RIPPEN_TOMATO = 0;
const int RIPPEN_TOMATO = 1;
const int ROTTER_TOMATO = -1;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

int tomatoBox[MAX_LENGTH_OF_TOMATO_BOX][MAX_LENGTH_OF_TOMATO_BOX];
int rippenTimeTomatoBox[MAX_LENGTH_OF_TOMATO_BOX][MAX_LENGTH_OF_TOMATO_BOX];

void printAllTomatoRipenTime();

int width, height;
int main() {
	cin >> width >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tomatoBox[i][j];
		}
	}

	printAllTomatoRipenTime();
}

void printAllTomatoRipenTime() {
	queue<pair<int, int>> rippenTomatoQueue;
	int countOfTomato = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (tomatoBox[i][j] == ROTTER_TOMATO) {
				continue;
			}
			if (tomatoBox[i][j] == RIPPEN_TOMATO) {
				rippenTomatoQueue.push(make_pair(i, j));
			}
			countOfTomato += 1;
		}
	}

	while (!rippenTomatoQueue.empty()) {
		countOfTomato -= 1;

		int currentXCoordinate = rippenTomatoQueue.front().first;
		int currentYCoordinate = rippenTomatoQueue.front().second;

		rippenTomatoQueue.pop();
		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate == height || nextYCoordinate < 0 || nextYCoordinate == width) {
				continue;
			}
			if (tomatoBox[nextXCoordinate][nextYCoordinate] == ROTTER_TOMATO) {
				continue;
			}
			if (tomatoBox[nextXCoordinate][nextYCoordinate] == RIPPEN_TOMATO) {
				continue;
			}

			tomatoBox[nextXCoordinate][nextYCoordinate] = RIPPEN_TOMATO;
			rippenTimeTomatoBox[nextXCoordinate][nextYCoordinate] = rippenTimeTomatoBox[currentXCoordinate][currentYCoordinate] + 1;

			rippenTomatoQueue.push(make_pair(nextXCoordinate, nextYCoordinate));
		}
	}
	
	if (countOfTomato > 0) {
		cout << "-1" << '\n';
	}
	else {
		int rippenTime = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (rippenTimeTomatoBox[i][j] > rippenTime) {
					rippenTime = rippenTimeTomatoBox[i][j];
				}
			}
		}

		cout << rippenTime << '\n';
	}
}