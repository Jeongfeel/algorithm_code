//Baekjoon #12100
//algorithm : brute force

#include <iostream>
using namespace std;

const int MAX_NUMBER = 20;
const int MOVE_NUMBER = 5;
const int MAX_GAME_BOARD_NUMBER = 1024;

int gameBoard[MOVE_NUMBER + 1][MAX_GAME_BOARD_NUMBER][MAX_NUMBER][MAX_NUMBER];
bool isCombineGameBoard[MOVE_NUMBER + 1][MAX_GAME_BOARD_NUMBER][MAX_NUMBER][MAX_NUMBER];

int gameBoardNumberByMoveNumber[MOVE_NUMBER] = { 1, 4, 16, 64, 256 };
int x[] = { 1,-1,0,0 };
int y[] = { 0,0,1,-1 };

void moveBlockToLeft(int moveNumber, int gameBoardNumber);
void moveBlockToRight(int moveNumber, int gameBoardNumber);
void moveBlockToUp(int moveNumber, int gameBoardNumber);
void moveBlockToDown(int moveNumber, int gameBoardNumber);

void printMakeableMaxNumberToMove();

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> gameBoard[0][0][i][j];
		}
	}

	for (int i = 0; i < MOVE_NUMBER; i++) {
		for (int j = 0; j < gameBoardNumberByMoveNumber[i]; j++) {
			moveBlockToLeft(i, j);
			moveBlockToRight(i, j);
			moveBlockToUp(i, j);
			moveBlockToDown(i, j);
		}
	}

	printMakeableMaxNumberToMove();
}

void moveBlockToLeft(int moveNumber, int gameBoardNumber) {
	int newMoveNumber = moveNumber + 1;
	int newGameBoardNumber = gameBoardNumber * 4 + 0;

	for (int i = 0; i < N; i++) {
		gameBoard[newMoveNumber][newGameBoardNumber][i][0] = gameBoard[moveNumber][gameBoardNumber][i][0];
		for (int j = 1; j < N; j++) {
			if (gameBoard[moveNumber][gameBoardNumber][i][j] == 0) {
				continue;
			}

			if (gameBoard[newMoveNumber][newGameBoardNumber][i][j - 1] == gameBoard[moveNumber][gameBoardNumber][i][j]) {
				gameBoard[newMoveNumber][newGameBoardNumber][i][j - 1] *= 2;
				gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j - 1] = true;
			}
			else if (gameBoard[newMoveNumber][newGameBoardNumber][i][j - 1] == 0) {
				int minusNumber = 1;
				while (gameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber] == 0 && j - minusNumber >= 0) {
					minusNumber += 1;
				}

				if (j - minusNumber < 0) {
					gameBoard[newMoveNumber][newGameBoardNumber][i][0] = gameBoard[moveNumber][gameBoardNumber][i][j];
					gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				}
				else {
					if (gameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber] == gameBoard[moveNumber][gameBoardNumber][i][j] && isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber] == false) {
						gameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber] *= 2;
						isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber] = true;
					}
					else {
						gameBoard[newMoveNumber][newGameBoardNumber][i][j - minusNumber + 1] = gameBoard[moveNumber][gameBoardNumber][i][j];
					}

					gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				}
			}
			else {
				gameBoard[newMoveNumber][newGameBoardNumber][i][j] = gameBoard[moveNumber][gameBoardNumber][i][j];
			}
		}
	}
}

void moveBlockToRight(int moveNumber, int gameBoardNumber) {
	int newMoveNumber = moveNumber + 1;
	int newGameBoardNumber = gameBoardNumber * 4 + 1;

	for (int i = 0; i < N; i++) {
		gameBoard[newMoveNumber][newGameBoardNumber][i][N - 1] = gameBoard[moveNumber][gameBoardNumber][i][N - 1];
		for (int j = N - 2; j >= 0; j--) {
			if (gameBoard[moveNumber][gameBoardNumber][i][j] == 0) {
				continue;
			}

			if (gameBoard[newMoveNumber][newGameBoardNumber][i][j + 1] == gameBoard[moveNumber][gameBoardNumber][i][j]) {
				gameBoard[newMoveNumber][newGameBoardNumber][i][j + 1] *= 2;
				gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j + 1] = true;
			}
			else if (gameBoard[newMoveNumber][newGameBoardNumber][i][j + 1] == 0) {
				int plusNumber = 1;
				while (gameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber] == 0 && j + plusNumber < N) {
					plusNumber += 1;
				}

				if (j + plusNumber == N) {
					gameBoard[newMoveNumber][newGameBoardNumber][i][N - 1] = gameBoard[moveNumber][gameBoardNumber][i][j];
					gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				}
				else {
					if (gameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber] == gameBoard[moveNumber][gameBoardNumber][i][j] &&  isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber] == false) {
						gameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber] *= 2;
						isCombineGameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber] = true;
					}
					else {
						gameBoard[newMoveNumber][newGameBoardNumber][i][j + plusNumber - 1] = gameBoard[moveNumber][gameBoardNumber][i][j];
					}

					gameBoard[newMoveNumber][newGameBoardNumber][i][j] = 0;
				}
			}
			else {
				gameBoard[newMoveNumber][newGameBoardNumber][i][j] = gameBoard[moveNumber][gameBoardNumber][i][j];
			}
		}
	}
}

