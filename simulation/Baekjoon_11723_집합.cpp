/*
	problem site	:	baekjoon
	problem number	:	11723
	problem name	:	집합
	algorithm	:	simulation
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int MAX_NUMBER = 20;
bool setArray[MAX_NUMBER + 1];

void checkOrder(string order);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;

	while (M--) {
		string order;

		cin >> order;
		checkOrder(order);
	}
}

void checkOrder(string order) {
	if (order == "add") {
		int number;
		cin >> number;

		if (setArray[number] == false) {
			setArray[number] = true;
		}
	}
	else if (order == "check") {
		int number;
		cin >> number;
		cout << setArray[number] << '\n';
	}
	else if (order == "remove") {
		int number;
		cin >> number;

		if (setArray[number] == true) {
			setArray[number] = false;
		}
	}
	else if (order == "toggle") {
		int number;
		cin >> number;

		if (setArray[number] == true) {
			setArray[number] = false;
		}
		else {
			setArray[number] = true;
		}
	}
	else if (order == "all") {
		for (int i = 1; i <= 20; i++) {
			setArray[i] = true;
		}
	}
	else if (order == "empty") {
		for (int i = 1; i <= 20; i++) {
			setArray[i] = false;
		}
	}
}