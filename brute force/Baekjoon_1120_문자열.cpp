/*
	problem site	:	baekjoon
	problem number	:	1120
	problem name	:	문자열
	algorithm	:	brute force
*/

#include <iostream>
#include <string>
using namespace std;

int minimumDifference = 1024 * 1024 * 1024 * 2 - 1;

void findMinimumDifference(string A, string B);

int main() {
	string A, B;
	cin >> A >> B;

	findMinimumDifference(A, B);

	cout << minimumDifference << '\n';
}

void findMinimumDifference(string A, string B) {
	for (int indexOfB = 0; indexOfB < B.length() - A.length() + 1; indexOfB++) {
		int currentDifference = 0;
		
		for (int indexOfA = 0; indexOfA < A.length(); indexOfA++) {
			if (A[indexOfA] == B[indexOfB + indexOfA]) {
				continue;
			}

			currentDifference += 1;
		}

		if (currentDifference < minimumDifference) {
			minimumDifference = currentDifference;
		}
	}
}