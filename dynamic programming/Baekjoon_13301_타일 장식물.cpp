/*
	problem site	:	baekjoon
	problem number	:	13301
	problem name	:	타일 장식물
	algorithm	:	dynamic programming
*/

#include <iostream>
using namespace std;

const int MAX_COUNT_OF_TILE = 80;

long long tile[MAX_COUNT_OF_TILE + 2];

void initTile();

int main() {
	int N;
	cin >> N;

	initTile();

	for (int i = 3; i <= N + 1; i++) {
		tile[i] = tile[i - 2] + tile[i - 1];
	}

	cout << tile[N + 1] * 2 + tile[N] * 2 << endl;
}

void initTile() {
	tile[1] = 1;
	tile[2] = 1;
}