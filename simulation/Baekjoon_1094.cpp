//Baekjoon #1094
//algorithm : simulation

#include <iostream>
using namespace std;

int main() {
	int answer = 0;

	int stick = 64, sum_of_stick = 0;

	int number;
	cin >> number;

	while (sum_of_stick != number) {
		if (sum_of_stick + stick > number)
			stick /= 2;
		else {
			sum_of_stick += stick;
			answer += 1;
		}
	}

	cout << answer << endl;
}