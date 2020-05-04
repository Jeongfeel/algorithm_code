/*
	problem site	:	baekjoon
	problem number	:	10799
	problem name	:	쇠막대기
	algorithm	:	simulation
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string ironStick;
	cin >> ironStick;

	int countOfIronStick = 0;
	int countOfSerparteStick = 0;
	
	for (int i = 0; i < ironStick.size(); i++) {
		if (ironStick[i] == '(') {
			countOfIronStick += 1;
		}
		else if (ironStick[i] == ')') {
			countOfIronStick -= 1;
			if (ironStick[i - 1] == '(') {
				countOfSerparteStick += countOfIronStick;
			}
			else {
				countOfSerparteStick += 1;
			}
		}
	}

	cout << countOfSerparteStick << '\n';
}