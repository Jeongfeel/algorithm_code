//Baekjoon #2851
//algorithm : simulation

#include <iostream>
using namespace std;

int mushroom[10];

int main() {
	int score = 0;

	for (int i = 0; i < 10; i++) {
		cin >> mushroom[i];
	}

	for (int i = 0; i < 10; i++) {
		score += mushroom[i];

		if (score >= 100) {
			if (abs(100 - (score - mushroom[i])) < abs(100-score)) {
				score -= mushroom[i];
			}

			break;
		}
	}

	cout << score << endl;
}