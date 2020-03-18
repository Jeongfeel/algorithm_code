//Baekjoon #14890
//algorithm : simulation

#include <iostream>
using namespace std;

const int MAX_NUMBER = 100;

int map[MAX_NUMBER][MAX_NUMBER];
bool isConstructedSlopeHorizontally[MAX_NUMBER][MAX_NUMBER];
bool isConstructedSlopeVertically[MAX_NUMBER][MAX_NUMBER];

int countOfWayToMoveFromStartToEndHorizontally();
int countOfWayToMoveFromStartToEndVertically();

int N, L;

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cout << countOfWayToMoveFromStartToEndHorizontally() + countOfWayToMoveFromStartToEndVertically() << '\n';
}

int countOfWayToMoveFromStartToEndHorizontally() {
	int countOfWay = 0;

	for (int i = 0; i < N; i++) {
		bool isConstructed = true;
		int currentHeight = map[i][0];

		for (int j = 1; j < N; j++) {
			if (currentHeight == map[i][j]) {
				continue;
			}

			if (abs(currentHeight - map[i][j]) != 1) {
				isConstructed = false;
				break;
			}

			if (currentHeight - map[i][j] == 1) {
				for (int k = 0; k < L; k++) {
					if (j + k == N) {
						isConstructed = false;
						break;
					}

					if (currentHeight - map[i][j + k] == 1 && isConstructedSlopeHorizontally[i][j + k] == false) {
						isConstructedSlopeHorizontally[i][j + k] = true;
						continue;
					}

					isConstructed = false;
				}
			}
			else if (currentHeight - map[i][j] == -1) {
				for (int k = 1; k <= L; k++) {
					if (j - k < 0) {
						isConstructed = false;
						break;
					}

					if (currentHeight - map[i][j - k] == 0 && isConstructedSlopeHorizontally[i][j - k] == false) {
						isConstructedSlopeHorizontally[i][j - k] = true;
						continue;
					}

					isConstructed = false;
				}
			}

			if (isConstructed == false) {
				break;
			}

			j += (L - 1);
			currentHeight = map[i][j];
		}

		if (isConstructed == true) {
			countOfWay += 1;
		}
	}

	return countOfWay;
}

int countOfWayToMoveFromStartToEndVertically() {
	int countOfWay = 0;

	for (int i = 0; i < N; i++) {
		bool isConstructed = true;
		int currentHeight = map[0][i];

		for (int j = 1; j < N; j++) {
			if (currentHeight == map[j][i]) {
				continue;
			}

			if (abs(currentHeight - map[j][i]) != 1) {
				isConstructed = false;
				break;
			}

			if (currentHeight - map[j][i] == 1) {
				for (int k = 0; k < L; k++) {
					if (j + k == N) {
						isConstructed = false;
						break;
					}

					if (currentHeight - map[j + k][i] == 1 && isConstructedSlopeVertically[j + k][i] == false) {
						isConstructedSlopeVertically[j + k][i] = true;
						continue;
					}

					isConstructed = false;
				}
			}
			else if (currentHeight - map[j][i] == -1) {
				for (int k = 1; k <= L; k++) {
					if (j - k < 0) {
						isConstructed = false;
						break;
					}

					if (currentHeight - map[j - k][i] == 0 && isConstructedSlopeVertically[j - k][i] == false) {
						isConstructedSlopeVertically[j - k][i] = true;
						continue;
					}

					isConstructed = false;
				}
			}

			if (isConstructed == false) {
				break;
			}

			currentHeight = map[j][i];
		}

		if (isConstructed == true) {
			countOfWay += 1;
		}
	}

	return countOfWay;
}
