/*
	problem site	:	baekjoon
	problem number	:	16948
	problem name	:	데스 나이트
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
using namespace std;

const int MAX_NUMBER_OF_CHESS_BOARD = 200;

int chessBoard[MAX_NUMBER_OF_CHESS_BOARD + 1][MAX_NUMBER_OF_CHESS_BOARD + 1];
int moveXCoordinate[] = { -2,-2,0,0,2,2 };
int moveYCoordinate[] = { -1,1,-2,2,-1,1 };

void checkMinimumMovingCount();

int N;
int r1, c1, r2, c2;
int main() {
	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;

	checkMinimumMovingCount();
}

void checkMinimumMovingCount() {
	queue<pair<int, int>> moveablePositionAndCountQueue;
	moveablePositionAndCountQueue.push(make_pair(r1, c1));

	while (!moveablePositionAndCountQueue.empty()) {
		int xCoordinate = moveablePositionAndCountQueue.front().first;
		int yCoordinate = moveablePositionAndCountQueue.front().second;
		int count = chessBoard[xCoordinate][yCoordinate];

		if (xCoordinate == r2 && yCoordinate == c2) {
			cout << count << '\n';
			return;
		}

		moveablePositionAndCountQueue.pop();

		for (int i = 0; i < 6; i++) {
			int nextXCoordinate = xCoordinate + moveXCoordinate[i];
			int nextYCoordinate = yCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 0 || nextXCoordinate > N || nextYCoordinate < 0 || nextYCoordinate > N) {
				continue;
			}
			if (chessBoard[nextXCoordinate][nextYCoordinate] > 0) {
				continue;
			}

			chessBoard[nextXCoordinate][nextYCoordinate] = chessBoard[xCoordinate][yCoordinate] + 1;
			moveablePositionAndCountQueue.push(make_pair(nextXCoordinate, nextYCoordinate));
		}
	}

	cout << "-1" << '\n';
}