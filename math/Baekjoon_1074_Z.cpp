//Baekjoon #1074
//algorithm : math

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUMBER = 15;
const int MAX_SQUARE_NUMBER = MAX_NUMBER * 2 + 1;

int squareNumberOfTwo[MAX_SQUARE_NUMBER];

void initSquareNumberOfTwo();
vector<int> binaryNumber(int number);

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	initSquareNumberOfTwo();

	vector<int> binaryNumberOfR = binaryNumber(r);
	vector<int> binaryNumberOfC = binaryNumber(c);

	int orderOfVisit = 0;

	for (int i = 0; i < binaryNumberOfR.size(); i++) {
		if (binaryNumberOfR[i] == 1) {
			orderOfVisit += squareNumberOfTwo[i * 2 + 1];
		}
	}

	for (int i = 0; i < binaryNumberOfC.size(); i++) {
		if (binaryNumberOfC[i] == 1) {
			orderOfVisit += squareNumberOfTwo[i * 2];
		}
	}

	cout << orderOfVisit << endl;
}

void initSquareNumberOfTwo() {
	int startNumber = 1;
	for (int i = 0; i < MAX_SQUARE_NUMBER; i++) {
		squareNumberOfTwo[i] = startNumber;
		startNumber *= 2;
	}
}

vector<int> binaryNumber(int number) {
	vector<int> binaryNumber;

	while (number != 0) {
		if (number % 2 == 1) {
			binaryNumber.push_back(1);
		}
		else {
			binaryNumber.push_back(0);
		}
		number /= 2;
	}

	return binaryNumber;
}