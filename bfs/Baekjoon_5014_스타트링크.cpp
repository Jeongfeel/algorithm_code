/*
	problem site	:	baekjoon
	problem number	:	5014
	problem name	:	스타트링크
	algorithm		:	bfs
*/

#include <iostream>
#include <queue>
using namespace std;

const int MAX_NUMBER = 1000000;

int clickButtonNumber[MAX_NUMBER + 1];

void initClickButtonNumber();

int main() {
	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	initClickButtonNumber();
	
	queue<int> moveablePositionQueue;
	moveablePositionQueue.push(S);

	clickButtonNumber[S] = 0;

	while (!moveablePositionQueue.empty()) {
		int currentPosition = moveablePositionQueue.front();
		moveablePositionQueue.pop();

		if (currentPosition == G) {
			break;
		}

		int nextUpPosition = currentPosition + U;
		if (nextUpPosition <= F && clickButtonNumber[nextUpPosition] == -1) {
			clickButtonNumber[nextUpPosition] = clickButtonNumber[currentPosition] + 1;
			moveablePositionQueue.push(nextUpPosition);
		}

		int nextDownPosition = currentPosition - D;
		if (nextDownPosition > 0 && clickButtonNumber[nextDownPosition] == -1) {
			clickButtonNumber[nextDownPosition] = clickButtonNumber[currentPosition] + 1;
			moveablePositionQueue.push(nextDownPosition);
		}
	}

	if (clickButtonNumber[G] == -1) {
		cout << "use the stairs" << '\n';
	}
	else {
		cout << clickButtonNumber[G] << '\n';
	}
}

void initClickButtonNumber() {
	for (int i = 0; i <= MAX_NUMBER; i++) {
		clickButtonNumber[i] = -1;
	}
}