//Baekjoon #2839
//algorithm : math

#include <iostream>
using namespace std;

int main() {
	int answer = 0;

	int number;
	cin >> number;

	if (number == 4 || number == 7)
		answer = -1;
	else {
		answer = number / 5;

		if (number % 5 == 1)
			answer += 1;
		else if (number % 5 == 2)
			answer += 2;
		else if (number % 5 == 3)
			answer += 1;
		else if (number % 5 == 4)
			answer += 2;
	}

	cout << answer << endl;
}