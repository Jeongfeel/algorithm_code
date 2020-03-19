//Baekjoon #1547
//algorithm : simulation

#include <iostream>
using namespace std;

int main() {
	int switchNumber;
	cin >> switchNumber;

	int firstSwitchCup, secondSwitchCup;
	int currentBallCup = 1;
	for (int i = 0; i < switchNumber; i++) {
		cin >> firstSwitchCup >> secondSwitchCup;

		if (currentBallCup == firstSwitchCup) {
			currentBallCup = secondSwitchCup;
		}
		else if (currentBallCup == secondSwitchCup) {
			currentBallCup = firstSwitchCup;
		}
	}

	cout << currentBallCup << '\n';
}