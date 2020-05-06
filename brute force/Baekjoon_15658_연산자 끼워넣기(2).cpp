/*
	problem site	:	baekjoon
	problem number	:	15658
	problem name	:	연산자 끼워넣기(2)
	algorithm	:	brute force
*/

#include <iostream>
#include <vector>
using namespace std;

int countOfOperator[4];

void checkMaximumAndMinimumNumber(int currentIndex, int currentNumber);

int maximumNumber = -1000000000;
int minimumNumber = 1000000000;

int N;
vector<int> numberVector;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;

		numberVector.push_back(number);
	}

	for (int i = 0; i < 4; i++) {
		cin >> countOfOperator[i];
	}

	checkMaximumAndMinimumNumber(1, numberVector[0]);

	cout << maximumNumber << '\n' << minimumNumber << '\n';
}

void checkMaximumAndMinimumNumber(int currentIndex, int currentNumber) {
	if (currentIndex == N) {
		if (currentNumber > maximumNumber) {
			maximumNumber = currentNumber;
		}
		if (currentNumber < minimumNumber) {
			minimumNumber = currentNumber;
		}
	}
	else {
		if (countOfOperator[0] > 0) {
			countOfOperator[0] -= 1;
			int nextNumber = currentNumber + numberVector[currentIndex];
			checkMaximumAndMinimumNumber(currentIndex + 1, nextNumber);
			countOfOperator[0] += 1;
		}
		if (countOfOperator[1] > 0) {
			countOfOperator[1] -= 1;
			int nextNumber = currentNumber - numberVector[currentIndex];
			checkMaximumAndMinimumNumber(currentIndex + 1, nextNumber);
			countOfOperator[1] += 1;
		}
		if (countOfOperator[2] > 0) {
			countOfOperator[2] -= 1;
			int nextNumber = currentNumber * numberVector[currentIndex];
			checkMaximumAndMinimumNumber(currentIndex + 1, nextNumber);
			countOfOperator[2] += 1;
		}
		if (countOfOperator[3] > 0) {
			countOfOperator[3] -= 1;
			int nextNumber = currentNumber / numberVector[currentIndex];
			checkMaximumAndMinimumNumber(currentIndex + 1, nextNumber);
			countOfOperator[3] += 1;
		}
	}
}