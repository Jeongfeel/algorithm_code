/*
	problem site	:	baekjoon
	problem number	:	4963
	problem name	:	섬의 개수
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_LENGTH_OF_MAP = 50;
const int SEA = 0;
const int LAND = 1;

int map[MAX_LENGTH_OF_MAP][MAX_LENGTH_OF_MAP];
bool isVistedMap[MAX_LENGTH_OF_MAP][MAX_LENGTH_OF_MAP];

int moveXCoordiante[] = { 1,-1,0,0,1,1,-1,-1 };
int moveYCoordiante[] = { 0,0,1,-1,1,-1,1,-1 };

bool isWidthAndHeightNotZero(int height, int width);
void printCountOfLand(int height ,int width);
void initIsVistedMap();
void checkAdjacentLand(int xCoordinate, int yCoordinate, int height, int width);

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;

		if (isWidthAndHeightNotZero(w, h) == false) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		printCountOfLand(h, w);
	}
}

bool isWidthAndHeightNotZero(int height, int width) {
	if (width == 0 && height == 0) {
		return false;
	}

	return true;
}

void printCountOfLand(int height, int width) {
	initIsVistedMap();

	int countOfLand = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == SEA) {
				continue;
			}

			if (isVistedMap[i][j] == true) {
				continue;
			}

			countOfLand += 1;
			checkAdjacentLand(i, j, height, width);
		}
	}

	cout << countOfLand << '\n';
}

void initIsVistedMap() {
	for (int i = 0; i < MAX_LENGTH_OF_MAP; i++) {
		for (int j = 0; j < MAX_LENGTH_OF_MAP; j++) {
			isVistedMap[i][j] = false;
		}
	}
}

void checkAdjacentLand(int xCoordinate, int yCoordinate, int height, int width) {
	isVistedMap[xCoordinate][yCoordinate] = true;
	queue<pair<int, int>> landCoordinateQueue;
	landCoordinateQueue.push(make_pair(xCoordinate, yCoordinate));

	while (!landCoordinateQueue.empty()) {
		int currentXCoordinate = landCoordinateQueue.front().first;
		int currentYCoordinate = landCoordinateQueue.front().second;

		landCoordinateQueue.pop();

		for (int i = 0; i < 8; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordiante[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordiante[i];

			if (nextXCoordinate < 0 || nextXCoordinate == height || nextYCoordinate < 0 || nextYCoordinate == width) {
				continue;
			}
			if (map[nextXCoordinate][nextYCoordinate] == SEA) {
				continue;
			}
			if (isVistedMap[nextXCoordinate][nextYCoordinate] == true) {
				continue;
			}

			isVistedMap[nextXCoordinate][nextYCoordinate] = true;
			landCoordinateQueue.push(make_pair(nextXCoordinate, nextYCoordinate));
		}
	}
}