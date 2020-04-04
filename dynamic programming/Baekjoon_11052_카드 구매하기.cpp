/*
	problem site	:	baekjoon
	problem number	:	11052
	problem name	:	카드 구매하기
	algorithm	:	dynamic programming
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER_OF_CARD = 1000;

int card[MAX_NUMBER_OF_CARD + 1];

void checkMaximumCostOfCard();

int N;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	checkMaximumCostOfCard();
	cout << card[N] << '\n';	
}

void checkMaximumCostOfCard() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if (card[j] + card[i - j] > card[i]) {
				card[i] = card[j] + card[i - j];
			}
		}
	}
}