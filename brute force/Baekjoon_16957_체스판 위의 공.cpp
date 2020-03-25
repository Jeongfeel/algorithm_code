/*
	problem site	:	baekjoon
	problem number	:	16957
	problem name	:	체스판 위의 공
	algorithm	:	brute force
*/

#include <iostream>
#include <utility>
using namespace std;

const int MAX_NUMBER = 500;
const int COUNT_OF_DIRECTION = 8;

int moveXCoordinate[] = { 1,-1,0,0,1,-1,1,-1 };
int moveYCoordinate[] = { 0,0,1,-1,1,1,-1,-1 };

int chessBoard[MAX_NUMBER][MAX_NUMBER];
int finalChessBoard[MAX_NUMBER][MAX_NUMBER];
pair<int, int> finalDestinationCoordinate[MAX_NUMBER][MAX_NUMBER];

void initFinalDestinationCoordinate();
void checkFinalChessBoardPlace(int currentXCoordinate, int currentYCoordinate);
bool isFinalDestinationCoordinate(int currentXCoordinate, int currentYCoordinate);
void setFinalChessBoard(int currentXCoordinate, int currentYCoordinate);
void findFinalDestinationCoordinate(int currentXCoordinate, int currentYCoordinate);

int originalXCoordinate, originalYCoordinate;
int R, C;
int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> chessBoard[i][j];
		}
	}

	initFinalDestinationCoordinate();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			originalXCoordinate = i;
			originalYCoordinate = j;
			checkFinalChessBoardPlace(i, j);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << finalChessBoard[i][j] << " ";
		}
		cout << '\n';
	}
}

void initFinalDestinationCoordinate() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			finalDestinationCoordinate[i][j].first = -1;
			finalDestinationCoordinate[i][j].second = -1;
		}
	}
}

void checkFinalChessBoardPlace(int currentXCoordinate, int currentYCoordinate) {
	if (isFinalDestinationCoordinate(currentXCoordinate, currentYCoordinate) == true) {
		setFinalChessBoard(currentXCoordinate, currentYCoordinate);
	}
	else {
		findFinalDestinationCoordinate(currentXCoordinate, currentYCoordinate);		
	}
}

bool isFinalDestinationCoordinate(int currentXCoordinate, int currentYCoordinate) {
	if (finalDestinationCoordinate[currentXCoordinate][currentYCoordinate].first != -1) {
		return true;
	}

	return false;
}

void setFinalChessBoard(int currentXCoordinate, int currentYCoordinate) {
	int finalXCoordinate = finalDestinationCoordinate[currentXCoordinate][currentYCoordinate].first;
	int finalYCoordinate = finalDestinationCoordinate[currentXCoordinate][currentYCoordinate].second;

	finalDestinationCoordinate[originalXCoordinate][originalYCoordinate].first = finalXCoordinate;
	finalDestinationCoordinate[originalXCoordinate][originalYCoordinate].second = finalYCoordinate;

	finalChessBoard[finalXCoordinate][finalYCoordinate] += 1;
}

void findFinalDestinationCoordinate(int currentXCoordinate, int currentYCoordinate) {
	int currentChessBoardNumber = chessBoard[currentXCoordinate][currentYCoordinate];

	int nextMoveXCoordinate, nextMoveYCoordinate;
	bool isMovedNextCoordinate = false;

	for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
		int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
		int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

		if (nextXCoordinate < 0 || nextXCoordinate == R || nextYCoordinate < 0 || nextYCoordinate == C) {
			continue;
		}

		if (currentChessBoardNumber > chessBoard[nextXCoordinate][nextYCoordinate]) {
			currentChessBoardNumber = chessBoard[nextXCoordinate][nextYCoordinate];
			nextMoveXCoordinate = nextXCoordinate;
			nextMoveYCoordinate = nextYCoordinate;
			isMovedNextCoordinate = true;
		}
	}

	if (isMovedNextCoordinate == false) {
		finalChessBoard[currentXCoordinate][currentYCoordinate] += 1;
		finalDestinationCoordinate[originalXCoordinate][originalYCoordinate].first = currentXCoordinate;
		finalDestinationCoordinate[originalXCoordinate][originalYCoordinate].second = currentYCoordinate;
	}
	else {
		checkFinalChessBoardPlace(nextMoveXCoordinate, nextMoveYCoordinate);
	}
}