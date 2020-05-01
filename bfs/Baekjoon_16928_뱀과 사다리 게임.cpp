/*
	problem site	:	baekjoon
	problem number	:	16928
	problem name	:	뱀과 사다리 게임
	algorithm	:	bfs
*/

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int MAX_NUMBER_OF_MAP = 100;
const int LADDER = 1;
const int SNAKE = 2;
const int DESTINATION = 100;

int stateOfMap[MAX_NUMBER_OF_MAP + 1];
int movingMap[MAX_NUMBER_OF_MAP + 1];
bool isVisitedMap[MAX_NUMBER_OF_MAP + 1];

void checkMinimumCountOfDestination();

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int placeOfLadder, movingPlaceOfLadder;

		cin >> placeOfLadder >> movingPlaceOfLadder;
		stateOfMap[placeOfLadder] = LADDER;
		movingMap[placeOfLadder] = movingPlaceOfLadder;
	}
	for (int i = 0; i < M; i++) {
		int placeOfSnake, movingPlaceOfSnake;

		cin >> placeOfSnake >> movingPlaceOfSnake;
		stateOfMap[placeOfSnake] = SNAKE;
		movingMap[placeOfSnake] = movingPlaceOfSnake;
	}

	checkMinimumCountOfDestination();
}

void checkMinimumCountOfDestination() {
	queue<pair<int, int>> placeAndCountOfSnakeQueue;
	placeAndCountOfSnakeQueue.push(make_pair(1, 0));

	isVisitedMap[1] = true;

	while (!placeAndCountOfSnakeQueue.empty()) {
		int currentSnakePlace = placeAndCountOfSnakeQueue.front().first;
		int currentCount = placeAndCountOfSnakeQueue.front().second;

		placeAndCountOfSnakeQueue.pop();
		
		if (currentSnakePlace == DESTINATION) {
			cout << currentCount << '\n';
			break;
		}
		
		for (int i = 1; i <= 6; i++) {
			int nextPlaceOfSnake = currentSnakePlace + i;

			if (nextPlaceOfSnake > 100) {
				break;
			}

			if (stateOfMap[nextPlaceOfSnake] == LADDER || stateOfMap[nextPlaceOfSnake] == SNAKE) {
				nextPlaceOfSnake = movingMap[nextPlaceOfSnake];
			}

			if (isVisitedMap[nextPlaceOfSnake] == true) {
				continue;
			}

			isVisitedMap[nextPlaceOfSnake] = true;
			pair<int, int> nextPlaceAndCountOfSnake = make_pair(nextPlaceOfSnake, currentCount + 1);
			placeAndCountOfSnakeQueue.push(nextPlaceAndCountOfSnake);
		}
	}
}