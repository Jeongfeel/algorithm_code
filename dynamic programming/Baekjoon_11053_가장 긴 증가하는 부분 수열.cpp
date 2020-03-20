//Baekjoon #11053
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000 + 1;

int sequenceArray[MAX_NUMBER];
int lengthOfPartialSequenceByIndex[MAX_NUMBER];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> sequenceArray[i];
	}

	for (int i = N; i > 0; i--) {
		int currentNumber = sequenceArray[i];

		int theMostLongestSequence = 0;
		for (int j = i + 1; j <= N; j++) {
			if (currentNumber >= sequenceArray[j]) {
				continue;
			}

			if (theMostLongestSequence < lengthOfPartialSequenceByIndex[j]) {
				theMostLongestSequence = lengthOfPartialSequenceByIndex[j];
			}
		}

		theMostLongestSequence += 1;
		lengthOfPartialSequenceByIndex[i] = theMostLongestSequence;
	}

	int theMostLongestSequence = 0;
	for (int i = 1; i <= N; i++) {
		if (theMostLongestSequence < lengthOfPartialSequenceByIndex[i]) {
			theMostLongestSequence = lengthOfPartialSequenceByIndex[i];
		}
	}

	cout << theMostLongestSequence << '\n';
}