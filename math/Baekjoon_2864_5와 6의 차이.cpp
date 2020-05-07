/*
	problem site	:	baekjoon
	problem number	:	2864
	problem name	:	5와 6의 차이
	algorithm	:	math
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string number1, number2;
	cin >> number1 >> number2;

	int min, max;
	for (int i = 0; i < number1.length(); i++) {
		if (number1[i] == '5') {
			number1[i] = '6';
		}
	}
	for (int i = 0; i < number2.length(); i++) {
		if (number2[i] == '5') {
			number2[i] = '6';
		}
	}

	max = stoi(number1) + stoi(number2);

	for (int i = 0; i < number1.length(); i++) {
		if (number1[i] == '6') {
			number1[i] = '5';
		}
	}
	for (int i = 0; i < number2.length(); i++) {
		if (number2[i] == '6') {
			number2[i] = '5';
		}
	}

	min = stoi(number1) + stoi(number2);

	cout << min << " " << max << '\n';
}