void moveBlockToUp(int moveNumber, int gameBoardNumber) {
	int newMoveNumber = moveNumber + 1;
	int newGameBoardNumber = gameBoardNumber * 4 + 2;

	for (int i = 0; i < N; i++) {
		gameBoard[newMoveNumber][newGameBoardNumber][0][i] = gameBoard[moveNumber][gameBoardNumber][0][i];
		for (int j = 1; j < N; j++) {
			if (gameBoard[moveNumber][gameBoardNumber][j][i] == 0) {
				continue;
			}

			if (gameBoard[newMoveNumber][newGameBoardNumber][j - 1][i] == gameBoard[moveNumber][gameBoardNumber][j][i]) {
				gameBoard[newMoveNumber][newGameBoardNumber][j - 1][i] *= 2;
				gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				isCombineGameBoard[newMoveNumber][newGameBoardNumber][j - 1][i] = true;
			}
			else if (gameBoard[newMoveNumber][newGameBoardNumber][j - 1][i] == 0) {
				int minusNumber = 1;
				while (gameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber][i] == 0 && j - minusNumber >= 0) {
					minusNumber += 1;
				}

				if (j - minusNumber < 0) {
					gameBoard[newMoveNumber][newGameBoardNumber][0][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
					gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				}
				else {
					if (gameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber][i] == gameBoard[moveNumber][gameBoardNumber][j][i] && isCombineGameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber][i] == false) {
						gameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber][i] *= 2;
						isCombineGameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber][i] = true;
					}
					else {
						gameBoard[newMoveNumber][newGameBoardNumber][j - minusNumber + 1][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
					}

					gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				}
			}
			else {
				gameBoard[newMoveNumber][newGameBoardNumber][j][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
			}
		}
	}
}

void moveBlockToDown(int moveNumber, int gameBoardNumber) {
	int newMoveNumber = moveNumber + 1;
	int newGameBoardNumber = gameBoardNumber * 4 + 3;

	for (int i = 0; i < N; i++) {
		gameBoard[newMoveNumber][newGameBoardNumber][N - 1][i] = gameBoard[moveNumber][gameBoardNumber][N - 1][i];
		for (int j = N - 2; j >= 0; j--) {
			if (gameBoard[moveNumber][gameBoardNumber][j][i] == 0) {
				continue;
			}

			if (gameBoard[newMoveNumber][newGameBoardNumber][j + 1][i] == gameBoard[moveNumber][gameBoardNumber][j][i]) {
				gameBoard[newMoveNumber][newGameBoardNumber][j + 1][i] *= 2;
				gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				isCombineGameBoard[newMoveNumber][newGameBoardNumber][j + 1][i] = true;
			}
			else if (gameBoard[newMoveNumber][newGameBoardNumber][j + 1][i] == 0) {
				int plusNumber = 1;
				while (gameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber][i] == 0 && j + plusNumber < N) {
					plusNumber += 1;
				}

				if (j + plusNumber == N) {
					gameBoard[newMoveNumber][newGameBoardNumber][N - 1][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
					gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				}
				else {
					if (gameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber][i] == gameBoard[moveNumber][gameBoardNumber][j][i] && isCombineGameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber][i] == false) {
						gameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber][i] *= 2;
						isCombineGameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber][i] = true;
					}
					else {
						gameBoard[newMoveNumber][newGameBoardNumber][j + plusNumber - 1][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
					}

					gameBoard[newMoveNumber][newGameBoardNumber][j][i] = 0;
				}
			}
			else {
				gameBoard[newMoveNumber][newGameBoardNumber][j][i] = gameBoard[moveNumber][gameBoardNumber][j][i];
			}
		}
	}
}

void printMakeableMaxNumberToMove() {
	int makeableMaxNumber = 0;

	for (int i = 0; i < gameBoardNumberByMoveNumber[4] * 4; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (gameBoard[MOVE_NUMBER][i][j][k] > makeableMaxNumber) {
					makeableMaxNumber = gameBoard[MOVE_NUMBER][i][j][k];
				}
			}
		}
	}

	cout << makeableMaxNumber << '\n';
}