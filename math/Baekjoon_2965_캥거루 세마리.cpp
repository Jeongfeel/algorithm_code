//Baekjoon #2965
//algorithm : math

#include <iostream>
using namespace std;

int main() {
	int firstKangaroo, secondKangaroo, thirdKangaroo;

	cin >> firstKangaroo >> secondKangaroo >> thirdKangaroo;

	int maximumMoveCount = 0;

	if (thirdKangaroo - secondKangaroo > secondKangaroo - firstKangaroo) {
		maximumMoveCount = thirdKangaroo - secondKangaroo - 1;
	}
	else {
		maximumMoveCount = secondKangaroo - firstKangaroo - 1;
	}

	cout << maximumMoveCount << '\n';
}