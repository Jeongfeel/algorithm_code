//baekjoon #9095
//algorithm : dynamic programming

#include <iostream>
using namespace std;

int countNumberToMake123(int number);

int main() {
	int TestCase;
	cin >> TestCase;

	while (TestCase--) {
		int number;
		cin >> number;

		cout << countNumberToMake123(number) << endl;
	}
}

int countNumberToMake123(int number) {
	if (number < 0) {
		return 0;
	}

	if (number == 0) {
		return 1;
	}

	return countNumberToMake123(number - 1) + countNumberToMake123(number - 2) + countNumberToMake123(number - 3);;
}