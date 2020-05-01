/*
	problem site	:	baekjoon
	problem number	:	16929
	problem name	:	Two Dots
	algorithm	:	dfs
*/

#include <iostream>
using namespace std;

const int MAX_LENGTH_OF_GAME_BOARD = 50;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

char gameBoard[MAX_LENGTH_OF_GAME_BOARD][MAX_LENGTH_OF_GAME_BOARD];
bool isVisitedGameBoard[MAX_LENGTH_OF_GAME_BOARD][MAX_LENGTH_OF_GAME_BOARD];

void checkGameBoardCycle(int xCoordinate, int yCoordinate, int count);
void initIsVisitedGameBoard();

int startXCoordinate, startYCoordinate;
bool isMadeCycle = false;

int N, M;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> gameBoard[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			startXCoordinate = i;
			startYCoordinate = j;
			checkGameBoardCycle(i, j, 1);

			if (isMadeCycle == true) {
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}

	cout << "No" << '\n';
}

void checkGameBoardCycle(int xCoordinate, int yCoordinate, int count) {
	if (count == 1) {
		initIsVisitedGameBoard();
	}
	isVisitedGameBoard[xCoordinate][yCoordinate] = true;

	for (int i = 0; i < 4; i++) {
		int nextXCoordinate = xCoordinate + moveXCoordinate[i];
		int nextYCoordinate = yCoordinate + moveYCoordinate[i];

		if (nextXCoordinate == startXCoordinate && nextYCoordinate == startYCoordinate && count >= 3) {
			isMadeCycle = true;
			return;
		}

		if (nextXCoordinate < 0 || nextXCoordinate == N || nextYCoordinate < 0 || nextYCoordinate == M) {
			continue;
		}

		if (gameBoard[nextXCoordinate][nextYCoordinate] != gameBoard[xCoordinate][yCoordinate]) {
			continue;
		}

		if (isVisitedGameBoard[nextXCoordinate][nextYCoordinate] == true) {
			continue;
		}

		checkGameBoardCycle(nextXCoordinate, nextYCoordinate, count + 1);
	}
}

void initIsVisitedGameBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			isVisitedGameBoard[i][j] = false;
		}
	}
}