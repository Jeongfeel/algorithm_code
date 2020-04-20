/*
	problem site	:	baekjoon
	problem number	:	3085
	problem name	:	사탕 게임
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 50;
const char RED_COLOR = 'C';
const char BLUE_COLOR = 'P';
const char GREEN_COLOR = 'Z';
const char YELLOW_COLOR = 'Y';

char board[MAX_NUMBER][MAX_NUMBER];

void changeLeftAndRight();
void checkMaximumCandyByWidth(int currentWidthIndex);
void changeUpAndDown();
void checkMaximumCandyByHeight(int currentHeightIndex);

int maximumCountOfCandy = 0;
int sizeOfBoard;
int main() {
	cin >> sizeOfBoard;

	for (int i = 0; i < sizeOfBoard; i++) {
		for (int j = 0; j < sizeOfBoard; j++) {
			cin >> board[i][j];
		}
	}

	changeLeftAndRight();
	changeUpAndDown();

	cout << maximumCountOfCandy << '\n';
}

void changeLeftAndRight() {
	for (int i = 0; i < sizeOfBoard; i++) {
		checkMaximumCandyByWidth(i);
		for (int j = 0; j < sizeOfBoard - 1; j++) {
			char currentColor = board[i][j];
			board[i][j] = board[i][j + 1];
			board[i][j + 1] = currentColor;
			checkMaximumCandyByWidth(i);
			checkMaximumCandyByHeight(j);
			checkMaximumCandyByHeight(j + 1);
			currentColor = board[i][j];
			board[i][j] = board[i][j + 1];
			board[i][j + 1] = currentColor;
		}
	}
}

void checkMaximumCandyByWidth(int currentWidthIndex) {
	int countOfCandy = 1;
	char currentColor = board[currentWidthIndex][0];
	
	for (int i = 1; i < sizeOfBoard; i++) {
		if (currentColor == board[currentWidthIndex][i]) {
			countOfCandy += 1;
		}
		else {
			if (countOfCandy > maximumCountOfCandy) {
				maximumCountOfCandy = countOfCandy;
			}

			currentColor = board[currentWidthIndex][i];
			countOfCandy = 1;
		}
	}

	if (countOfCandy > maximumCountOfCandy) {
		maximumCountOfCandy = countOfCandy;
	}
}

void changeUpAndDown() {
	for (int i = 0; i < sizeOfBoard; i++) {
		checkMaximumCandyByHeight(i);
		for (int j = 0; j < sizeOfBoard - 1; j++) {
			char currentColor = board[j][i];
			board[j][i] = board[j + 1][i];
			board[j + 1][i] = currentColor;
			checkMaximumCandyByHeight(i);
			checkMaximumCandyByWidth(j);
			checkMaximumCandyByWidth(j + 1);
			currentColor = board[j][i];
			board[j][i] = board[j + 1][i];
			board[j + 1][i] = currentColor;
		}
	}
}

void checkMaximumCandyByHeight(int currentHeightIndex) {
	int countOfCandy = 1;
	char currentColor = board[0][currentHeightIndex];

	for (int i = 1; i < sizeOfBoard; i++) {
		if (currentColor == board[i][currentHeightIndex]) {
			countOfCandy += 1;
		}
		else {
			if (countOfCandy > maximumCountOfCandy) {
				maximumCountOfCandy = countOfCandy;
			}

			currentColor = board[i][currentHeightIndex];
			countOfCandy = 1;
		}
	}

	if (countOfCandy > maximumCountOfCandy) {
		maximumCountOfCandy = countOfCandy;
	}
}