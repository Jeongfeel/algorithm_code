//Baekjoon #1463
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 1000000 + 1;
int minimumCountToMakeOne[MAX_NUMBER];

void initMinimumCountToMakeOne(int number);
int getMinimumCountToMakeOne(int first, int second, int third);

int main() {
	int number;
	cin >> number;

	initMinimumCountToMakeOne(number);
	
	for (int i = 4; i < number + 1; i++) {
		int first, second, third;
		if (i % 3 == 0)
			first = i / 3;
		else
			first = 0;
		if (i % 2 == 0)
			second = i / 2;
		else
			second = 0;
		third = i - 1;
		minimumCountToMakeOne[i] = getMinimumCountToMakeOne(minimumCountToMakeOne[first], minimumCountToMakeOne[second], minimumCountToMakeOne[third]) + 1;
	}

	cout << minimumCountToMakeOne[number] << endl;
}

void initMinimumCountToMakeOne(int number) {
	minimumCountToMakeOne[0] = MAX_NUMBER;
	minimumCountToMakeOne[1] = 0;
	minimumCountToMakeOne[2] = 1;
	minimumCountToMakeOne[3] = 1;
}

int getMinimumCountToMakeOne(int first, int second, int third) {
	if (first < second&&first < third) {
		return first;
	}
	else if (second < third) {
		return second;
	}
	else {
		return third;
	}
}