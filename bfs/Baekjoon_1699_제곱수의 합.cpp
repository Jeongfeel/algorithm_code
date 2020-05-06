/*
	problem site	:	baekjoon
	problem number	:	1699
	problem name	:	제곱수의 합
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 100000;

bool isMadeNumber[MAX_NUMBER + 1];

int main() {
	int N;
	cin >> N;

	queue<pair<int, int>> numberAndCountOfSquareNumber;
	numberAndCountOfSquareNumber.push(make_pair(N, 0));

	while (!numberAndCountOfSquareNumber.empty()) {
		int currentNumber = numberAndCountOfSquareNumber.front().first;
		int currentCountOfSquareNumber = numberAndCountOfSquareNumber.front().second;

		if (currentNumber == 0) {
			cout << currentCountOfSquareNumber << '\n';
			break;
		}

		numberAndCountOfSquareNumber.pop();
		for (int i = 1; i*i <= currentNumber; i++) {
			int nextNumber = currentNumber - i * i;
			if (isMadeNumber[nextNumber] == true) {
				continue;
			}
			numberAndCountOfSquareNumber.push(make_pair(nextNumber, currentCountOfSquareNumber + 1));
			isMadeNumber[nextNumber] = true;
		}
	}
}