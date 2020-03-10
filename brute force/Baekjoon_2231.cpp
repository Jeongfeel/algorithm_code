//Beakjoon #2231
//algorithm : brute force

#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int result = 0;

	for (int n = 1; n <= 1000000; n++) {
		int a = n / 1000000;
		int b = n % 1000000 / 100000;
		int c = n % 100000 / 10000;
		int d = n % 10000 / 1000;
		int e = n % 1000 / 100;
		int f = n % 100 / 10;
		int g = n % 10;

		if (n + a + b + c + d + e + f + g == num) {
			result = n;
			break;
		}
	}

	cout << result << endl;
}