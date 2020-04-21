/*
	problem site	:	baekjoon
	problem number	:	14002
	problem name	:	가장 긴 증가하는 부분 수열 4
	algorithm	:	dynamic programming
*/

#include <iostream>
#include <utility>
#include <stack>
using namespace std;

const int MAX_NUMBER = 1000;

int A[MAX_NUMBER];
int countOfIncerasingArray[MAX_NUMBER];
int parentNode[MAX_NUMBER];

void initCountOfIncerasingArray();
void checkIncreasingArray();
void checkMostLongestIncreasingArray();

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	initCountOfIncerasingArray();
	checkIncreasingArray();
	checkMostLongestIncreasingArray();
}

void initCountOfIncerasingArray() {
	for (int i = 0; i < N; i++) {
		countOfIncerasingArray[i] = 1;
		parentNode[i] = i;
	}
}

void checkIncreasingArray() {
	for (int i = 0; i < N; i++) {
		int currentNumber = A[i];
		for (int j = i + 1; j < N; j++) {
			if (currentNumber >= A[j]) {
				continue;
			}

			if (countOfIncerasingArray[j] >= countOfIncerasingArray[i] + 1) {
				continue;
			}
	
			countOfIncerasingArray[j] = countOfIncerasingArray[i] + 1;
			parentNode[j] = i;
		}
	}
}

void checkMostLongestIncreasingArray() {
	int longestLength = 0;
	int longestLengthIndex = 0;
	for (int i = 0; i < N; i++) {
		if (countOfIncerasingArray[i] <= longestLength) {
			continue;
		}

		longestLength = countOfIncerasingArray[i];
		longestLengthIndex = i;
	}

	stack<int> parentNodeStack;

	while (longestLengthIndex != parentNode[longestLengthIndex]) {
		parentNodeStack.push(A[longestLengthIndex]);

		longestLengthIndex = parentNode[longestLengthIndex];
	}
	parentNodeStack.push(A[longestLengthIndex]);

	cout << longestLength << '\n';
	while (!parentNodeStack.empty()) {
		cout << parentNodeStack.top() << " ";
		parentNodeStack.pop();
	}
}