/*
	problem site	:	baekjoon
	problem number	:	10815
	problem name	:	숫자 카드
	algorithm	:	simulation
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_NUMBER = 20000000 + 1;
const int PLUS_NUMBER = 10000000;

bool isGetNumber[MAX_NUMBER];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int number;
		scanf("%d", &number);

		isGetNumber[number + PLUS_NUMBER] = true;
	}

	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int number;
		scanf("%d", &number);

		if (isGetNumber[number + PLUS_NUMBER] == true) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}

/*
	problem site	:	baekjoon
	problem number	:	10815
	problem name	:	숫자 카드
	algorithm	:	simulation
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sangeunCard;

bool isGetSangeunCard(int number);

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int number;
		scanf("%d", &number);

		sangeunCard.push_back(number);
	}
	sort(sangeunCard.begin(), sangeunCard.end());

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int number;
		scanf("%d", &number);

		if (isGetSangeunCard(number) == true) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}

bool isGetSangeunCard(int number) {
	int startIndex = 0;
	int endIndex = sangeunCard.size() - 1;

	while (startIndex <= endIndex) {
		int middleIndex = (startIndex + endIndex) / 2;

		if (sangeunCard[middleIndex] == number) {
			return true;
		}
		else if (sangeunCard[middleIndex] < number) {
			startIndex = middleIndex + 1;
		}
		else if (sangeunCard[middleIndex] > number) {
			endIndex = middleIndex - 1;
		}
	}


	return false;
}

/*
	problem site	:	baekjoon
	problem number	:	10815
	problem name	:	숫자 카드
	algorithm	:	simulation
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	map<int, bool> sangeunCard;
	for (int i = 0; i < N; i++) {
		int number;
		scanf("%d", &number);

		sangeunCard[number] = true;
	}

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int number;
		scanf("%d", &number);

		if (sangeunCard[number] == true) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}

//순서대로 280ms / 304ms / 724ms