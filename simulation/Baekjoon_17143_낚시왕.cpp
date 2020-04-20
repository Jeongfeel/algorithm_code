/*
	problem site	:	baekjoon
	problem number	:	17143
	problem name	:	낚시왕
	algorithm	:	simulation
*/

#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

const int MAX_NUMBER_OF_FISHING_GROUND = 100;
const int DIRECTION_UP = 1;
const int DIRECTION_DOWN = 2;
const int DIRECTION_RIGHT = 3;
const int DIRECTION_LEFT = 4;

void catchShark(int anglerPosition);
void moveShark();
pair<int, int> moveUpAndDown(int currentPosition, int remainDistance, int direction);
pair<int, int> moveLeftAndRight(int currentPosition, int remainDistance, int direction);

tuple<int,int,int> fishingGround[MAX_NUMBER_OF_FISHING_GROUND + 1][MAX_NUMBER_OF_FISHING_GROUND + 1];
int weightOfCaughtShark = 0;

int R, C, M;
int main() {
	cin >> R >> C >> M;
	
	for (int i = 0; i < M; i++) {
		int xCoordinateOfShark, yCoordinateOfShark, speed, direction, size;
		cin >> xCoordinateOfShark >> yCoordinateOfShark >> speed >> direction >> size;

		fishingGround[xCoordinateOfShark][yCoordinateOfShark] = make_tuple(speed, direction, size);
	}

	for (int anglerPosition = 1; anglerPosition <= C; anglerPosition++) {
		catchShark(anglerPosition);
		moveShark();
	}

	cout << weightOfCaughtShark << '\n';
}

void catchShark(int anglerPosition) {
	for (int i = 1; i <= R; i++) {
		int sharkSize = get<2>(fishingGround[i][anglerPosition]);
		if (sharkSize == 0) {
			continue;
		}

		weightOfCaughtShark += sharkSize;
		fishingGround[i][anglerPosition] = make_tuple(0, 0, 0);
		break;
	}
}

void moveShark() {
	tuple<int, int, int> nextFishingGround[MAX_NUMBER_OF_FISHING_GROUND + 1][MAX_NUMBER_OF_FISHING_GROUND + 1];

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (get<2>(fishingGround[i][j]) == 0) {
				continue;
			}

			int remainDistance = get<0>(fishingGround[i][j]);
			int currentDirection = get<1>(fishingGround[i][j]);
			int currentSharkSize = get<2>(fishingGround[i][j]);
			
			if (currentDirection == DIRECTION_UP || currentDirection == DIRECTION_DOWN) {
				pair<int, int> nextSharkHeightAndDirection = moveUpAndDown(i, remainDistance, currentDirection);

				int nextHeight = nextSharkHeightAndDirection.first;
				int nextDirection = nextSharkHeightAndDirection.second;

				int nextSharkSize = get<2>(nextFishingGround[nextHeight][j]);
				if (nextSharkSize < currentSharkSize) {
					nextFishingGround[nextHeight][j] = make_tuple(remainDistance, nextDirection, currentSharkSize);
				}
			}
			else if (currentDirection == DIRECTION_LEFT || currentDirection == DIRECTION_RIGHT) {
				pair<int, int> nextSharkWidthAndDirection = moveLeftAndRight(j, remainDistance, currentDirection);

				int nextWidth = nextSharkWidthAndDirection.first;
				int nextDirection = nextSharkWidthAndDirection.second;

				int nextSharkSize = get<2>(nextFishingGround[i][nextWidth]);
				if (nextSharkSize < currentSharkSize) {
					nextFishingGround[i][nextWidth] = make_tuple(remainDistance, nextDirection, currentSharkSize);
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			fishingGround[i][j] = nextFishingGround[i][j];
		}
	}

}

pair<int, int> moveUpAndDown(int currentPosition, int remainDistance, int direction) {
	int nextPosition = currentPosition;
	int nextDirection = direction;

	while (remainDistance != 0) {
		if (direction == DIRECTION_UP) {
			if (currentPosition - 1 > remainDistance) {
				currentPosition -= remainDistance;
				remainDistance = 0;
			}
			else {
				remainDistance -= (currentPosition - 1);
				currentPosition = 1;
				direction = DIRECTION_DOWN;
			}
		}
		else if (direction == DIRECTION_DOWN) {
			if (R - currentPosition > remainDistance) {
				currentPosition += remainDistance;
				remainDistance = 0;
			}
			else {
				remainDistance -= (R - currentPosition);
				currentPosition = R;
				direction = DIRECTION_UP;
			}
		}
	}

	return make_pair(currentPosition, direction);
}

pair<int, int> moveLeftAndRight(int currentPosition, int remainDistance, int direction) {
	while (remainDistance != 0) {
		if (direction == DIRECTION_RIGHT) {
			if (C - currentPosition > remainDistance) {
				currentPosition += remainDistance;
				remainDistance = 0;
			}
			else {
				remainDistance -= (C - currentPosition);
				currentPosition = C;
				direction = DIRECTION_LEFT;
			}
		}
		else if (direction == DIRECTION_LEFT) {
			if (currentPosition - 1 > remainDistance) {
				currentPosition -= remainDistance;
				remainDistance = 0;
			}
			else {
				remainDistance -= (currentPosition - 1);
				currentPosition = 1;
				direction = DIRECTION_RIGHT;
			}
		}
	}

	return make_pair(currentPosition, direction);
}
