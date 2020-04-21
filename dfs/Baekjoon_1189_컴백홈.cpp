/*
	problem site	:	baekjoon
	problem number	:	1189
	problem name	:	컴백홈
	algorithm	:	dfs
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 5;

int moveX[] = { 1,-1,0,0 };
int moveY[] = { 0,0,1,-1 };

char map[MAX_NUMBER][MAX_NUMBER];
bool isVisitedMap[MAX_NUMBER][MAX_NUMBER];

void checkMap(int xCoordinate, int yCoordinate, int currentWay);

int	way = 0;

int R, C, K;
int main() {
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	checkMap(R-1, 0, 1);
	cout << way << '\n';
}

void checkMap(int xCoordinate, int yCoordinate, int currentWay) {
	isVisitedMap[xCoordinate][yCoordinate] = true;
	
	if (xCoordinate == 0 && yCoordinate == C - 1) {
		if (currentWay == K) {
			way += 1;
		}
	}

	for (int i = 0; i < 4; i++) {
		int nextXCoordinate = xCoordinate + moveX[i];
		int nextYCoordinate = yCoordinate + moveY[i];

		if (nextXCoordinate < 0 || nextXCoordinate == R || nextYCoordinate < 0 || nextYCoordinate == C) {
			continue;
		}

		if (isVisitedMap[nextXCoordinate][nextYCoordinate] == true) {
			continue;
		}

		if (map[nextXCoordinate][nextYCoordinate] == 'T') {
			continue;
		}

		checkMap(nextXCoordinate, nextYCoordinate, currentWay + 1);
	}

	isVisitedMap[xCoordinate][yCoordinate] = false;
}