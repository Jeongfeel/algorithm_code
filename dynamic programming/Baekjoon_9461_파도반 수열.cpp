//Baekjoon #9461
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 100 + 1;

int spiralTriangleSideLengthByIndex[MAX_NUMBER];

void findSpiralTriangleSideLengthByIndex(int index);
void initSpiralTriangleSideLength();

int main() {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		int N;
		cin >> N;

		findSpiralTriangleSideLengthByIndex(N);
	}
}

void findSpiralTriangleSideLengthByIndex(int index) {
	initSpiralTriangleSideLength();

	for (int i = 6; i <= index; i++) {
		spiralTriangleSideLengthByIndex[i] = spiralTriangleSideLengthByIndex[i - 5] + spiralTriangleSideLengthByIndex[i - 1];
	}

	cout << spiralTriangleSideLengthByIndex[index] << '\n';
}

void initSpiralTriangleSideLength() {
	spiralTriangleSideLengthByIndex[1] = 1;
	spiralTriangleSideLengthByIndex[2] = 1;
	spiralTriangleSideLengthByIndex[3] = 1;
	spiralTriangleSideLengthByIndex[4] = 2;
	spiralTriangleSideLengthByIndex[5] = 2;
}
