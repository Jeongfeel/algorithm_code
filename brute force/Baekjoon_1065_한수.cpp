//Baekjoon #1065
//algorithm : brute force

#include <iostream>
#include <string>
using namespace std;

int main() {
	int answer = 0;

	int number;
	cin >> number;

	for (int i = 1; i <= number; i++) {
		string s_num = to_string(i);
		if (s_num.length() == 1 || s_num.length() == 2)
			answer += 1;
		else {
			if (s_num[0] - s_num[1] == s_num[1] - s_num[2])
				answer += 1;
		}
	}

	cout << answer << endl;
}