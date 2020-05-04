/*
	problem site	:	baekjoon
	problem number	:	13913
	problem name	:	숨바꼭질4
	algorithm	:	bfs
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int MAX_NUMBER = 100000;

int distanceOfPlace[MAX_NUMBER + 1];
int previousPlace[MAX_NUMBER + 1];
bool isVisitedPlace[MAX_NUMBER + 1];

void checkMinimumDistance(int placeOfSubin, int placeOfSister);
void initDistanceOfPlace();
void initPreviousPlace();

int main() {
	int placeOfSubin, placeOfSister;
	cin >> placeOfSubin >> placeOfSister;
	checkMinimumDistance(placeOfSubin, placeOfSister);

	cout << distanceOfPlace[placeOfSister] << '\n';

	stack<int> traceOfSubin;
	while (previousPlace[placeOfSister] != placeOfSister) {
		traceOfSubin.push(placeOfSister);
		placeOfSister = previousPlace[placeOfSister];
	}
	traceOfSubin.push(placeOfSubin);

	while (!traceOfSubin.empty()) {
		cout << traceOfSubin.top() << " ";
		traceOfSubin.pop();
	}
}

void initDistanceOfPlace() {
	for (int i = 0; i < MAX_NUMBER + 1; i++) {
		distanceOfPlace[i] = 1024 * 1024 * 1024 * 2 - 1;
	}
}

void initPreviousPlace() {
	for (int i = 0; i < MAX_NUMBER + 1; i++) {
		previousPlace[i] = i;
	}
}

void checkMinimumDistance(int placeOfSubin, int placeOfSister) {
	initPreviousPlace();
	initDistanceOfPlace();

	queue<int> moveableSubinPlace;
	moveableSubinPlace.push(placeOfSubin);
	
	distanceOfPlace[placeOfSubin] = 0;
	isVisitedPlace[placeOfSubin] = true;

	while (!moveableSubinPlace.empty()) {
		int currentPlaceOfSubin = moveableSubinPlace.front();
		moveableSubinPlace.pop();

		if (currentPlaceOfSubin + 1 <= MAX_NUMBER) {
			int nextPlaceOfSubin = currentPlaceOfSubin + 1;

			if (isVisitedPlace[nextPlaceOfSubin] == false) {
				isVisitedPlace[nextPlaceOfSubin] = true;
				distanceOfPlace[nextPlaceOfSubin] = distanceOfPlace[currentPlaceOfSubin] + 1;
				moveableSubinPlace.push(nextPlaceOfSubin);
				previousPlace[nextPlaceOfSubin] = currentPlaceOfSubin;
			}
		}

		if (currentPlaceOfSubin - 1 >= 0) {
			int nextPlaceOfSubin = currentPlaceOfSubin - 1;

			if (isVisitedPlace[nextPlaceOfSubin] == false) {
				isVisitedPlace[nextPlaceOfSubin] = true;
				distanceOfPlace[nextPlaceOfSubin] = distanceOfPlace[currentPlaceOfSubin] + 1;
				moveableSubinPlace.push(nextPlaceOfSubin);
				previousPlace[nextPlaceOfSubin] = currentPlaceOfSubin;
			}
		}

		if (currentPlaceOfSubin * 2 <= MAX_NUMBER) {
			int nextPlaceOfSubin = currentPlaceOfSubin * 2;

			if (isVisitedPlace[nextPlaceOfSubin] == false) {
				isVisitedPlace[nextPlaceOfSubin] = true;
				distanceOfPlace[nextPlaceOfSubin] = distanceOfPlace[currentPlaceOfSubin] + 1;
				moveableSubinPlace.push(nextPlaceOfSubin);
				previousPlace[nextPlaceOfSubin] = currentPlaceOfSubin;
			}
		}
	}
}