/*
	problem site	:	baekjoon
	problem number	:	9019
	problem name	:	DSLR
	algorithm	:	bfs
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX_NUMBER = 10000;
const int D = 0;
const int S = 1;
const int L = 2;
const int R = 3;
const string NOT_VISITED = "";

string isVisitedNumber[MAX_NUMBER];

void printMinimumLengthOfCommand(int A, int B);
void initIsVisitedNumber();
int makeNextNumberByOperation(int currentNumber, int i);
int doDOperation(int currentNumber);
int doSOperation(int currentNumber);
int doLOperation(int currentNumber);
int doROperation(int currentNumber);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int A, B;
		cin >> A >> B;

		printMinimumLengthOfCommand(A, B);
	}
}

void printMinimumLengthOfCommand(int A, int B) {
	initIsVisitedNumber();
	
	queue<int> commandQueue;
	commandQueue.push(A);

	while (!commandQueue.empty()) {
		int currentNumber = commandQueue.front();
		string currentCommand = isVisitedNumber[currentNumber];
		commandQueue.pop();

		if (currentNumber == B) {
			cout << currentCommand << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextNumber = makeNextNumberByOperation(currentNumber, i);
			
			if (isVisitedNumber[nextNumber] != NOT_VISITED) {
				continue;
			}

			if (i == D) {
				isVisitedNumber[nextNumber] = currentCommand + "D";
			}								  
			else if (i == S) {				  
				isVisitedNumber[nextNumber] = currentCommand + "S";
			}								  
			else if (i == L) {				  
				isVisitedNumber[nextNumber] = currentCommand + "L";
			}								  
			else if (i == R) {				  
				isVisitedNumber[nextNumber] = currentCommand + "R";
			}

			commandQueue.push(nextNumber);
		}
	}
}

void initIsVisitedNumber() {
	for (int i = 0; i < MAX_NUMBER; i++) {
		isVisitedNumber[i] = NOT_VISITED;
	}
}

int makeNextNumberByOperation(int currentNumber, int i) {
	int nextNumber;
	if (i == D) {
		nextNumber = doDOperation(currentNumber);
	}
	else if (i == S) {
		nextNumber = doSOperation(currentNumber);
	}
	else if (i == L) {
		nextNumber = doLOperation(currentNumber);
	}
	else if (i == R) {
		nextNumber = doROperation(currentNumber);
	}

	return nextNumber;
}

int doDOperation(int currentNumber) {
	int nextNumber = currentNumber * 2 % MAX_NUMBER;

	return nextNumber;
}

int doSOperation(int currentNumber) {
	int nextNumber = currentNumber - 1;
	if (nextNumber == -1) {
		nextNumber = MAX_NUMBER - 1;
	}

	return nextNumber;
}

int doLOperation(int currentNumber) {
	int firstNumber = currentNumber / 1000;
	int secondNumber = currentNumber % 1000 / 100;
	int thirdNumber = currentNumber % 100 / 10;
	int fourthNumber = currentNumber % 10;

	int nextNumber = firstNumber + secondNumber * 1000 + thirdNumber * 100 + fourthNumber * 10;

	return nextNumber;
}

int doROperation(int currentNumber) {
	int firstNumber = currentNumber / 1000;
	int secondNumber = currentNumber % 1000 / 100;
	int thirdNumber = currentNumber % 100 / 10;
	int fourthNumber = currentNumber % 10;

	int nextNumber = firstNumber * 100 + secondNumber * 10 + thirdNumber + fourthNumber * 1000;

	return nextNumber;
}
