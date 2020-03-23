//Baekjoon #1018
//algorithm : brute force

#include <iostream>
using namespace std;

const int MAX_NUMBER = 50;
const int MAX_INT_NUMBER = 1024 * 1024 * 1024 * 2 - 1;
const int MAX_CHESS_BOARD_NUMBER = 8;

char chessBoard[MAX_NUMBER][MAX_NUMBER];
char checkChessBoardStartBlackColor[8][8] = {
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },
	{ 'W','B','W','B','W','B','W','B' }
};

int countSquareStartBlackColor(int startXCoordinate, int startYCoordinate);

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chessBoard[i][j];
		}
	}

	int numberOfWidth = N - MAX_CHESS_BOARD_NUMBER + 1;
	int numberOfHeight = M - MAX_CHESS_BOARD_NUMBER + 1;

	int theMostMinimumNumber = MAX_INT_NUMBER;

	for (int i = 0; i < numberOfWidth; i++) {
		for (int j = 0; j < numberOfHeight; j++) {
			int minimumCount = countSquareStartBlackColor(i, j);

			if (theMostMinimumNumber > minimumCount) {
				theMostMinimumNumber = minimumCount;
			}
			if (theMostMinimumNumber > (MAX_CHESS_BOARD_NUMBER * MAX_CHESS_BOARD_NUMBER - minimumCount)) {
				theMostMinimumNumber = MAX_CHESS_BOARD_NUMBER * MAX_CHESS_BOARD_NUMBER - minimumCount;
			}
		}
	}

	cout << theMostMinimumNumber << '\n';
}

int countSquareStartBlackColor(int startXCoordinate, int startYCoordinate) {
	int coloredNumber = 0;
	
	for (int i = 0; i < MAX_CHESS_BOARD_NUMBER; i++) {
		for (int j = 0; j < MAX_CHESS_BOARD_NUMBER; j++) {
			int newXCoordinate = startXCoordinate + i;
			int newYCoordinate = startYCoordinate + j;

			if (chessBoard[newXCoordinate][newYCoordinate] == checkChessBoardStartBlackColor[i][j]) {
				continue;
			}

			coloredNumber += 1;
		}
	}
	
	return coloredNumber;
}
