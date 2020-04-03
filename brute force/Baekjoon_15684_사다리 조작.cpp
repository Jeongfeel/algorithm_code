/*
	problem site	:	baekjoon
	problem number	:	15684
	problem name	:	사다리 조작
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER_OF_VERTICAL = 10;
const int MAX_NUMBER_OF_HORIZONTAL = 30;
const bool RIGHT = true;
const bool LEFT = false;

bool ladder[MAX_NUMBER_OF_HORIZONTAL + 1][MAX_NUMBER_OF_VERTICAL + 1];
bool direction[MAX_NUMBER_OF_HORIZONTAL + 1][MAX_NUMBER_OF_VERTICAL + 1];

void addNewHorizontal(int currentNewHorizontalCount, int currentVertical);
bool isSameStartAndEnd();

int minimumLadderCount = 4;

int N, M, H;
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int horizontal, vertical;
		cin >> horizontal >> vertical;

		ladder[horizontal][vertical] = true;
		direction[horizontal][vertical] = true;
		ladder[horizontal][vertical + 1] = true;
	}

	addNewHorizontal(0, 1);

	if (minimumLadderCount == 4) {
		cout << "-1" << '\n';
	}
	else {
		cout << minimumLadderCount << '\n';
	}
}

void addNewHorizontal(int currentNewHorizontalCount, int currentVertical) {	
	if (isSameStartAndEnd() == true) {
		if (currentNewHorizontalCount < minimumLadderCount) {
			minimumLadderCount = currentNewHorizontalCount;
		}
	}
	else if (currentNewHorizontalCount < 3) {
		for (int i = currentVertical; i <= H; i++) {
			for (int j = 1; j < N; j++) {
				if (ladder[i][j] == true) {
					continue;
				}
				if (ladder[i][j + 1] == true) {
					continue;
				}

				ladder[i][j] = true;
				ladder[i][j + 1] = true;
				direction[i][j] = true;
				addNewHorizontal(currentNewHorizontalCount + 1, i);
				ladder[i][j] = false;
				ladder[i][j + 1] = false;
				direction[i][j] = false;
			}
		}
	}
}

bool isSameStartAndEnd() {
	for (int i = 1; i <= N; i++) {
		int start = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][start] == true) {
				if (direction[j][start] == true) {
					start += 1;
				}
				else {
					start -= 1;
				}
			}
		}

		if (start != i) {
			return false;
		}
	}

	return true;
}