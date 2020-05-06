/*
	problem site	:	baekjoon
	problem number	:	13549
	problem name	:	숨바꼭질3
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 100000;
const int NOT_VISITED = 1024 * 1024 * 1024 * 2 - 1;
int stairTime[MAX_NUMBER + 1];

void initStairTime();

int main() {
	int placeOfSubin, placeOfSister;

	cin >> placeOfSubin >> placeOfSister;

	initStairTime();

	queue<pair<int, int>> placeOfSubinAndTimeQueue;
	placeOfSubinAndTimeQueue.push(make_pair(placeOfSubin, 0));

	stairTime[placeOfSubin] = 0;

	while (!placeOfSubinAndTimeQueue.empty()) {
		int currentPlaceOfSubin = placeOfSubinAndTimeQueue.front().first;
		int currentTime = placeOfSubinAndTimeQueue.front().second;
		
		placeOfSubinAndTimeQueue.pop();

		if (currentPlaceOfSubin + 1 <= MAX_NUMBER && currentTime + 1 < stairTime[currentPlaceOfSubin + 1]) {
			int nextPlaceOfSubin = currentPlaceOfSubin + 1;
			int nextTime = currentTime + 1;

			stairTime[nextPlaceOfSubin] = nextTime;
			placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
		}

		if (currentPlaceOfSubin - 1 >= 0 && currentTime + 1 < stairTime[currentPlaceOfSubin - 1]) {
			int nextPlaceOfSubin = currentPlaceOfSubin - 1;
			int nextTime = currentTime + 1;

			stairTime[nextPlaceOfSubin] = nextTime;
			placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
		}

		if (currentPlaceOfSubin * 2 <= MAX_NUMBER && currentTime < stairTime[currentPlaceOfSubin * 2]) {
			int nextPlaceOfSubin = currentPlaceOfSubin * 2;
			int nextTime = currentTime;

			stairTime[nextPlaceOfSubin] = nextTime;
			placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
		}
	}

	cout << stairTime[placeOfSister] << '\n';
}

void initStairTime() {
	for (int i = 0; i <= MAX_NUMBER; i++) {
		stairTime[i] = NOT_VISITED;
	}
}