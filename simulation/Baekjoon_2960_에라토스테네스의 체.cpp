/*
	problem site	:	baekjoon
	problem number	:	2960
	problem name	:	에라토스테네스의 체
	algorithm	:	simulation
*/

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000;
bool primeNumber[MAX_NUMBER + 1];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (primeNumber[j] == false) {
				K--;
				primeNumber[j] = true;
			}

			if (K == 0) {
				cout << j << '\n';
				return 0;
			}
		}
	}
}