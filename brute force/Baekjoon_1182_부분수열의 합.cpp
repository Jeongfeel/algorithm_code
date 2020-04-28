/*
	problem site	:	baekjoon
	problem number	:	1182
	problem name	:	부분수열의 합
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_LENGTH_OF_ARRAY = 20;

int totalArray[MAX_LENGTH_OF_ARRAY];

void checkSumZero(int index, int sum);

int zeroSumCount = 0;

int N, S;
int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> totalArray[i];
	}

	checkSumZero(0, 0);

	cout << zeroSumCount << '\n';
}

void checkSumZero(int index, int sum) {
	for (int i = index; i < N; i++) {
		int nextSum = sum + totalArray[i];
		
		if (nextSum == S) {
			zeroSumCount += 1;
		}

		checkSumZero(i + 1, nextSum);
	}
}