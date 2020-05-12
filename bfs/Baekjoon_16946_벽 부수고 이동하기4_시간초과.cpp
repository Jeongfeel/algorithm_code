/*
	problem site	:	baekjoon
	problem number	:	16946
	problem name	:	벽 부수고 이동하기4
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

const int MAX_NUMBER_OF_PLACE = 1000 + 1;
const char BLANK = '0';
const char WALL = '1';
const int NOT_VISITED = 0;
const int VISITED = -1;

char place[MAX_NUMBER_OF_PLACE][MAX_NUMBER_OF_PLACE];
int identiferPlace[MAX_NUMBER_OF_PLACE][MAX_NUMBER_OF_PLACE];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void makeIdentifierPlace();
void checkIdentiferPlace(int xCoordinate, int yCoordinate);
void makeAnswer();

map<int, int> identiferAndCountMap;

int N, M;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> place[i][j];
		}
	}

	makeIdentifierPlace();
	makeAnswer();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << place[i][j];
		}
		cout << endl;
	}
}

void makeIdentifierPlace() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (place[i][j] == WALL) {
				continue;
			}
			if (identiferPlace[i][j] != NOT_VISITED) {
				continue;
			}

			checkIdentiferPlace(i, j);
		}
	}
}

void checkIdentiferPlace(int xCoordinate, int yCoordinate) {
	static int identifer = 1;
	int count = 0;
	queue<pair<int, int>> checkAdjacentBlankQueue;

	checkAdjacentBlankQueue.push(make_pair(xCoordinate, yCoordinate));

	while (!checkAdjacentBlankQueue.empty()) {
		int currentXCoordinate = checkAdjacentBlankQueue.front().first;
		int currentYCoordinate = checkAdjacentBlankQueue.front().second;
		count += 1;

		identiferPlace[currentXCoordinate][currentYCoordinate] = identifer;
		checkAdjacentBlankQueue.pop();

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate == N || nextYCoordinate < 0 || nextYCoordinate == M) {
				continue;
			}
			if (place[nextXCoordinate][nextYCoordinate] == WALL) {
				continue;
			}
			if (identiferPlace[nextXCoordinate][nextYCoordinate] != NOT_VISITED) {
				continue;
			}

			checkAdjacentBlankQueue.push(make_pair(nextXCoordinate, nextYCoordinate));
		}
	}

	identiferAndCountMap[identifer] = count;
	identifer += 1;
}

void makeAnswer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (identiferPlace[i][j] == NOT_VISITED) {
				int count = 1;
				map<int, bool> checkSameIdentifer;

				for (int k = 0; k < 4; k++) {
					int nextXCoordinate = i + moveXCoordinate[k];
					int nextYCoordinate = j + moveYCoordinate[k];

					if (nextXCoordinate < 0 || nextXCoordinate == N || nextYCoordinate < 0 || nextYCoordinate == M) {
						continue;
					}
					if (identiferPlace[nextXCoordinate][nextYCoordinate] == NOT_VISITED) {
						continue;
					}

					int currentIdentifier = identiferPlace[nextXCoordinate][nextYCoordinate];
					if (checkSameIdentifer[currentIdentifier] == true) {
						continue;
					}

					checkSameIdentifer[currentIdentifier] = true;
					count += identiferAndCountMap[currentIdentifier];
				}

				count %= 10;
				place[i][j] = count + '0';
			}
			else {
				place[i][j] = BLANK;
			}
		}
	}
}