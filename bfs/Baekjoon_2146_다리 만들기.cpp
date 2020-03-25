/*
	problem site	:	baekjoon
	problem number	:	2146
	problem name	:	다리 만들기
	algorithm		:	bfs + dfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 100;
const int SEA = 0;
const int LAND = 1;
const int COUNT_OF_DIRECTION = 4;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

int groundOfCountry[MAX_NUMBER][MAX_NUMBER];
bool isVisitGroundOfCountry[MAX_NUMBER][MAX_NUMBER];

void findCoordinateOfIsland(int currentXCoordinate, int currentYCoordinate, queue<pair<int, int>> &coordinateOfIslandQueue);
void findMinimumLengthOfBridge(queue<pair<int, int>> &coordinateOfIslandQueue);
void clearGroundOfCountry();

int minimumLengthOfBridge = 1024 * 1024 * 1024 * 2 - 1;

int number;
int main() {
	cin >> number;

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cin >> groundOfCountry[i][j];

			if (groundOfCountry[i][j] == LAND) {
				pair<int, int> coordinateOfLand = make_pair(i, j);
			}
		}
	}

	queue<pair<int, int>> coordinateOfIslandQueue;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (groundOfCountry[i][j] == SEA) {
				continue;
			}
			
			if (isVisitGroundOfCountry[i][j] == true) {
				continue;
			}

			findCoordinateOfIsland(i, j, coordinateOfIslandQueue);
			findMinimumLengthOfBridge(coordinateOfIslandQueue);
			clearGroundOfCountry();
		}
	}

	cout << minimumLengthOfBridge - 1 << '\n';
}

void findCoordinateOfIsland(int currentXCoordinate, int currentYCoordinate, queue<pair<int, int>> &coordinateOfIslandQueue) {
	isVisitGroundOfCountry[currentXCoordinate][currentYCoordinate] = true;

	pair<int, int> coordinateOfIsland = make_pair(currentXCoordinate, currentYCoordinate);
	coordinateOfIslandQueue.push(coordinateOfIsland);

	for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
		int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
		int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

		if (nextXCoordinate < 0 || nextXCoordinate == number || nextYCoordinate < 0 || nextYCoordinate == number) {
			continue;
		}

		if (groundOfCountry[nextXCoordinate][nextYCoordinate] == SEA) {
			continue;
		}

		if (isVisitGroundOfCountry[nextXCoordinate][nextYCoordinate] == true) {
			continue;
		}

		findCoordinateOfIsland(nextXCoordinate, nextYCoordinate, coordinateOfIslandQueue);
	}

}

void findMinimumLengthOfBridge(queue<pair<int, int>> &coordinateOfIslandQueue) {
	while (!coordinateOfIslandQueue.empty()) {
		pair<int, int> currentCoordinateOfIsland = coordinateOfIslandQueue.front();
		coordinateOfIslandQueue.pop();

		int currentXCoordinate = currentCoordinateOfIsland.first;
		int currentYCoordinate = currentCoordinateOfIsland.second;

		for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate == number || nextYCoordinate < 0 || nextYCoordinate == number) {
				continue;
			}

			if (groundOfCountry[nextXCoordinate][nextYCoordinate] == LAND && isVisitGroundOfCountry[nextXCoordinate][nextYCoordinate] == true) {
				continue;
			}

			if (groundOfCountry[nextXCoordinate][nextYCoordinate] == LAND && isVisitGroundOfCountry[nextXCoordinate][nextYCoordinate] == false) {
				if (groundOfCountry[currentXCoordinate][currentYCoordinate] < minimumLengthOfBridge) {
					minimumLengthOfBridge = groundOfCountry[currentXCoordinate][currentYCoordinate];
				}
				
				continue;
			}
			
			if (groundOfCountry[nextXCoordinate][nextYCoordinate] == SEA) {
				groundOfCountry[nextXCoordinate][nextYCoordinate] = groundOfCountry[currentXCoordinate][currentYCoordinate] + 1;

				pair<int, int>nextCoordinateOfIsland = make_pair(nextXCoordinate, nextYCoordinate);
				coordinateOfIslandQueue.push(nextCoordinateOfIsland);
			}
		}
	}
}

void clearGroundOfCountry() {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (groundOfCountry[i][j] == LAND) {
				continue;
			}

			groundOfCountry[i][j] = SEA;
		}
	}
}