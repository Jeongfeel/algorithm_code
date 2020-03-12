//baekjoon #7562
//algorithm : bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 300;

int chessBoard[MAX_NUMBER][MAX_NUMBER];

int x[] = { 1, 2, 1, 2, -1, -2 , -1, -2};
int y[] = { 2, 1, -2, -1, 2, 1, -2, -1 };

void initChessBoard() {
	for (int i = 0; i < MAX_NUMBER; i++) {
		for (int j = 0; j < MAX_NUMBER; j++) {
			chessBoard[i][j] = 0;
		}
	}
}

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		initChessBoard();
		
		int squareSide;
		cin >> squareSide;

		int currentX, currentY, destinationX, destinationY;
		cin >> currentX >> currentY >> destinationX >> destinationY;

		chessBoard[currentX][currentY] = 1;

		queue<pair<int, int>> knightMovableLocationQueue;

		pair<int, int> knightMovalbeLocation = make_pair(currentX, currentY);
		knightMovableLocationQueue.push(knightMovalbeLocation);

		int countOfKnightMoving = 0;
		int countOfMoveableLocation = knightMovableLocationQueue.size();

		while (!knightMovableLocationQueue.empty()) {
			pair<int, int> currentKnightLocation = knightMovableLocationQueue.front();
			knightMovableLocationQueue.pop();

			int currentKnightX = currentKnightLocation.first;
			int currentKnightY = currentKnightLocation.second;

			if (currentKnightX == destinationX && currentKnightY == destinationY) {
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nextKnightX = currentKnightX + x[i];
				int nextKnightY = currentKnightY + y[i];

				if (nextKnightX < 0 || nextKnightX >= squareSide || nextKnightY < 0 || nextKnightY >= squareSide) {
					continue;
				}
				
				if (chessBoard[nextKnightX][nextKnightY] == 0) {
					chessBoard[nextKnightX][nextKnightY] = 1;

					pair<int, int> nextKnightLocation = make_pair(nextKnightX, nextKnightY);
					knightMovableLocationQueue.push(nextKnightLocation);
				}
			}

			countOfMoveableLocation -= 1;
			if (countOfMoveableLocation == 0) {
				countOfMoveableLocation = knightMovableLocationQueue.size();
				countOfKnightMoving += 1;
			}
		}
		
		cout << countOfKnightMoving << '\n';
	}
}	