/*
	problem site	:	baekjoon
	problem number	:	1212
	problem name	:	8진수 2진수
	algorithm	:	math
*/

#include <iostream>
#include <string>
using namespace std;

string makeDigitNumber(int number);
string checkHeaderZero(string digitNumber);
int main() {
	string number;
	cin >> number;

	string answer = "";

	if (number == "0") {
		cout << "0" << '\n';
		return 0;
	}

	for (int i = 0; i < number.length(); i++) {
		int digitNumber = number[i] - '0';
		answer += makeDigitNumber(digitNumber);
	}

	answer = checkHeaderZero(answer);

	cout << answer << '\n';
}

string makeDigitNumber(int number) {
	string digitNumber = "";

	int firstNumber = number % 2;
	int secondNumber = number / 2 % 2;
	int thirdNumber = number / 2 / 2;

	digitNumber = to_string(thirdNumber) + to_string(secondNumber) + to_string(firstNumber);

	return digitNumber;
}

string checkHeaderZero(string digitNumber) {
	int index = 0;

	for (int i = 0; i < digitNumber.length(); i++) {
		if (digitNumber[i] == '0') {
			index += 1;
			continue;
		}

		break;
	}

	return digitNumber.substr(index, digitNumber.length());
}