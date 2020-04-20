/*
	problem site	:	baekjoon
	problem number	:	1986
	problem name	:	체스
	algorithm	:	simulation
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER_OF_CHESS_BOARD = 1000;
const int UNSAFETY_ZONE = -1;
const int SAFETY_ZONE = 0;
const int QUEEN = 1;
const int KNIGHT = 2;
const int PAWN = 3;

int moveXOfKnight[] = { -2,-2,-1,-1,1,1,2,2 };
int moveYOfKnight[] = { 1,-1,2,-2,2,-2,1,-1 };
int moveXOfQueen[] = { 1,-1,0,0,1,1,-1,-1 };
int moveYOfQueen[] = { 0,0,1,-1,1,-1,1,-1 };

int chessBoard[MAX_NUMBER_OF_CHESS_BOARD + 1][MAX_NUMBER_OF_CHESS_BOARD + 1];

void checkChessBoard();
void checkKnightMove(int xCoordinate, int yCoordinate);
void checkQueenMove(int xCoordinate, int yCoordinate);
void printSafetyZoneOfChessBoard();

int n, m;
int main() {
	cin >> n >> m;

	int countOfQueen;
	cin >> countOfQueen;
	for (int i = 0; i < countOfQueen; i++) {
		int xCoordinateOfQueen, yCoordinateOfQueen;
		cin >> xCoordinateOfQueen >> yCoordinateOfQueen;

		chessBoard[xCoordinateOfQueen][yCoordinateOfQueen] = QUEEN;
	}

	int countOfKnight;
	cin >> countOfKnight;
	for (int i = 0; i < countOfKnight; i++) {
		int xCoordinateOfKnight, yCoordinateOfKnight;
		cin >> xCoordinateOfKnight >> yCoordinateOfKnight;

		chessBoard[xCoordinateOfKnight][yCoordinateOfKnight] = KNIGHT;
	}

	int countOfPawn;
	cin >> countOfPawn;
	for (int i = 0; i < countOfPawn; i++) {
		int xCoordinateOfPawn, yCoordinateOfPawn;
		cin >> xCoordinateOfPawn >> yCoordinateOfPawn;

		chessBoard[xCoordinateOfPawn][yCoordinateOfPawn] = PAWN;
	}
	
	checkChessBoard();
	printSafetyZoneOfChessBoard();
}

void checkChessBoard() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chessBoard[i][j] == SAFETY_ZONE) {
				continue;
			}

			if (chessBoard[i][j] == KNIGHT) {
				checkKnightMove(i, j);
			}
			else if (chessBoard[i][j] == QUEEN) {
				checkQueenMove(i, j);
			}
		}
	}
}

void checkKnightMove(int xCoordinate, int yCoordinate) {
	for (int i = 0; i < 8; i++) {
		int nextXCoordinate = xCoordinate + moveXOfKnight[i];
		int nextYCoordinate = yCoordinate + moveYOfKnight[i];

		if (nextXCoordinate < 1 || nextXCoordinate > n || nextYCoordinate < 1 || nextYCoordinate > m) {
			continue;
		}

		if (chessBoard[nextXCoordinate][nextYCoordinate] != SAFETY_ZONE) {
			continue;
		}

		chessBoard[nextXCoordinate][nextYCoordinate] = UNSAFETY_ZONE;
	}
}
void checkQueenMove(int xCoordinate, int yCoordinate) {
	for (int i = 0; i < 8; i++) {
		int nextXCoordinate = xCoordinate; 
		int nextYCoordinate = yCoordinate;

		while (1) {
			nextXCoordinate += moveXOfQueen[i];
			nextYCoordinate += moveYOfQueen[i];
			if (nextXCoordinate < 1 || nextXCoordinate > n || nextYCoordinate < 1 || nextYCoordinate > m) {
				break;
			}

			if (chessBoard[nextXCoordinate][nextYCoordinate] != SAFETY_ZONE && chessBoard[nextXCoordinate][nextYCoordinate] != UNSAFETY_ZONE) {
				break;
			}

			chessBoard[nextXCoordinate][nextYCoordinate] = UNSAFETY_ZONE;
		}
	}
}

void printSafetyZoneOfChessBoard() {
	int countOfSafetyZone = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (chessBoard[i][j] != SAFETY_ZONE) {
				continue;
			}
			
			countOfSafetyZone += 1;
		}
	}

	cout << countOfSafetyZone << '\n';
}