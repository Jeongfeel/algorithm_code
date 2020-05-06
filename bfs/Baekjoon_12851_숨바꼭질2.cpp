/*
	problem site	:	baekjoon
	problem number	:	12851
	problem name	:	숨바꼭질2
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER_OF_STAIR = 100000;

int visitedStairTime[MAX_NUMBER_OF_STAIR + 1];

int findWayOfArriveDestination(queue<pair<int, int>> placeOfSubinAndTimeQueue, int destinationTime);

void initIsVistedStair();

int placeOfSubin, placeOfSister;
int main() {
	cin >> placeOfSubin >> placeOfSister;

	queue<pair<int, int>> placeOfSubinAndTimeQueue;
	placeOfSubinAndTimeQueue.push(make_pair(placeOfSubin, 0));

	initIsVistedStair();

	int destinationTime, wayOfArriveDestination;
	while (!placeOfSubinAndTimeQueue.empty()) {
		int currentPlaceOfSubin = placeOfSubinAndTimeQueue.front().first;
		int currentTime = placeOfSubinAndTimeQueue.front().second;

		placeOfSubinAndTimeQueue.pop();
		if (currentPlaceOfSubin == placeOfSister) {
			destinationTime = currentTime;
			wayOfArriveDestination = findWayOfArriveDestination(placeOfSubinAndTimeQueue, currentTime);
			break;
		}
		else {
			if (currentPlaceOfSubin + 1 <= MAX_NUMBER_OF_STAIR && visitedStairTime[currentPlaceOfSubin + 1] >= currentTime + 1) {
				int nextPlaceOfSubin = currentPlaceOfSubin + 1;
				int nextTime = currentTime + 1;

				placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
				visitedStairTime[nextPlaceOfSubin] = nextTime;
			}

			if (currentPlaceOfSubin - 1 >= 0 && visitedStairTime[currentPlaceOfSubin - 1] >= currentTime + 1) {
				int nextPlaceOfSubin = currentPlaceOfSubin - 1;
				int nextTime = currentTime + 1;

				placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
				visitedStairTime[nextPlaceOfSubin] = nextTime;
			}

			if (currentPlaceOfSubin * 2 <= MAX_NUMBER_OF_STAIR && visitedStairTime[currentPlaceOfSubin * 2] >= currentTime + 1) {
				int nextPlaceOfSubin = currentPlaceOfSubin * 2;
				int nextTime = currentTime + 1;

				placeOfSubinAndTimeQueue.push(make_pair(nextPlaceOfSubin, nextTime));
				visitedStairTime[nextPlaceOfSubin] = nextTime;
			}
		}
	}

	cout << destinationTime << '\n' << wayOfArriveDestination << '\n';
}

int findWayOfArriveDestination(queue<pair<int, int>> placeOfSubinAndTimeQueue, int destinationTime) {
	int wayOfArriveDestination = 1;
	while (!placeOfSubinAndTimeQueue.empty()) {
		if (placeOfSubinAndTimeQueue.front().first != placeOfSister) {
			placeOfSubinAndTimeQueue.pop();
			continue;
		}

		if (placeOfSubinAndTimeQueue.front().second > destinationTime) {
			placeOfSubinAndTimeQueue.pop();
			break;
		}

		wayOfArriveDestination += 1;
		placeOfSubinAndTimeQueue.pop();
	}

	return wayOfArriveDestination;
}

void initIsVistedStair() {
	for (int i = 0; i <= MAX_NUMBER_OF_STAIR; i++) {
		visitedStairTime[i] = 1024 * 1024 * 1024 * 2 - 1;
	}
}