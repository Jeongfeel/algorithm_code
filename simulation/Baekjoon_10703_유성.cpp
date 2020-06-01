/*
	problem site	:	baekjoon
	problem number	:	10703
	problem name	:	유성
	algorithm	:	simulation
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_LENGTH_OF_PICTURE = 3000;
const int NOT_EXIST = -1;
const char METEOR = 'X';
const char GROUND = '#';
const char AIR = '.';

char picture[MAX_LENGTH_OF_PICTURE][MAX_LENGTH_OF_PICTURE];
char resultPicture[MAX_LENGTH_OF_PICTURE][MAX_LENGTH_OF_PICTURE];

int existPositionOfMeteor[MAX_LENGTH_OF_PICTURE];
int existPositionOfGround[MAX_LENGTH_OF_PICTURE];

void initExistPosition();
int checkMinimumDistance();

int R, S;
int main() {
	cin >> R >> S;
	vector<pair<int, int>> meteorVector;

	initExistPosition();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cin >> picture[i][j];

			if (picture[i][j] == METEOR) {
				resultPicture[i][j] = AIR;
				existPositionOfMeteor[j] = i;
				meteorVector.push_back({ i,j });
			}
			else {
				resultPicture[i][j] = picture[i][j];

				if (resultPicture[i][j] == GROUND) {
					if (existPositionOfGround[j] == R) {
						existPositionOfGround[j] = i;
					}
				}
			}
		}
	}

	int minimumDistance = checkMinimumDistance();

	for (int i = 0; i < meteorVector.size(); i++) {
		int yCoordinate = meteorVector[i].first;
		int xCorodinate = meteorVector[i].second;

		resultPicture[yCoordinate + minimumDistance][xCorodinate] = METEOR;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			cout << resultPicture[i][j];
		}
		cout << '\n';
	}
}

void initExistPosition() {
	for (int i = 0; i < S; i++) {
		existPositionOfGround[i] = R;
		existPositionOfMeteor[i] = NOT_EXIST;
	}
}

int checkMinimumDistance() {
	int minimumDistance = 3000;

	for (int i = 0; i < S; i++) {
		if (existPositionOfMeteor[i] == NOT_EXIST) {
			continue;
		}

		int distance = existPositionOfGround[i] - existPositionOfMeteor[i] - 1;

		if (minimumDistance > distance) {
			minimumDistance = distance;
		}
	}

	return minimumDistance;
}