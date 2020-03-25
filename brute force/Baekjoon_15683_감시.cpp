/*
	problem site	:	baekjoon
	problem number	:	15683
	problem name	:	감시
	algorithm	:	brute force
*/

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int MAX_NUMBER = 8;
const int DEAD_ZONE = 0;
const int WALL = 6;
const int COUNT_OF_DIRECTION = 4;

int office[MAX_NUMBER][MAX_NUMBER];

void findMinimumDeadZone(queue<pair<int, int>> coordinateOfCCTVQueue);
void checkCountOfDeadZone();
void checkNumberOfCCTVAndDirection(int numberOfCCTV, int direction, queue<pair<int,int>> &monitoredCoordinateQueue);
void monitoredCCTVNumberOne(int direction, queue<pair<int,int>> &monitoredCoordinateQueue);
void monitoredCCTVNumberTwo(int direction, queue<pair<int, int>> &monitoredCoordinateQueue);
void monitoredCCTVNumberThree(int direction, queue<pair<int, int>> &monitoredCoordinateQueue);
void monitoredCCTVNumberFour(int direction, queue<pair<int, int>> &monitoredCoordinateQueue);
void monitoredCCTVNumberFive(int direction, queue<pair<int, int>> &monitoredCoordinateQueue);
void makeOriginalOfficeState(queue<pair<int,int>> monitoredCoordinateQueue);

int minimumCountOfDeadZone = 1024 * 1024 * 1024 * 2 - 1;

int N, M;
int main() {
	cin >> N >> M;

	queue<pair<int, int>> coordinateOfCCTVQueue;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];

			if (office[i][j] != DEAD_ZONE && office[i][j] != WALL) {
				pair<int, int> coordinateOfCCTV = make_pair(i, j);
				coordinateOfCCTVQueue.push(coordinateOfCCTV);
			}
		}
	}

	findMinimumDeadZone(coordinateOfCCTVQueue);
	cout << minimumCountOfDeadZone << '\n';
}

void findMinimumDeadZone(queue<pair<int, int>> coordinateOfCCTVQueue) {
	if (coordinateOfCCTVQueue.size() == 0) {
		checkCountOfDeadZone();
	}
	else {
		pair<int, int> currentCoordinateOfCCTV = coordinateOfCCTVQueue.front();
		coordinateOfCCTVQueue.pop();

		int xCoordinateOfCCTV = currentCoordinateOfCCTV.first;
		int yCoordinateOfCCTV = currentCoordinateOfCCTV.second;

		for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
			queue<pair<int, int>> monitoredCoordinateQueue;
			monitoredCoordinateQueue.push(currentCoordinateOfCCTV);

			checkNumberOfCCTVAndDirection(office[xCoordinateOfCCTV][yCoordinateOfCCTV], i, monitoredCoordinateQueue);
			findMinimumDeadZone(coordinateOfCCTVQueue);
			makeOriginalOfficeState(monitoredCoordinateQueue);
		}
	}
}

void checkCountOfDeadZone() {
	int countOfDeadZone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (office[i][j] == DEAD_ZONE) {
				countOfDeadZone += 1;
			}
		}
	}

	if (minimumCountOfDeadZone > countOfDeadZone) {
		minimumCountOfDeadZone = countOfDeadZone;
	}
}

void checkNumberOfCCTVAndDirection(int numberOfCCTV, int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	if (numberOfCCTV == 1) {
		monitoredCCTVNumberOne(direction, monitoredCoordinateQueue);
	}
	else if (numberOfCCTV == 2) {
		monitoredCCTVNumberTwo(direction, monitoredCoordinateQueue);
	}
	else if (numberOfCCTV == 3) {
		monitoredCCTVNumberThree(direction, monitoredCoordinateQueue);
	}
	else if (numberOfCCTV == 4) {
		monitoredCCTVNumberFour(direction, monitoredCoordinateQueue);
	}
	else if (numberOfCCTV == 5) {
		monitoredCCTVNumberFive(direction, monitoredCoordinateQueue);
	}
}

