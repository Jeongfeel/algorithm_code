//Baekjoon #1629
//algorithm : math

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	
	stack<int> binaryNumber;
	while (B) {
		binaryNumber.push(B % 2);
		B /= 2;
	}

	long long remainder = A % C;
	binaryNumber.pop();
	
	while (!binaryNumber.empty()) {
		int currentBinaryNumber = binaryNumber.top();
		binaryNumber.pop();

		if (currentBinaryNumber == 0) {
			remainder *= remainder;
			remainder %= C;
		}
		else if (currentBinaryNumber == 1) {
			remainder *= remainder;
			remainder %= C;
			remainder *= A;
			remainder %= C;
		}
	}

	cout << remainder << '\n';
}