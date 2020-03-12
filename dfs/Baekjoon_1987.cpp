//baekjoon #1987
//algorithm : dfs

#include <iostream>
#include <string>
using namespace std;

const int MAX_NUMBER = 20;
const int countOfAlphabet = 26;

int alphabetBoard[MAX_NUMBER][MAX_NUMBER];
string alphabetInputString[MAX_NUMBER];
bool isPassedAlphabet[countOfAlphabet];

int x[] = { 1,-1,0,0 };
int y[] = { 0,0,1,-1 };

int maxPassedBoard;

void findMaxPassedBoard(int currentX, int currentY, int currentPassedBoard);

int R, C;

int main(){
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		cin >> alphabetInputString[i];
	}

	int alphabetIndex = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			alphabetBoard[i][j] = alphabetInputString[i][j] - 'A';
		}
	}

	findMaxPassedBoard(0, 0, 0);

	cout << maxPassedBoard << '\n';
}	

void findMaxPassedBoard(int currentX, int currentY, int currentPassedBoard) {
	if (isPassedAlphabet[alphabetBoard[currentX][currentY]] == false) {
		isPassedAlphabet[alphabetBoard[currentX][currentY]] = true;
		currentPassedBoard += 1;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = currentX + x[i];
		int nextY = currentY + y[i];

		if (nextX < 0 || nextX == R || nextY < 0 || nextY == C) {
			continue;
		}

		if (isPassedAlphabet[alphabetBoard[nextX][nextY]] == false) {
			findMaxPassedBoard(nextX, nextY, currentPassedBoard);
		}
	}

	if (maxPassedBoard < currentPassedBoard) {
		maxPassedBoard = currentPassedBoard;
	}

	isPassedAlphabet[alphabetBoard[currentX][currentY]] = false;

}