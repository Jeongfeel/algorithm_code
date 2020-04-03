/*
	problem site	:	baekjoon
	problem number	:	13458
	problem name	:	시험 감독
	algorithm	:	math
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> studentAbooutEachClass;
	for (int i = 0; i < N; i++) {
		int student;
		cin >> student;
		studentAbooutEachClass.push_back(student);
	}

	int B, C;
	cin >> B >> C;

	long long teacher = 0;
	for (int i = 0; i < studentAbooutEachClass.size(); i++) {
		teacher += 1;
		studentAbooutEachClass[i] -= B;
		if (studentAbooutEachClass[i] <= 0) {
			continue;
		}
		if (studentAbooutEachClass[i] % C == 0) {
			teacher += studentAbooutEachClass[i] / C;
		}
		else {
			teacher += studentAbooutEachClass[i] / C + 1;
		}
	}

	cout << teacher << '\n';
}