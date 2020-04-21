/*
	problem site	:	baekjoon
	problem number	:	3184
	problem name	:	양
	algorithm	:	bfs
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 250;
const char EMPTY_FIELD = '.';
const char FENCE = '#';
const char WOLF = 'v';
const char SHEEP = 'o';

char garden[MAX_NUMBER][MAX_NUMBER];
bool isVisitedGarden[MAX_NUMBER][MAX_NUMBER];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void checkGarden(int xCoordinate, int yCoordinate);

int countOfSheep;
int countOfWolf;

int R, C;
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> garden[i][j];
		}
	}

	int countOfSurviveSheep = 0;
	int countOfSurviveWolf = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (garden[i][j] == FENCE) {
				continue;
			}

			if (isVisitedGarden[i][j] == true) {
				continue;
			}

			countOfSheep = 0;
			countOfWolf = 0;
			
			checkGarden(i, j);

			if (countOfSheep > countOfWolf) {
				countOfSurviveSheep += countOfSheep;
			}
			else if (countOfSheep <= countOfWolf) {
				countOfSurviveWolf += countOfWolf;
			}
		}
	}

	cout << countOfSurviveSheep << " " << countOfSurviveWolf << '\n';
}

void checkGarden(int xCoordinate, int yCoordinate) {
	isVisitedGarden[xCoordinate][yCoordinate] = true;

	if (garden[xCoordinate][yCoordinate] == SHEEP) {
		countOfSheep += 1;
	}
	else if (garden[xCoordinate][yCoordinate] == WOLF) {
		countOfWolf += 1;
	}

	for (int i = 0; i < 4; i++) {
		int nextXCoordinate = xCoordinate + moveXCoordinate[i];
		int nextYCoordinate = yCoordinate + moveYCoordinate[i];

		if (nextXCoordinate < 0 || nextXCoordinate == R || nextYCoordinate < 0 || nextYCoordinate == C) {
			continue;
		}

		if (garden[nextXCoordinate][nextYCoordinate] == FENCE) {
			continue;
		}

		if (isVisitedGarden[nextXCoordinate][nextYCoordinate] == true) {
			continue;
		}

		checkGarden(nextXCoordinate, nextYCoordinate);
	}
}