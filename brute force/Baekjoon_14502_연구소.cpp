/*
	problem site	:	baekjoon
	problem number	:	14502
	problem name	:	연구소
	algorithm	:	brute force + bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 8;

const int BLANK_SPACE = 0;
const int WALL = 1;
const int VIRUS = 2;
const int MAX_COUNT_OF_WALL = 3;
const int NUMBER_OF_DIRECTION = 4;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

int laboratory[MAX_NUMBER][MAX_NUMBER];
int countOfSafetyZone = 0;

void constructWallAndCheckSafetyZone(int numberOfWall, queue<pair<int,int>> &virusCoordinateQueue);
void spreadVirus(queue<pair<int, int>> virusCoordinateQueue);
void checkSafetyZone();
void initVirus(queue<pair<int, int>> virusCoordinateQueue);

int N, M;
int main() {
	cin >> N >> M;

	queue<pair<int, int>> virusCoordinateQueue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> laboratory[i][j];

			if (laboratory[i][j] == VIRUS) {
				pair<int, int> currentVirusCoordinate = make_pair(i, j);
				virusCoordinateQueue.push(currentVirusCoordinate);
			}
		}
	}

	constructWallAndCheckSafetyZone(0, virusCoordinateQueue);

	cout << countOfSafetyZone << '\n';
}

void constructWallAndCheckSafetyZone(int numberOfWall, queue<pair<int, int>> &virusCoordinateQueue) {
	if (numberOfWall == MAX_COUNT_OF_WALL) {
		spreadVirus(virusCoordinateQueue);
		checkSafetyZone();
		initVirus(virusCoordinateQueue);
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (laboratory[i][j] == BLANK_SPACE) {
					laboratory[i][j] = WALL;
					constructWallAndCheckSafetyZone(numberOfWall + 1, virusCoordinateQueue);
					laboratory[i][j] = BLANK_SPACE;
				}
			}
		}
	}
}

void spreadVirus(queue<pair<int, int>> virusCoordinateQueue) {
	while (!virusCoordinateQueue.empty()) {
		pair<int, int> currentVirusCoordinate = virusCoordinateQueue.front();
		virusCoordinateQueue.pop();

		int currentVirusXCoordinate = currentVirusCoordinate.first;
		int currentVirusYCoordinate = currentVirusCoordinate.second;

		for (int i = 0; i < NUMBER_OF_DIRECTION; i++) {
			int nextVirusXCoordinate = currentVirusXCoordinate + moveXCoordinate[i];
			int nextVirusYCoordinate = currentVirusYCoordinate + moveYCoordinate[i];

			if (nextVirusXCoordinate < 0 || nextVirusXCoordinate == N || nextVirusYCoordinate < 0 || nextVirusYCoordinate == M) {
				continue;
			}

			if (laboratory[nextVirusXCoordinate][nextVirusYCoordinate] == WALL || laboratory[nextVirusXCoordinate][nextVirusYCoordinate] == VIRUS) {
				continue;
			}
			
			laboratory[nextVirusXCoordinate][nextVirusYCoordinate] = VIRUS;
			
			pair<int, int> nextVirusCoordinate = make_pair(nextVirusXCoordinate, nextVirusYCoordinate);
			virusCoordinateQueue.push(nextVirusCoordinate);
		}
	}
}

void checkSafetyZone() {
	int currentCountOfSafetyZone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (laboratory[i][j] == BLANK_SPACE) {
				currentCountOfSafetyZone += 1;
			}
		}
	}

	if (currentCountOfSafetyZone > countOfSafetyZone) {
		countOfSafetyZone = currentCountOfSafetyZone;
	}
}

void initVirus(queue<pair<int, int>> virusCoordinateQueue) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (laboratory[i][j] == VIRUS) {
				laboratory[i][j] = BLANK_SPACE;
			}
		}
	}
	
	while (!virusCoordinateQueue.empty()) {
		pair<int, int> currentVirusCoordinate = virusCoordinateQueue.front();
		virusCoordinateQueue.pop();

		int currentVirusXCoordinate = currentVirusCoordinate.first;
		int currentVirusYCoordinate = currentVirusCoordinate.second;

		laboratory[currentVirusXCoordinate][currentVirusYCoordinate] = VIRUS;
	}
}