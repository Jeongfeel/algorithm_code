//Baekjoon #2589
//algorithm : bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 50;

char treasureMap[MAX_NUMBER][MAX_NUMBER];
int minimumDistanceMap[MAX_NUMBER][MAX_NUMBER];

void initMinimumDistanceMap();
void findMinimumDistance(int currentHeight, int currentWidth);

int moveableWidth[] = { 1,-1,0,0 };
int moveableHeight[] = { 0,0,1,-1 };

int maxDistance = 0;

int height, width;

int main() {
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> treasureMap[i][j];
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (treasureMap[i][j] == 'W') {
				continue;
			}
			
			findMinimumDistance(i, j);
		}
	}

	cout << maxDistance << '\n';
}

void initMinimumDistanceMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			minimumDistanceMap[i][j] = -1;
		}
	}
}

void findMinimumDistance(int startHeight, int startWidth) {
	initMinimumDistanceMap();

	pair<int, int> currentCoordinate = make_pair(startHeight, startWidth);

	queue<pair<int, int>> moveableCoordinate;
	moveableCoordinate.push(currentCoordinate);
	minimumDistanceMap[startHeight][startWidth] = 0;

	while (!moveableCoordinate.empty()) {
		pair<int, int> currentCoordinate = moveableCoordinate.front();
		moveableCoordinate.pop();

		int currentHeight = currentCoordinate.first;
		int currentWidth = currentCoordinate.second;

		if (minimumDistanceMap[currentHeight][currentWidth] > maxDistance) {
			maxDistance = minimumDistanceMap[currentHeight][currentWidth];
		}

		for (int i = 0; i < 4; i++) {
			int nextHeight = currentHeight + moveableHeight[i];
			int nextWidth = currentWidth + moveableWidth[i];

			if (nextHeight < 0 || nextHeight == height || nextWidth < 0 || nextWidth == width) {
				continue;
			}

			if (treasureMap[nextHeight][nextWidth] == 'W') {
				continue;
			}

			if (minimumDistanceMap[nextHeight][nextWidth] == -1) {
				minimumDistanceMap[nextHeight][nextWidth] = minimumDistanceMap[currentHeight][currentWidth] + 1;
				
				pair<int, int> nextCoordinate = make_pair(nextHeight, nextWidth);				
				moveableCoordinate.push(nextCoordinate);
			}
		}
	}
}
