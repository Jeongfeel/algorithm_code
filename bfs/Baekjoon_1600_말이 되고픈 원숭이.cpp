/*
	problem site	:	baekjoon
	problem number	:	1600
	problem name	:	말이 되고픈 원숭이
	algorithm	:	bfs
*/

#include <iostream>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

const int MAX_NUMBER = 200;
const int MAX_MOVING_OF_HORSE = 30 + 1;
const int PALIN = 0;
const int OBSTACLE = 1;
const int COUNT_OF_MONKEY_MOVE = 4;
const int COUNT_OF_HORSE_MOVE = 8;

int moveXOfMonkey[] = { 1,-1,0,0 };
int moveYOfMonkey[] = { 0,0,1,-1 };
int moveXOfHorse[] = { -2,-2,-1,-1,1,1,2,2 };
int moveYOfHorse[] = { 1,-1,2,-2,2,-2,1,-1 };

int world[MAX_NUMBER][MAX_NUMBER];
bool isVisitedMonkeyMove[MAX_MOVING_OF_HORSE][MAX_NUMBER][MAX_NUMBER];
bool isVisitedHorseMove[MAX_MOVING_OF_HORSE][MAX_NUMBER][MAX_NUMBER];

void checkMonkeyMove(int xCoordinate, int yCoordinate);

int K;
int W, H;
int main() {
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> world[i][j];
		}
	}

	checkMonkeyMove(0, 0);
}

void checkMonkeyMove(int xCoordinate, int yCoordinate) {
	queue <tuple <pair<int, int>, int, int >> monkeyPossibleMove;
	monkeyPossibleMove.push(make_tuple(make_pair(xCoordinate, yCoordinate), K, 0));

	isVisitedMonkeyMove[K][xCoordinate][yCoordinate] = true;
	isVisitedHorseMove[K][xCoordinate][yCoordinate] = true;

	while (!monkeyPossibleMove.empty()) {
		int currentXCoordinate = get<0>(monkeyPossibleMove.front()).first;
		int currentYCoordinate = get<0>(monkeyPossibleMove.front()).second;
		int currentHorseMoving = get<1>(monkeyPossibleMove.front());
		int currentMovingCount = get<2>(monkeyPossibleMove.front());

		monkeyPossibleMove.pop();

		if (currentXCoordinate == H - 1 && currentYCoordinate == W - 1) {
			cout << currentMovingCount << '\n';
			return;
		}

		for (int i = 0; i < COUNT_OF_MONKEY_MOVE; i++) {
			int nextXCoordinate = currentXCoordinate + moveXOfMonkey[i];
			int nextYCoordinate = currentYCoordinate + moveYOfMonkey[i];

			if (nextXCoordinate < 0 || nextXCoordinate == H || nextYCoordinate < 0 || nextYCoordinate == W) {
				continue;
			}

			if (world[nextXCoordinate][nextYCoordinate] == OBSTACLE) {
				continue;
			}

			if (isVisitedMonkeyMove[currentHorseMoving][nextXCoordinate][nextYCoordinate] == true) {
				continue;
			}

			isVisitedMonkeyMove[currentHorseMoving][nextXCoordinate][nextYCoordinate] = true;
			monkeyPossibleMove.push(make_tuple(make_pair(nextXCoordinate, nextYCoordinate), currentHorseMoving, currentMovingCount + 1));
		}

		if (currentHorseMoving == 0) {
			continue;
		}

		for (int i = 0; i < COUNT_OF_HORSE_MOVE; i++) {
			int nextXCoordinate = currentXCoordinate + moveXOfHorse[i];
			int nextYCoordinate = currentYCoordinate + moveYOfHorse[i];

			if (nextXCoordinate < 0 || nextXCoordinate >= H || nextYCoordinate < 0 || nextYCoordinate >= W) {
				continue;
			}

			if (world[nextXCoordinate][nextYCoordinate] == OBSTACLE) {
				continue;
			}

			if (isVisitedHorseMove[currentHorseMoving][nextXCoordinate][nextYCoordinate] == true) {
				continue;
			}

			isVisitedHorseMove[currentHorseMoving][nextXCoordinate][nextYCoordinate] = true;
			monkeyPossibleMove.push(make_tuple(make_pair(nextXCoordinate, nextYCoordinate), currentHorseMoving - 1, currentMovingCount + 1));
		}
	}

	cout << "-1" << '\n';
}