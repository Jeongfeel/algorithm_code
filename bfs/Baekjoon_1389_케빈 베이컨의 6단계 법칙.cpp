//Baekjoon #1389
//algorithm : bfs

#include <iostream>
#include <queue>
using namespace std;

const int MAX_NUMBER = 100 + 1;
const int MAX_LIMIT_NUMBER = 2147483647;

bool connectionOfUser[MAX_NUMBER][MAX_NUMBER];
int numberOfKevinBacon[MAX_NUMBER][MAX_NUMBER];

void initNumberOfKevinBacon();
void checkNumberOfKevinBacon(int currentUser);

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int firstUser, secondUser;
		cin >> firstUser >> secondUser;

		connectionOfUser[firstUser][secondUser] = 1;
		connectionOfUser[secondUser][firstUser] = 1;
	}

	initNumberOfKevinBacon();

	for (int i = 1; i <= N; i++) {
		checkNumberOfKevinBacon(i);
	}

	int countOfMinimumKevinBacon = MAX_LIMIT_NUMBER;
	int minimumKevinBaconUser = 0;
	
	for (int i = 1; i <= N; i++) {
		int countOfKevinBacon = 0;
		for (int j = 1; j <= N; j++) {
			countOfKevinBacon += numberOfKevinBacon[i][j];
		}

		if (countOfMinimumKevinBacon > countOfKevinBacon) {
			minimumKevinBaconUser = i;
			countOfMinimumKevinBacon = countOfKevinBacon;
		}
	}

	cout << minimumKevinBaconUser << '\n';
}

void initNumberOfKevinBacon() {
	for (int i = 1; i < MAX_NUMBER; i++) {
		for (int j = 1; j < MAX_NUMBER; j++) {
			numberOfKevinBacon[i][j] = -1;
		}
	}
}

void checkNumberOfKevinBacon(int currentUser) {
	numberOfKevinBacon[currentUser][currentUser] = 0;

	queue<int> connectionUserQueue;

	for (int i = 1; i < MAX_NUMBER; i++) {
		if (connectionOfUser[currentUser][i] == 1) {
			connectionUserQueue.push(i);
			numberOfKevinBacon[currentUser][i] = 1;
		}
	}

	while (!connectionUserQueue.empty()) {
		int connectionUser = connectionUserQueue.front();
		connectionUserQueue.pop();

		for (int i = 1; i <= MAX_NUMBER; i++) {
			if (connectionOfUser[connectionUser][i] == 0) {
				continue;
			}

			if (numberOfKevinBacon[currentUser][i] == -1) {
				numberOfKevinBacon[currentUser][i] = numberOfKevinBacon[currentUser][connectionUser] + 1;
				connectionUserQueue.push(i);
			}
			else if (numberOfKevinBacon[currentUser][i] > numberOfKevinBacon[currentUser][connectionUser] + 1) {
				numberOfKevinBacon[currentUser][i] = numberOfKevinBacon[currentUser][connectionUser] + 1;
				connectionUserQueue.push(i);
			}
		}
	}
}