/*
	problem site	:	baekjoon
	problem number	:	14954
	problem name	:	Happy Number
	algorithm	:	brute force
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int number;
	cin >> number;

	map<int, bool> checkNumberMap;
	checkNumberMap[number] = true;
	while (1) {
		string stringNumber = to_string(number);
		int newNumber = 0;
		
		for (int i = 0; i < stringNumber.size(); i++) {
			newNumber = newNumber + (stringNumber[i] - '0') * (stringNumber[i] - '0');
		}

		if (newNumber == 1) {
			cout << "HAPPY" << '\n';
			break;
		}
		
		if (checkNumberMap[newNumber] == true) {
			cout << "UNHAPPY" << '\n';
			break;
		}

		checkNumberMap[newNumber] = true;
		number = newNumber;
	}
}