//Baekjoon #3055
//algorithm : simulation

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 50;
char mapOfTitup[MAX_NUMBER][MAX_NUMBER];

int adjacentSquareOfX[] = { 1,-1,0,0 };
int adjacentSquareOfY[] = { 0,0,1,-1 };
	
int main() {
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mapOfTitup[i][j];
		}
	}

	pair<int, int> caveOfBeaver;
	queue<pair<int, int>> moveablePositionOfHedgehog;	
	queue<pair<int, int>> moveablePositionOfWater;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mapOfTitup[i][j] == 'D') {
				caveOfBeaver.first = i;
				caveOfBeaver.second = j;
			}
			else if (mapOfTitup[i][j] == 'S') {
				pair<int, int> positionOfHedgehog = make_pair(i, j);
				moveablePositionOfHedgehog.push(positionOfHedgehog);
			}
			else if (mapOfTitup[i][j] == '*') {
				pair<int, int>positionOfWater = make_pair(i, j);
				moveablePositionOfWater.push(positionOfWater);
			}
		}
	}

	int timeToBeaverFromHedgehog = 0;
	bool isPossibleToBeaverFromHedgehog = false;

	while (!moveablePositionOfHedgehog.empty()) {
		int countOfMoveablePositionOfWater = moveablePositionOfWater.size();
		
		while (countOfMoveablePositionOfWater != 0) {
			pair<int, int> currentPositionOfWater = moveablePositionOfWater.front();
			moveablePositionOfWater.pop();

			countOfMoveablePositionOfWater -= 1;
			
			for (int i = 0; i < 4; i++) {
				int newPositionOfWaterX = currentPositionOfWater.first + adjacentSquareOfX[i];
				int newPositionOfWaterY = currentPositionOfWater.second + adjacentSquareOfY[i];

				if (newPositionOfWaterX < 0 || newPositionOfWaterX >= R || newPositionOfWaterY < 0 || newPositionOfWaterY >= C) {
					continue;
				}

				if (mapOfTitup[newPositionOfWaterX][newPositionOfWaterY] == 'X' || mapOfTitup[newPositionOfWaterX][newPositionOfWaterY] == 'D' || mapOfTitup[newPositionOfWaterX][newPositionOfWaterY] == '*') {
					continue;
				}

				mapOfTitup[newPositionOfWaterX][newPositionOfWaterY] = '*';
				moveablePositionOfWater.push(make_pair(newPositionOfWaterX, newPositionOfWaterY));
			}
		}

		int countOfMoveablePositionOfHedgehog = moveablePositionOfHedgehog.size();

		while (countOfMoveablePositionOfHedgehog != 0) {
			pair<int, int> currentPositionOfHedgehog = moveablePositionOfHedgehog.front();
			moveablePositionOfHedgehog.pop();

			countOfMoveablePositionOfHedgehog -= 1;
			
			for (int i = 0; i < 4; i++) {
				int newPositionOfHedgehogX = currentPositionOfHedgehog.first + adjacentSquareOfX[i];
				int newPositionOfHedgehogY = currentPositionOfHedgehog.second + adjacentSquareOfY[i];

				if (newPositionOfHedgehogX < 0 || newPositionOfHedgehogX >= R || newPositionOfHedgehogY < 0 || newPositionOfHedgehogY >= C) {
					continue;
				}

				if (mapOfTitup[newPositionOfHedgehogX][newPositionOfHedgehogY] == 'X' || mapOfTitup[newPositionOfHedgehogX][newPositionOfHedgehogY] == '*' || mapOfTitup[newPositionOfHedgehogX][newPositionOfHedgehogY] == 'S') {
					continue;
				}

				if (caveOfBeaver.first == newPositionOfHedgehogX && caveOfBeaver.second == newPositionOfHedgehogY) {
					isPossibleToBeaverFromHedgehog = true;
					break;
				}

				mapOfTitup[newPositionOfHedgehogX][newPositionOfHedgehogY] = 'S';
				moveablePositionOfHedgehog.push(make_pair(newPositionOfHedgehogX, newPositionOfHedgehogY));
			}
		}

		timeToBeaverFromHedgehog += 1;
		if (isPossibleToBeaverFromHedgehog == true) {
			break;
		}
	}

	if (isPossibleToBeaverFromHedgehog) {
		cout << timeToBeaverFromHedgehog << '\n';
	}
	else {
		cout << "KAKTUS" << '\n';
	}
}