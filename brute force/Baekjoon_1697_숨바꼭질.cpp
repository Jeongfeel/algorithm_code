/*
	problem site	:	baekjoon
	problem number	:	1697
	problem name	:	숨바꼭질
	algorithm		:	brute force
*/

#include <iostream>
#include <queue>
using namespace std;

const int MAX_NUMBER = 100000;

int possiblePositionArray[MAX_NUMBER + 1];

int main() {
	int N, K;
	cin >> N >> K;

	queue<int> possiblePositionQueue;
	possiblePositionQueue.push(N);

	while (!possiblePositionQueue.empty()) {
		int currentPosition = possiblePositionQueue.front();
		possiblePositionQueue.pop();

		if (currentPosition == K) {
			break;
		}

		int minusPosition = currentPosition - 1;
		if (minusPosition >= 0 && possiblePositionArray[minusPosition] == 0) {
			possiblePositionArray[minusPosition] = possiblePositionArray[currentPosition] + 1;
			possiblePositionQueue.push(minusPosition);
		}

		int plusPosition = currentPosition + 1;
		if (plusPosition <= MAX_NUMBER && possiblePositionArray[plusPosition] == 0) {
			possiblePositionArray[plusPosition] = possiblePositionArray[currentPosition] + 1;
			possiblePositionQueue.push(plusPosition);
		}

		int twicePosition = 2 * currentPosition;
		if (twicePosition <= MAX_NUMBER && possiblePositionArray[twicePosition] == 0) {
			possiblePositionArray[twicePosition] = possiblePositionArray[currentPosition] + 1;
			possiblePositionQueue.push(twicePosition);
		}
	}

	cout << possiblePositionArray[K] << '\n';
}