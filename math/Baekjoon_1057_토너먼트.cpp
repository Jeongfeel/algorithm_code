/*
	problem site	:	baekjoon
	problem number	:	1057
	problem name	:	토너먼트
	algorithm		:	math
*/

#include <iostream>
using namespace std;

int main() {
	int numberOfParticipant, numberOfKim, numberOfLim;
	cin >> numberOfParticipant >> numberOfKim >> numberOfLim;

	int numberOfRound = 0;

	while (numberOfKim != numberOfLim) {
		if (numberOfKim % 2 == 1) {
			numberOfKim /= 2;
			numberOfKim += 1;
		}
		else {
			numberOfKim /= 2;
		}

		if (numberOfLim % 2 == 1) {
			numberOfLim /= 2;
			numberOfLim += 1;
		}
		else {
			numberOfLim /= 2;
		}

		numberOfRound += 1;
	}

	cout << numberOfRound << '\n';
}