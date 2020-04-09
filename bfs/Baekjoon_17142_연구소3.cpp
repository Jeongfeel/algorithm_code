/*
	problem site	:	baekjoon
	problem number	:	17142
	problem name	:	연구소3
	algorithm	:	bfs
*/

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int SPACE = 0;
const int WALL = 1;
const int INACTIVE_VIRUS = 2;
const int ACTIVE_VIRUS = 3;
const int MAX_SIZE_OF_LABORATORY = 50;

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

int originalLaboratory[MAX_SIZE_OF_LABORATORY][MAX_SIZE_OF_LABORATORY];
int laboratory[MAX_SIZE_OF_LABORATORY][MAX_SIZE_OF_LABORATORY];
int minimumTime = -1;

void checkMinimumTimeToSpreadVirus(vector<pair<int, int>> virusPositionVector);
void initLaboratory(queue<pair<int, int>> currentActiveVirusQueue);
void checkTimeToSpreadVirus(queue<pair<int, int>> currentActiveVirusQueue);
bool isAllPlaceVirus();

int N, M;
int main() {
	cin >> N >> M;

	vector<pair<int, int>> virusPositionVector;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> originalLaboratory[i][j];

			if (originalLaboratory[i][j] == INACTIVE_VIRUS) {
				virusPositionVector.push_back(make_pair(i, j));
			}
		}
	}

	checkMinimumTimeToSpreadVirus(virusPositionVector);

	cout << minimumTime << '\n';
}

void checkMinimumTimeToSpreadVirus(vector<pair<int, int>> virusPositionVector) {
	vector<int> permutationVector;

	for (int i = 0; i < virusPositionVector.size() - M; i++) {
		permutationVector.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		permutationVector.push_back(1);
	}

	do {
		queue<pair<int, int>> currentActiveVirusQueue;
		for (int i = 0; i < permutationVector.size(); i++) {
			if (permutationVector[i] == 0) {
				continue;
			}

			currentActiveVirusQueue.push(virusPositionVector[i]);
		}
		initLaboratory(currentActiveVirusQueue);
		checkTimeToSpreadVirus(currentActiveVirusQueue);
	} while (next_permutation(permutationVector.begin(), permutationVector.end()));
}

void initLaboratory(queue<pair<int, int>> currentActiveVirusQueue) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			laboratory[i][j] = originalLaboratory[i][j];
		}
	}

	while (!currentActiveVirusQueue.empty()) {
		pair<int, int> currentVirusCoordinate = currentActiveVirusQueue.front();
		currentActiveVirusQueue.pop();

		laboratory[currentVirusCoordinate.first][currentVirusCoordinate.second] = ACTIVE_VIRUS;
	}
}

void checkTimeToSpreadVirus(queue<pair<int, int>> currentActiveVirusQueue) {
	int spreadTime = -1;
	int currentActiveVirusCount = currentActiveVirusQueue.size();

	while (!currentActiveVirusQueue.empty()) {
		pair<int, int> currentVirusCoordinate = currentActiveVirusQueue.front();
		currentActiveVirusQueue.pop();
		currentActiveVirusCount -= 1;

		int currentVirusXCoordinate = currentVirusCoordinate.first;
		int currentVirusYCoordinate = currentVirusCoordinate.second;
		for (int i = 0; i < 4; i++) {
			int nextVirusXCoordinate = currentVirusXCoordinate + moveXCoordinate[i];
			int nextVirusYCoordinate = currentVirusYCoordinate + moveYCoordinate[i];

			if (nextVirusXCoordinate < 0 || nextVirusXCoordinate == N || nextVirusYCoordinate < 0 || nextVirusYCoordinate == N) {
				continue;
			}

			if (laboratory[nextVirusXCoordinate][nextVirusYCoordinate] == WALL || laboratory[nextVirusXCoordinate][nextVirusYCoordinate] == ACTIVE_VIRUS) {
				continue;
			}

			if (laboratory[nextVirusXCoordinate][nextVirusYCoordinate] == INACTIVE_VIRUS) {
				if (isAllPlaceVirus() == true) {
					break;
				}
			}

			laboratory[nextVirusXCoordinate][nextVirusYCoordinate] = ACTIVE_VIRUS;
			currentActiveVirusQueue.push(make_pair(nextVirusXCoordinate, nextVirusYCoordinate));
		}

		if (currentActiveVirusCount == 0) {
			spreadTime += 1;
			currentActiveVirusCount = currentActiveVirusQueue.size();
		}
	}
	if (isAllPlaceVirus() == true) {
		if (minimumTime == -1) {
			minimumTime = spreadTime;
		}
		else if (minimumTime > spreadTime) {
			minimumTime = spreadTime;
		}
	}
}

bool isAllPlaceVirus() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (laboratory[i][j] == ACTIVE_VIRUS || laboratory[i][j] == INACTIVE_VIRUS || laboratory[i][j] == WALL) {
				continue;
			}

			return false;
		}
	}

	return true;
}