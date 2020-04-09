/*
	problem site	:	baekjoon
	problem number	:	11054
	problem name	:	가장 긴 바이토닉 부분 수열
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000;

int bitonicArray[MAX_NUMBER];
int upperArray[MAX_NUMBER];
int downArray[MAX_NUMBER];

void checkUpperArray();
void checkDownArray();
void printMostLongerBitonicArrayLength();

int number;
int main() {
	cin >> number;

	for (int i = 0; i < number; i++) {
		cin >> bitonicArray[i];
	}

	checkUpperArray();
	checkDownArray();
	printMostLongerBitonicArrayLength();
}

void checkUpperArray() {
	for (int i = 0; i < number; i++) {
		int currentNumber = bitonicArray[i];
		if (upperArray[i] == 0) {
			upperArray[i] = 1;
		}

		for (int j = i + 1; j < number; j++) {
			if (bitonicArray[j] > bitonicArray[i]) {
				if (upperArray[j] < upperArray[i] + 1) {
					upperArray[j] = upperArray[i] + 1;
				}
			}
		}
	}
}

void checkDownArray() {
	for (int i = number - 1; i >= 0; i--) {
		int currentNumber = bitonicArray[i];
		if (downArray[i] == 0) {
			downArray[i] = 1;
		}

		for (int j = i - 1; j >= 0; j--) {
			if (bitonicArray[j] > bitonicArray[i]) {
				if (downArray[j] < downArray[i] + 1) {
					downArray[j] = downArray[i] + 1;
				}
			}
		}
	}
}

void printMostLongerBitonicArrayLength() {
	int mostLongetBitonicArrayLength = 0;

	for (int i = 0; i < number; i++) {
		int currentBitonicArrayLength = upperArray[i] + downArray[i];

		if (currentBitonicArrayLength > mostLongetBitonicArrayLength) {
			mostLongetBitonicArrayLength = currentBitonicArrayLength;
		}
	}

	cout << mostLongetBitonicArrayLength - 1 << '\n';
}