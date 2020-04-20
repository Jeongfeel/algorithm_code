/*
	problem site	:	baekjoon
	problem number	:	11559
	problem name	:	Puyo Puyo
	algorithm	:	dfs
*/

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

const int WIDTH = 6;
const int HEIGHT = 12;

int moveXCoordate[] = { 1,-1,0,0 };
int moveYCoordate[] = { 0,0,1,-1 };

char field[HEIGHT][WIDTH];

void checkChainExplosion();
void applyGravity();
void applyGravityAtField(int indexOfWidth, stack<char> applyGravityColor);
void checkSameColor(char currentColor, int xCoordinate, int yCoordinate, vector<pair<int,int>> &explosionCoordinate);

int maximumCountOfExplosion = 0;

int main() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cin >> field[i][j];
		}
	}

	checkChainExplosion();
	cout << maximumCountOfExplosion << '\n';
}

void checkChainExplosion() {
	bool isExploded = false;
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (field[i][j] == '.') {
				continue;
			}
			char currentColor = field[i][j];
			vector<pair<int, int>> explosionCoordinate;

			checkSameColor(currentColor, i, j, explosionCoordinate);

			if (explosionCoordinate.size() < 4) {
				for (int i = 0; i < explosionCoordinate.size(); i++) {
					int xCoordinate = explosionCoordinate[i].first;
					int yCoordinate = explosionCoordinate[i].second;

					field[xCoordinate][yCoordinate] = currentColor;
				}
			}
			else {
				isExploded = true;
			}
		}
	}

	if (isExploded == true) {
		applyGravity();
		maximumCountOfExplosion += 1;

		checkChainExplosion();
	}
}

void applyGravity() {
	for (int i = 0; i < WIDTH; i++) {
		stack<char> applyGravityColor;
		for (int j = 0; j < HEIGHT; j++) {
			if (field[j][i] == '.') {
				continue;
			}

			applyGravityColor.push(field[j][i]);
			field[j][i] = '.';
		}

		applyGravityAtField(i, applyGravityColor);
	}
}

void applyGravityAtField(int indexOfWidth, stack<char> applyGravityColor) {
	int sizeOfApplyGravityColor = applyGravityColor.size();
	int indexOfHeight = HEIGHT - 1;
	for (int i = 0; i < sizeOfApplyGravityColor; i++) {
		field[indexOfHeight][indexOfWidth] = applyGravityColor.top();
		applyGravityColor.pop();
		indexOfHeight -= 1;
	}
}

void checkSameColor(char currentColor, int xCoordinate, int yCoordinate, vector<pair<int, int>> &explosionCoordinate) {
	field[xCoordinate][yCoordinate] = '.';
	explosionCoordinate.push_back(make_pair(xCoordinate, yCoordinate));
	
	for (int i = 0; i < 4; i++) {
		int nextXCoordinate = xCoordinate + moveXCoordate[i];
		int nextYCoordinate = yCoordinate + moveYCoordate[i];

		if (nextXCoordinate < 0 || nextXCoordinate == HEIGHT || nextYCoordinate < 0 || nextYCoordinate == WIDTH) {
			continue;
		}
		if (field[nextXCoordinate][nextYCoordinate] != currentColor) {
			continue;
		}

		checkSameColor(currentColor, nextXCoordinate, nextYCoordinate, explosionCoordinate);
	}
}
