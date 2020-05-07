/*
	problem site	:	baekjoon
	problem number	:	1075
	problem name	:	나누기
	algorithm	:	math
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string originalNumber; 
	int divNumber;
	cin >> originalNumber >> divNumber;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			string replaceNumber = to_string(i) + to_string(j);

			originalNumber.replace(originalNumber.length() - 2, 2, replaceNumber);
			if (stoi(originalNumber) % divNumber == 0) {
				cout << replaceNumber << endl;
				return 0;
			}
		}
	}
}