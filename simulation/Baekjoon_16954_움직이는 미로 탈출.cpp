/*
	problem site	:	baekjoon
	problem number	:	16954
	problem name	:	움직이는 미로 탈출
	algorithm	:	simulation
*/

#include <iostream>
#include <vector>
using namespace std;

const int LENGTH_OF_CHESS_BOARD = 8;
const char BLANK = '.';
const char WALL = '#';
const char WOOKJE = 'W';

int moveXCoordinate[] = { 1,-1,0,0,1,-1,1,-1 };
int moveYCoordinate[] = { 0,0,1,-1,1,1,-1,-1 };

char chessBoard[LENGTH_OF_CHESS_BOARD][LENGTH_OF_CHESS_BOARD];

bool possibleToMoveDestination();
bool isWallExisted();
void moveWookje();
void moveWall();
bool isWookjeExsited();

int main() {
	for (int i = 0; i < LENGTH_OF_CHESS_BOARD; i++) {
		for (int j = 0; j < LENGTH_OF_CHESS_BOARD; j++) {
			cin >> chessBoard[i][j];
		}
	}

	chessBoard[LENGTH_OF_CHESS_BOARD - 1][0] = WOOKJE;

	if (possibleToMoveDestination() == true) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
}

bool possibleToMoveDestination() {
	while (isWallExisted()) {
		moveWookje();
		moveWall();
	}

	if (isWookjeExsited()) {
		return true;
	}
	else {
		return false;
	}
}

bool isWallExisted() {
	for (int i = 0; i < LENGTH_OF_CHESS_BOARD; i++) {
		for (int j = 0; j < LENGTH_OF_CHESS_BOARD; j++) {
			if (chessBoard[i][j] == WALL) {
				return true;
			}
		}
	}

	return false;
}

void moveWookje() {
	vector<pair<int, int>> wookjePosition;

	for (int i = 0; i < LENGTH_OF_CHESS_BOARD; i++) {
		for (int j = 0; j < LENGTH_OF_CHESS_BOARD; j++) {
			if (chessBoard[i][j] == WOOKJE) {
				wookjePosition.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < wookjePosition.size(); i++) {
		int currentXCoordinate = wookjePosition[i].first;
		int currentYCoordinate = wookjePosition[i].second;

		for (int j = 0; j < 8; j++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[j];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[j];

			if (nextXCoordinate < 0 || nextXCoordinate == LENGTH_OF_CHESS_BOARD || nextYCoordinate < 0 || nextYCoordinate == LENGTH_OF_CHESS_BOARD) {
				continue;
			}
			if (chessBoard[nextXCoordinate][nextYCoordinate] == WALL) {
				continue;
			}

			chessBoard[nextXCoordinate][nextYCoordinate] = WOOKJE;
		}
	}
}

void moveWall() {
	for (int i = 0; i < LENGTH_OF_CHESS_BOARD; i++) {
		if (chessBoard[LENGTH_OF_CHESS_BOARD - 1][i] == WALL) {
			chessBoard[LENGTH_OF_CHESS_BOARD - 1][i] = BLANK;
		}
	}
	for (int i = LENGTH_OF_CHESS_BOARD - 1; i >= 0; i--) {
		for (int j = 0; j < LENGTH_OF_CHESS_BOARD; j++) {
			if (chessBoard[i][j] == WALL) {
				chessBoard[i + 1][j] = WALL;
				chessBoard[i][j] = BLANK;
			}
		}
	}
}

bool isWookjeExsited() {
	for (int i = 0; i < LENGTH_OF_CHESS_BOARD; i++) {
		for (int j = 0; j < LENGTH_OF_CHESS_BOARD; j++) {
			if (chessBoard[i][j] == WOOKJE) {
				return true;
			}
		}
	}

	return false;
}