void monitoredCCTVNumberOne(int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	pair<int, int> currentCoordinateOfCCTV = monitoredCoordinateQueue.front();
	monitoredCoordinateQueue.pop();
	
	int currentXCoordinate = currentCoordinateOfCCTV.first;
	int currentYCoordinate = currentCoordinateOfCCTV.second;

	if (direction == 0) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}
	}
	else if (direction == 1) {
		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}
	}
	else if (direction == 2) {
		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 3) {
		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
}

void monitoredCCTVNumberTwo(int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	pair<int, int> currentCoordinateOfCCTV = monitoredCoordinateQueue.front();
	monitoredCoordinateQueue.pop();

	int currentXCoordinate = currentCoordinateOfCCTV.first;
	int currentYCoordinate = currentCoordinateOfCCTV.second;

	if (direction == 0 || direction == 2) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}
			
			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}
	}
	else if (direction == 1 || direction == 3) {
		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	
		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
}

void monitoredCCTVNumberThree(int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	pair<int, int> currentCoordinateOfCCTV = monitoredCoordinateQueue.front();
	monitoredCoordinateQueue.pop();

	int currentXCoordinate = currentCoordinateOfCCTV.first;
	int currentYCoordinate = currentCoordinateOfCCTV.second;

	if (direction == 0) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 1) {
		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 2) {
		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 3) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}
			
			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
}

void monitoredCCTVNumberFour(int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	pair<int, int> currentCoordinateOfCCTV = monitoredCoordinateQueue.front();
	monitoredCoordinateQueue.pop();

	int currentXCoordinate = currentCoordinateOfCCTV.first;
	int currentYCoordinate = currentCoordinateOfCCTV.second;

	if (direction == 0) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 1) {
		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
		
		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 2) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
	else if (direction == 3) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}

		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
}

void monitoredCCTVNumberFive(int direction, queue<pair<int, int>> &monitoredCoordinateQueue) {
	pair<int, int> currentCoordinateOfCCTV = monitoredCoordinateQueue.front();
	monitoredCoordinateQueue.pop();

	int currentXCoordinate = currentCoordinateOfCCTV.first;
	int currentYCoordinate = currentCoordinateOfCCTV.second;

	if (direction == 0 || direction == 1 || direction == 2 || direction == 3) {
		for (int i = currentYCoordinate + 1; i < M; i++) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentYCoordinate - 1; i >= 0; i--) {
			if (office[currentXCoordinate][i] == WALL) {
				break;
			}

			if (office[currentXCoordinate][i] != DEAD_ZONE) {
				continue;
			}

			office[currentXCoordinate][i] = -1;
			monitoredCoordinateQueue.push(make_pair(currentXCoordinate, i));
		}

		for (int i = currentXCoordinate + 1; i < N; i++) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}

		for (int i = currentXCoordinate - 1; i >= 0; i--) {
			if (office[i][currentYCoordinate] == WALL) {
				break;
			}

			if (office[i][currentYCoordinate] != DEAD_ZONE) {
				continue;
			}

			office[i][currentYCoordinate] = -1;
			monitoredCoordinateQueue.push(make_pair(i, currentYCoordinate));
		}
	}
}

void makeOriginalOfficeState(queue<pair<int, int>> monitoredCoordinateQueue) {
	while (!monitoredCoordinateQueue.empty()) {
		pair<int, int> currentMonitoredCoordinate = monitoredCoordinateQueue.front();
		monitoredCoordinateQueue.pop();

		int xCoordinateOfMonitoredCoordinate = currentMonitoredCoordinate.first;
		int yCoordinateOfMonitoredCoordinate = currentMonitoredCoordinate.second;

		office[xCoordinateOfMonitoredCoordinate][yCoordinateOfMonitoredCoordinate] = DEAD_ZONE;
	}
}