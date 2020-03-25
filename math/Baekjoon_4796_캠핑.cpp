/*
	problem site	:	baekjoon
	problem number	:	4796
	problem name	:	д╥гн
	algorithm		:	math
*/

#include <iostream>
using namespace std;

int main() {
	int numberOfCase = 0;

	while (1) {
		int usableDay, continuousDay, holiday;
		cin >> usableDay >> continuousDay >> holiday;

		if (usableDay == 0 && continuousDay == 0 && holiday == 0) {
			break;
		}

		numberOfCase += 1;

		int maximumUseableDay = usableDay * (holiday / continuousDay);

		if (holiday % continuousDay > usableDay) {
			maximumUseableDay += usableDay;
		}
		else {
			maximumUseableDay += holiday % continuousDay;
		}

		cout << "Case " << numberOfCase << ": " << maximumUseableDay << '\n';
	}
}