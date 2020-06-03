/*
	problem site	:	baekjoon
	problem number	:	16234
	problem name	:	인구 이동
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_LENGTH_OF_GROUND = 50;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

int ground[MAX_LENGTH_OF_GROUND][MAX_LENGTH_OF_GROUND];
bool isVisitedGround[MAX_LENGTH_OF_GROUND][MAX_LENGTH_OF_GROUND];
bool isMoveable = false;

void printCountOfMovingPopulation();
void initIsVisitedGround();
void checkAdjacentGround(int xCoordinate, int yCoordinate);
void changeGround(vector<pair<int, int>> adjacentCountryVector);

int N, L, R;
int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ground[i][j];
		}
	}

	printCountOfMovingPopulation();
}

void printCountOfMovingPopulation() {
	int count = 0;

	while (true) {
		isMoveable = false;
		initIsVisitedGround();
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isVisitedGround[i][j] == true) {
					continue;
				}

				checkAdjacentGround(i, j);
			}
		}

		if (isMoveable == false) {
			break;
		}
		count += 1;
	}

	cout << count << '\n';
}

void initIsVisitedGround() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isVisitedGround[i][j] = false;
		}
	}
}

void checkAdjacentGround(int xCoordinate, int yCoordinate) {
	queue<pair<int, int>> adjacentCountryQueue;
	vector<pair<int, int>> adjacentCountryVector;

	adjacentCountryQueue.push({ xCoordinate,yCoordinate });

	while (!adjacentCountryQueue.empty()) {
		int x = adjacentCountryQueue.front().first;
		int y = adjacentCountryQueue.front().second;
		adjacentCountryQueue.pop();
		if (isVisitedGround[x][y] == true) {
			continue;
		}

		isVisitedGround[x][y] = true;
		adjacentCountryVector.push_back({ x,y });
				
		for (int i = 0; i < 4; i++) {
			int nextX = x + moveXCoordinate[i];
			int nextY = y + moveYCoordinate[i];

			if (nextX < 0 || nextX == N || nextY < 0 || nextY == N) {
				continue;
			}
			if (isVisitedGround[nextX][nextY] == true) {
				continue;
			}

			int differenceOfPopulation = abs(ground[x][y] - ground[nextX][nextY]);
			if (differenceOfPopulation < L || differenceOfPopulation > R) {
				continue;
			}

			adjacentCountryQueue.push({ nextX,nextY });
		}
	}

	if (adjacentCountryVector.size() == 1) {
		return;
	}

	isMoveable = true;

	changeGround(adjacentCountryVector);
}

void changeGround(vector<pair<int, int>> adjacentCountryVector) {
	int sumOfPopulation = 0;
	for (int i = 0; i < adjacentCountryVector.size(); i++) {
		int x = adjacentCountryVector[i].first;
		int y = adjacentCountryVector[i].second;

		sumOfPopulation += ground[x][y];
	}

	sumOfPopulation /= adjacentCountryVector.size();
	for (int i = 0; i < adjacentCountryVector.size(); i++) {
		int x = adjacentCountryVector[i].first;
		int y = adjacentCountryVector[i].second;

		ground[x][y] = sumOfPopulation;
	}
}