/*
	problem site	:	baekjoon
	problem number	:	14501
	problem name	:	퇴사
	algorithm	:	dynamic programming
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 15;

int date[MAX_NUMBER + 1];
int pay[MAX_NUMBER + 1];
int maximumPay[MAX_NUMBER + 1];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> date[i] >> pay[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i + date[i] > N + 1) {
			continue;
		}

		maximumPay[i] = pay[i];
	}

	for (int i = 1; i <= N; i++) {
		int currentDate = date[i] + i;
		int currentPay = maximumPay[i];

		for (int j = currentDate; j <= N; j++) {
			if (j + date[j] > N + 1) {
				continue;
			}

			if (currentPay + pay[j] > maximumPay[j]) {
				maximumPay[j] = currentPay + pay[j];
			}
		}
	}

	int currentMaximumPay = 0;
	for (int i = 1; i <= N; i++) {
		if (maximumPay[i] > currentMaximumPay) {
			currentMaximumPay = maximumPay[i];
		}
	}

	cout << currentMaximumPay << '\n';
}