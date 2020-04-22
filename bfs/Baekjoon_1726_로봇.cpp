/*
	problem site	:	baekjoon
	problem number	:	1726
	problem name	:	로봇
	algorithm	:	bfs
*/

#include <iostream>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

const int MAX_NUMBER = 100;
const int POSSIBLE = 0;
const int IMPOSSIBLE = 1;
const int COUNT_OF_DIRECTION = 4;
const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

int factory[MAX_NUMBER + 1][MAX_NUMBER + 1];
bool isVisitedPositionAndDirection[MAX_NUMBER + 1][MAX_NUMBER + 1][COUNT_OF_DIRECTION + 1];

void findMinimumOrder();
bool isFoundMinimumWay(int robotXCoordinate, int robotYCoordinate, int robotDirection);

int N, M;
int robotXCoordinate, robotYCoordinate, robotDirection;
int destinationXCoordinate, destinationYCoordinate, destinationDirection;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> factory[i][j];
		}
	}

	cin >> robotXCoordinate >> robotYCoordinate >> robotDirection;
	cin >> destinationXCoordinate >> destinationYCoordinate >> destinationDirection;

	findMinimumOrder();
}

void findMinimumOrder() {
	isVisitedPositionAndDirection[robotXCoordinate][robotYCoordinate][robotDirection] = true;

	queue<pair<tuple<int, int, int>, int>> robotPositionAndOrderCountQueue;

	robotPositionAndOrderCountQueue.push(make_pair(make_tuple(robotXCoordinate, robotYCoordinate, robotDirection), 0));

	while (!robotPositionAndOrderCountQueue.empty()) {
		pair<tuple<int, int, int>, int> robotPositionAndOrderCount = robotPositionAndOrderCountQueue.front();
		robotPositionAndOrderCountQueue.pop();

		int currentXCoordinate = get<0>(robotPositionAndOrderCount.first);
		int currentYCoordinate = get<1>(robotPositionAndOrderCount.first);
		int currentDirection = get<2>(robotPositionAndOrderCount.first);
		int currentOrderCount = robotPositionAndOrderCount.second;

		if (isFoundMinimumWay(currentXCoordinate, currentYCoordinate, currentDirection) == true) {
			cout << currentOrderCount << "\n";
			break;
		}

		if (currentDirection == EAST) {
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][NORTH] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, NORTH), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][NORTH] = true;
			}
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][SOUTH] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, SOUTH), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][SOUTH] = true;
			}

			for (int i = 1; i <= 3; i++) {
				int nextYCoordinate = currentYCoordinate + i;
				if (nextYCoordinate > M) {
					break;
				}

				if (factory[currentXCoordinate][nextYCoordinate] == IMPOSSIBLE) {
					break;
				}

				if (isVisitedPositionAndDirection[currentXCoordinate][nextYCoordinate][currentDirection] == true) {
					continue;
				}

				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, nextYCoordinate, currentDirection), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][nextYCoordinate][currentDirection] = true;
			}
		} else if (currentDirection == WEST) {
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][NORTH] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, NORTH), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][NORTH] = true;
			}
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][SOUTH] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, SOUTH), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][SOUTH] = true;
			}

			for (int i = 1; i <= 3; i++) {
				int nextYCoordinate = currentYCoordinate - i;
				if (nextYCoordinate == 0) {
					break;
				}

				if (factory[currentXCoordinate][nextYCoordinate] == IMPOSSIBLE) {
					break;
				}
				
				if (isVisitedPositionAndDirection[currentXCoordinate][nextYCoordinate][currentDirection] == true) {
					continue;
				}

				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, nextYCoordinate, currentDirection), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][nextYCoordinate][currentDirection] = true;
			}
		}
		else if (currentDirection == NORTH) {
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][EAST] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, EAST), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][EAST] = true;
			} 
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][WEST] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, WEST), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][WEST] = true;
			}

			for (int i = 1; i <= 3; i++) {
				int nextXCoordinate = currentXCoordinate - i;
				if (nextXCoordinate == 0) {
					break;
				}

				if (factory[nextXCoordinate][currentYCoordinate] == IMPOSSIBLE) {
					break;
				}

				if (isVisitedPositionAndDirection[nextXCoordinate][currentYCoordinate][currentDirection] == true) {
					continue;
				}

				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(nextXCoordinate, currentYCoordinate, currentDirection), currentOrderCount + 1));
				isVisitedPositionAndDirection[nextXCoordinate][currentYCoordinate][currentDirection] = true;
			}
		}
		else if (currentDirection == SOUTH) {
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][EAST] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, EAST), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][EAST] = true;
			}
			if (isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][WEST] == false) {
				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(currentXCoordinate, currentYCoordinate, WEST), currentOrderCount + 1));
				isVisitedPositionAndDirection[currentXCoordinate][currentYCoordinate][WEST] = true;
			}

			for (int i = 1; i <= 3; i++) {
				int nextXCoordinate = currentXCoordinate + i;
				if (nextXCoordinate > N) {
					break;
				}

				if (factory[nextXCoordinate][currentYCoordinate] == IMPOSSIBLE) {
					break;
				}

				if (isVisitedPositionAndDirection[nextXCoordinate][currentYCoordinate][currentDirection] == true) {
					continue;
				}

				robotPositionAndOrderCountQueue.push(make_pair(make_tuple(nextXCoordinate, currentYCoordinate, currentDirection), currentOrderCount + 1));
				isVisitedPositionAndDirection[nextXCoordinate][currentYCoordinate][currentDirection] = true;
			}
		}
 	}
}

bool isFoundMinimumWay(int robotXCoordinate, int robotYCoordinate, int robotDirection) {
	if (robotXCoordinate != destinationXCoordinate || robotYCoordinate != destinationYCoordinate || robotDirection != destinationDirection) {
		return false;
	}

	return true;
}