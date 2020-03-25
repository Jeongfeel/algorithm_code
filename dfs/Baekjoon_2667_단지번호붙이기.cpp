/*
	problem site	:	baekjoon
	problem number	:	2667
	problem name	:	단지번호붙이기
	algorithm		:	dfs
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NUMBER_OF_N = 25;
const int COUNT_OF_DIRECTION = 4;
char squareMap[MAX_NUMBER_OF_N][MAX_NUMBER_OF_N];
bool isVisitedSquareMap[MAX_NUMBER_OF_N][MAX_NUMBER_OF_N];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void checkCountOfHomeComplex(int xCoordinate, int yCoordinate);

int numberOfHomeComplex;
int countOfHomeComplex;
vector<int> countOfEachHomeComplex;

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> squareMap[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (squareMap[i][j] == '0') {
				continue;
			}

			if (isVisitedSquareMap[i][j] == true) {
				continue;
			}

			numberOfHomeComplex += 1;
			countOfHomeComplex = 0;
			checkCountOfHomeComplex(i, j);
			countOfEachHomeComplex.push_back(countOfHomeComplex);
		}
	}

	sort(countOfEachHomeComplex.begin(), countOfEachHomeComplex.end());

	cout << numberOfHomeComplex << '\n';
	for (int i = 0; i < numberOfHomeComplex; i++) {
		cout << countOfEachHomeComplex[i] << '\n';
	}
}

void checkCountOfHomeComplex(int xCoordinate, int yCoordinate) {
	countOfHomeComplex += 1;

	isVisitedSquareMap[xCoordinate][yCoordinate] = true;

	for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
		int nextXCoordinate = xCoordinate + moveXCoordinate[i];
		int nextYCoordinate = yCoordinate + moveYCoordinate[i];

		if (nextXCoordinate < 0 || nextXCoordinate == N || nextYCoordinate < 0 || nextYCoordinate == N) {
			continue;
		}

		if (squareMap[nextXCoordinate][nextYCoordinate] == '0') {
			continue;
		}

		if (isVisitedSquareMap[nextXCoordinate][nextYCoordinate] == true) {
			continue;
		}

		checkCountOfHomeComplex(nextXCoordinate, nextYCoordinate);
	}
}
