/*
	problem site	:	baekjoon
	problem number	:	2012
	problem name	:	등수 매기기
	algorithm	:	simulation
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;

int main() {
	int N;
	cin >> N;

	vector<int> expectedRankVector;
	for (int i = 0; i < N; i++) {
		int expectedRank;
		cin >> expectedRank;

		expectedRankVector.push_back(expectedRank);
	}

	sort(expectedRankVector.begin(), expectedRankVector.end());

	long long answer = 0;
	for (int i = 1; i <= N; i++) {
		answer += abs(i - expectedRankVector[i - 1]);
	}

	cout << answer << '\n';
}