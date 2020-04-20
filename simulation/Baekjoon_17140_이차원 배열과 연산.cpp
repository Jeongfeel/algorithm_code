/*
	problem site	:	baekjoon
	problem number	:	17140
	problem name	:	이차원 배열과 연산
	algorithm	:	simulation
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int MAX_NUMBER_OF_ARRAY = 100;
const int START_LIMIT = 3;
const int LIMIT_TIME = 100;

int twoDimension[MAX_NUMBER_OF_ARRAY + 1][MAX_NUMBER_OF_ARRAY + 1];
int numberArray[MAX_NUMBER_OF_ARRAY + 1];

void operationOfR();
void operationOfC();
void initNumberArray();
vector<pair<int, int>> checkNumberAndCount();
void applyOperationOfR(int indexOfRow, vector<pair<int, int>> countrAndNumber);
void applyOperationOfC(int indexOfColumn, vector<pair<int, int>> countrAndNumber);

int countOfRow = 3;
int countOfColumn = 3;

int r, c, k;
int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= START_LIMIT; i++) {
		for (int j = 1; j <= START_LIMIT; j++) {
			cin >> twoDimension[i][j];
		}
	}

	int startTime = 0;
	
	while (startTime <= LIMIT_TIME) {
		if (twoDimension[r][c] == k) {
			break;
		}

		if (countOfRow >= countOfColumn) {
			operationOfR();
		}
		else {
			operationOfC();
		}

		startTime += 1;
	}

	if (startTime > LIMIT_TIME) {
		cout << "-1" << '\n';
	}
	else {
		cout << startTime << '\n';
	}
}

void operationOfR() {
	int maximumCountOfColumn = 0;

	for (int i = 1; i <= countOfRow; i++) {
		initNumberArray();
		
		for (int j = 1; j <= countOfColumn; j++) {
			if (twoDimension[i][j] == 0) {
				continue;
			}

			numberArray[twoDimension[i][j]] += 1;
		}

		vector<pair<int, int>> numberAndCount = checkNumberAndCount();
		sort(numberAndCount.begin(), numberAndCount.end());

		applyOperationOfR(i, numberAndCount);

		int currentCountOfColumn = numberAndCount.size() * 2;
		if (maximumCountOfColumn < currentCountOfColumn) {
			maximumCountOfColumn = currentCountOfColumn;
		}
	}

	countOfColumn = maximumCountOfColumn;
	if (countOfColumn >= MAX_NUMBER_OF_ARRAY) {
		countOfColumn = MAX_NUMBER_OF_ARRAY;
	}
}

void applyOperationOfR(int indexOfRow, vector<pair<int, int>> countAndNumber) {
	int countAndNumberSize = countAndNumber.size();
	if (countAndNumberSize >= MAX_NUMBER_OF_ARRAY / 2) {
		countAndNumberSize = MAX_NUMBER_OF_ARRAY / 2;
	}

	for (int i = 0; i < countAndNumberSize; i++) {
		twoDimension[indexOfRow][i * 2 + 1] = countAndNumber[i].second;
		twoDimension[indexOfRow][i * 2 + 2] = countAndNumber[i].first;
	}

	for (int i = countAndNumberSize * 2 + 1; i <= MAX_NUMBER_OF_ARRAY; i++) {
		twoDimension[indexOfRow][i] = 0;
	}
}

void operationOfC() {
	int maximumCountOfRow = 0;

	for (int i = 1; i <= countOfColumn; i++) {
		initNumberArray();

		for (int j = 1; j <= countOfRow; j++) {
			if (twoDimension[j][i] == 0) {
				continue;
			}

			numberArray[twoDimension[j][i]] += 1;
		}

		vector<pair<int, int>> numberAndCount = checkNumberAndCount();
		sort(numberAndCount.begin(), numberAndCount.end());

		applyOperationOfC(i, numberAndCount);

		int currentCountOfRow = numberAndCount.size() * 2;
		if (maximumCountOfRow < currentCountOfRow) {
			maximumCountOfRow = currentCountOfRow;
		}
	}

	countOfRow = maximumCountOfRow;

	if (countOfRow >= MAX_NUMBER_OF_ARRAY) {
		countOfRow = MAX_NUMBER_OF_ARRAY;
	}
}

void applyOperationOfC(int indexOfColumn, vector<pair<int, int>> countAndNumber) {
	int countAndNumberSize = countAndNumber.size();
	if (countAndNumberSize >= MAX_NUMBER_OF_ARRAY / 2) {
		countAndNumberSize = MAX_NUMBER_OF_ARRAY / 2;
	}

	for (int i = 0; i < countAndNumberSize; i++) {
		twoDimension[i * 2 + 1][indexOfColumn] = countAndNumber[i].second;
		twoDimension[i * 2 + 2][indexOfColumn] = countAndNumber[i].first;
	}

	for (int i = countAndNumberSize * 2 + 1; i <= MAX_NUMBER_OF_ARRAY; i++) {
		twoDimension[i][indexOfColumn] = 0;
	}
}

void initNumberArray() {
	for (int i = 1; i <= MAX_NUMBER_OF_ARRAY; i++) {
		numberArray[i] = 0;
	}
}

vector<pair<int, int>> checkNumberAndCount() {
	vector<pair<int, int>> numberAndCount;

	for (int i = 1; i <= MAX_NUMBER_OF_ARRAY; i++) {
		if (numberArray[i] == 0) {
			continue;
		}

		numberAndCount.push_back(make_pair(numberArray[i], i));
	}

	return numberAndCount;
}