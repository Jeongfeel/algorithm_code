/*
	problem site	:	baekjoon
	problem number	:	17281
	problem name	:	⚾
	algorithm	:	brute force
*/

#include <iostream>
using namespace std;

const int MAX_INNING = 50;
const int NUMBER_OF_PLAYER = 9;
const int OUT = 0;
const int HIT = 1;
const int TWO_BASE_HIT = 2;
const int THREE_BASE_HIT = 3;
const int HOME_RUN = 4;
const int NOT_EXIST_PLAYER = 0;
const int EXIST_PLAYER = 1;


int resultOfEachInning[MAX_INNING + 1][NUMBER_OF_PLAYER + 1];
int orderOfPlayer[NUMBER_OF_PLAYER + 1];

bool isAssingedPlayer[NUMBER_OF_PLAYER + 1];
bool isAllPlayerAssigned();

void assignPlayerOrder(int currentOrder);
void checkMaximumScore();
void initBase(int *base);

void checkHit(int *base, int &currentScore);
void checkTwoBaseHit(int *base, int &currentScore);
void checkThreeBaseHit(int *base ,int &currentScore);
void checkHomeRun(int *base ,int &currentScore);

int maximumScore = 0;

int N;
int main() {
	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < NUMBER_OF_PLAYER + 1; j++) {
			cin >> resultOfEachInning[i][j];
		}
	}
	
	orderOfPlayer[4] = 1;
	isAssingedPlayer[1] = true;
	
	assignPlayerOrder(1);

	cout << maximumScore << '\n';
}

void assignPlayerOrder(int currentOrder) {
	if (currentOrder == 4) {
		currentOrder += 1;
	}

	if (isAllPlayerAssigned() == true) {
		checkMaximumScore();
	}
	else {
		for (int i = 1; i < NUMBER_OF_PLAYER + 1; i++) {
			if (isAssingedPlayer[i] == false) {
				isAssingedPlayer[i] = true;
				orderOfPlayer[currentOrder] = i;
				assignPlayerOrder(currentOrder + 1);
				isAssingedPlayer[i] = false;
			}
		}
	}
}

bool isAllPlayerAssigned() {
	for (int i = 1; i < NUMBER_OF_PLAYER + 1; i++) {
		if (isAssingedPlayer[i] == false) {
			return false;
		}
	}

	return true;
}

void checkMaximumScore() {
	int currentScore = 0;
	int currentInning = 1;
	int currentOrder = 1;
	int currentOutCount = 0;

	int base[4];
	initBase(&base[0]);
	
	while (currentInning <= N) {
		int currentPlayer = orderOfPlayer[currentOrder];

		if (resultOfEachInning[currentInning][currentPlayer] == OUT) {
			currentOutCount += 1;
		}
		else if (resultOfEachInning[currentInning][currentPlayer] == HIT) {
			checkHit(&base[0], currentScore);
		}
		else if (resultOfEachInning[currentInning][currentPlayer] == TWO_BASE_HIT) {
			checkTwoBaseHit(&base[0], currentScore);
		}
		else if (resultOfEachInning[currentInning][currentPlayer] == THREE_BASE_HIT) {
			checkThreeBaseHit(&base[0], currentScore);
		}
		else if (resultOfEachInning[currentInning][currentPlayer] == HOME_RUN) {
			checkHomeRun(&base[0], currentScore);
		}

		currentOrder += 1;

		if (currentOutCount == 3) {
			currentOutCount = 0;
			currentInning += 1;
			initBase(&base[0]);
		}
		if (currentOrder == 10) {
			currentOrder = 1;
		}
	}

	if (maximumScore < currentScore) {
		maximumScore = currentScore;
	}
}

void initBase(int *base) {
	for (int i = 0; i < 4; i++) {
		base[i] = 0;
	}
}

void checkHit(int *base, int &currentScore) {
	if (base[3] == EXIST_PLAYER) {
		base[3] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[2] == EXIST_PLAYER) {
		base[2] = NOT_EXIST_PLAYER;
		base[3] = EXIST_PLAYER;
	}
	if (base[1] == EXIST_PLAYER) {
		base[2] = EXIST_PLAYER;
		base[1] = NOT_EXIST_PLAYER;
	}

	base[1] = EXIST_PLAYER;
}

void checkTwoBaseHit(int *base, int &currentScore) {
	if (base[3] == EXIST_PLAYER) {
		base[3] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[2] == EXIST_PLAYER) {
		base[2] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[1] == EXIST_PLAYER) {
		base[3] = EXIST_PLAYER;
		base[1] = NOT_EXIST_PLAYER;
	}

	base[2] = EXIST_PLAYER;
}

void checkThreeBaseHit(int *base, int &currentScore) {
	if (base[3] == EXIST_PLAYER) {
		base[3] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[2] == EXIST_PLAYER) {
		base[2] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[1] == EXIST_PLAYER) {
		base[1] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}

	base[3] = EXIST_PLAYER;
}

void checkHomeRun(int *base, int &currentScore) {
	if (base[3] == EXIST_PLAYER) {
		base[3] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[2] == EXIST_PLAYER) {
		base[2] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}
	if (base[1] == EXIST_PLAYER) {
		base[1] = NOT_EXIST_PLAYER;
		currentScore += 1;
	}

	currentScore += 1;
}
