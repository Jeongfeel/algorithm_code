//Baekjoon #2573
//algorithm : bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 300;
const int NOT_EXIST_ICEBERG = 0;

int checkEastAndWest[] = { 1,-1,0,0 };
int checkSouthAndNorth[] = { 0,0,1,-1 };

int originalIcebergMap[MAX_NUMBER][MAX_NUMBER];
int changedIcebergMap[MAX_NUMBER][MAX_NUMBER];
bool checkCloseIceberg[MAX_NUMBER][MAX_NUMBER];

bool isDividedIceberg();
void initCheckCloseIceberg();
void meltIceberg();
void changeIcebergHeight(int width, int height);
void changeOriginalIcebergMap();
bool isMeltedWholeIceberg();

int N, M;
int timeOfDividedIceberg;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> originalIcebergMap[i][j];
		}
	}

	while (isDividedIceberg() == false) {
		meltIceberg();
		timeOfDividedIceberg += 1;
		
		if (isMeltedWholeIceberg() == true) {
			cout << "0" << '\n';
			return 0;
		}
	}

	cout << timeOfDividedIceberg << '\n';
}

bool isDividedIceberg() {
	int countOfIceberg = 0;
	pair<int, int> startIcebergCoordinate;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (originalIcebergMap[i][j] == NOT_EXIST_ICEBERG) {
				continue;
			}

			countOfIceberg += 1;
			startIcebergCoordinate.first = i;
			startIcebergCoordinate.second = j;
		}
	}

	initCheckCloseIceberg();

	queue<pair<int, int>> closeIcebergQueue;
	closeIcebergQueue.push(startIcebergCoordinate);
	checkCloseIceberg[startIcebergCoordinate.first][startIcebergCoordinate.second] = 1;

	while (!closeIcebergQueue.empty()) {
		pair<int, int> currentIcebergCoordinate = closeIcebergQueue.front();
		closeIcebergQueue.pop();
		countOfIceberg -= 1;

		for (int i = 0; i < 4; i++) {
			int closeIcebergXCoordinate = currentIcebergCoordinate.first + checkEastAndWest[i];
			int closeIcebergYCoordinate = currentIcebergCoordinate.second + checkSouthAndNorth[i];

			if (closeIcebergXCoordinate < 0 || closeIcebergXCoordinate == N || closeIcebergYCoordinate < 0 || closeIcebergYCoordinate == M) {
				continue;
			}

			if (originalIcebergMap[closeIcebergXCoordinate][closeIcebergYCoordinate] == 0) {
				continue;
			}

			if (checkCloseIceberg[closeIcebergXCoordinate][closeIcebergYCoordinate] == 1) {
				continue;
			}

			checkCloseIceberg[closeIcebergXCoordinate][closeIcebergYCoordinate] = 1;

			pair<int, int> closeIcebergCoordinate = make_pair(closeIcebergXCoordinate, closeIcebergYCoordinate);
			closeIcebergQueue.push(closeIcebergCoordinate);
		}
	}

	if (countOfIceberg == 0) {
		return false;
	}
	else {
		return true;
	}
}

void initCheckCloseIceberg() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			checkCloseIceberg[i][j] = 0;
		}
	}
}

void meltIceberg() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (originalIcebergMap[i][j] == 0) {
				continue;
			}

			changeIcebergHeight(i, j);
		}
	}

	changeOriginalIcebergMap();
}

void changeIcebergHeight(int width, int height) {
	int decreaseHeight = 0;
	
	for (int i = 0; i < 4; i++) {
		int newWidth = width + checkEastAndWest[i];
		int newHeight = height + checkSouthAndNorth[i];

		if (newWidth < 0 || newWidth == N || newHeight < 0 || newHeight == M) {
			continue;
		}

		if (originalIcebergMap[newWidth][newHeight] == 0) {
			decreaseHeight += 1;
		}
	}

	changedIcebergMap[width][height] = originalIcebergMap[width][height] - decreaseHeight;
}

void changeOriginalIcebergMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (changedIcebergMap[i][j] < 0) {
				originalIcebergMap[i][j] = 0;
			}
			else {
				originalIcebergMap[i][j] = changedIcebergMap[i][j];
			}
		}
	}
}

bool isMeltedWholeIceberg() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (originalIcebergMap[i][j] == NOT_EXIST_ICEBERG) {
				continue;
			}

			return false;
		}
	}

	return true;
}
