//Baekjoon #2455
//algorithm : simulation

#include <iostream>
using namespace std;

int main() {
	int answer = 0;

	int get_off_people, get_on_people;
	int sum_of_people = 0;

	for (int i = 0; i < 4; i++) {
		cin >> get_off_people >> get_on_people;

		sum_of_people -= get_off_people;
		sum_of_people += get_on_people;

		if (answer < sum_of_people)
			answer = sum_of_people;
	}

	cout << answer << endl;
}