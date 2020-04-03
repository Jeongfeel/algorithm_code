//Baekjoon #15685
//algorithm : simulation

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 100 + 1;
bool wholeCoordinatePlane[MAX_NUMBER][MAX_NUMBER];
bool dragonCurveCoordinatePlane[MAX_NUMBER][MAX_NUMBER];

void makeDragonCurveCoordinatePlane(int xCoordinate, int yCoordinate, int direction, int generation);
void initDragonCurveCoordinatePlane(pair<int, int> currentCoordinate, pair<int, int> finalCoordinate, queue<pair<int, int>> &currentDragonCurveCoordinate);
void makeNextCoordinate(int direction, int &nextX, int &nextY);
void drawDragonCurveAtCoordinatePlane(pair<int, int> currentCoordinate, pair<int, int> finalCoordinate, queue<pair<int, int>> &currentDragonCurveCoordinate);
pair<int, int> makeFinalCoordinate(pair<int, int> startCoordinate, pair<int, int> finalCoordinate);
void drawDragonCurveAtWholeCoordinatePlane();
void printCountOfSquare();

int main() {
	int numberOfDragonCurve;
	cin >> numberOfDragonCurve;

	while (numberOfDragonCurve--) {
		int xCoordinate, yCoordinate, direction, generation;
		cin >> xCoordinate >> yCoordinate >> direction >> generation;

		makeDragonCurveCoordinatePlane(xCoordinate, yCoordinate, direction, generation);
	}

	printCountOfSquare();
}

void makeDragonCurveCoordinatePlane(int xCoordinate, int yCoordinate, int direction, int generation) {
	int startX = xCoordinate;
	int startY = yCoordinate;
	int finalX = xCoordinate;
	int finalY = yCoordinate;
	makeNextCoordinate(direction, finalX, finalY);

	pair<int, int> startCoordinate = make_pair(startX, startY);
	pair<int, int> finalCoordinate = make_pair(finalX, finalY);

	queue<pair<int, int>> currentDragonCurveCoordinate;
	initDragonCurveCoordinatePlane(startCoordinate, finalCoordinate, currentDragonCurveCoordinate);

	while (generation--) {
		int currentDragonCurvePointSize = currentDragonCurveCoordinate.size();

		while (currentDragonCurvePointSize--) {
			pair<int, int> currentCoordinate = currentDragonCurveCoordinate.front();
			currentDragonCurveCoordinate.pop();

			drawDragonCurveAtCoordinatePlane(currentCoordinate, finalCoordinate, currentDragonCurveCoordinate);
		}

		finalCoordinate = makeFinalCoordinate(startCoordinate, finalCoordinate);
	}

	drawDragonCurveAtWholeCoordinatePlane();
}

void initDragonCurveCoordinatePlane(pair<int, int> startCoordinate, pair<int, int> finalCoordinate, queue<pair<int, int>> &currentDragonCurveCoordinate) {
	for (int i = 0; i < MAX_NUMBER; i++) {
		for (int j = 0; j < MAX_NUMBER; j++) {
			dragonCurveCoordinatePlane[i][j] = 0;
		}
	}
	dragonCurveCoordinatePlane[startCoordinate.first][startCoordinate.second] = 1;
	dragonCurveCoordinatePlane[finalCoordinate.first][finalCoordinate.second] = 1;

	currentDragonCurveCoordinate.push(startCoordinate);
	currentDragonCurveCoordinate.push(finalCoordinate);
}

void makeNextCoordinate(int direction, int &nextX, int &nextY) {
	if (direction == 0) {
		nextX += 1;
	}
	else if (direction == 1) {
		nextY -= 1;
	}
	else if (direction == 2) {
		nextX -= 1;
	}
	else if (direction == 3) {
		nextY += 1;
	}
}

void drawDragonCurveAtCoordinatePlane(pair<int, int> currentCoordinate, pair<int, int> finalCoordinate, queue<pair<int, int>> &currentDragonCurveCoordinate) {
	currentDragonCurveCoordinate.push(currentCoordinate);

	int nextX = -(currentCoordinate.second - finalCoordinate.second) + finalCoordinate.first;
	int nextY = currentCoordinate.first - finalCoordinate.first + finalCoordinate.second;

	dragonCurveCoordinatePlane[nextX][nextY] = 1;

	pair<int, int> nextCoordinate = make_pair(nextX, nextY);
	currentDragonCurveCoordinate.push(nextCoordinate);
}

pair<int, int> makeFinalCoordinate(pair<int, int> startCoordinate, pair<int, int> finalCoordinate) {
	int finalX = -(startCoordinate.second - finalCoordinate.second) + finalCoordinate.first;
	int finalY = startCoordinate.first - finalCoordinate.first + finalCoordinate.second;

	return make_pair(finalX, finalY);
}

void drawDragonCurveAtWholeCoordinatePlane() {
	for (int i = 0; i < MAX_NUMBER; i++) {
		for (int j = 0; j < MAX_NUMBER; j++) {
			if (dragonCurveCoordinatePlane[i][j] == 1) {
				wholeCoordinatePlane[i][j] = dragonCurveCoordinatePlane[i][j];
			}
		}
	}
}

void printCountOfSquare() {
	int countOfSquare = 0;

	for (int i = 0; i < MAX_NUMBER - 1; i++) {
		for (int j = 0; j < MAX_NUMBER - 1; j++) {
			if (wholeCoordinatePlane[i][j] == 1) {
				if (wholeCoordinatePlane[i + 1][j] == 1 && wholeCoordinatePlane[i][j + 1] == 1 && wholeCoordinatePlane[i + 1][j + 1] == 1) {
					countOfSquare += 1;
				}
			}
		}
	}

	cout << countOfSquare << '\n';
}
