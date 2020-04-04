/*
	problem site	:	baekjoon
	problem number	:	9466
	problem name	:	텀 프로젝트
	algorithm	:	dfs
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUMBER_OF_STUDENT = 100000;
const int UNDETERMINED = 0;
const int HAVE_NO_TEAM = 1;
const int HAVE_TEAM = 2;

int student[MAX_NUMBER_OF_STUDENT + 1];
int stateOfStudent[MAX_NUMBER_OF_STUDENT + 1];
bool isCheckedStudent[MAX_NUMBER_OF_STUDENT + 1];

void initStateOfStudent();
void checkStateOfStudent(int currentStudentNumber);
void printCountOfNoTeamStudent(int numberOfStudent);

int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		initStateOfStudent();

		int numberOfStudent;
		cin >> numberOfStudent;

		for (int i = 1; i <= numberOfStudent; i++) {
			cin >> student[i];
		}

		for (int i = 1; i <= numberOfStudent; i++) {
			if (stateOfStudent[i] == UNDETERMINED) {
				checkStateOfStudent(i);
			}
		}

		printCountOfNoTeamStudent(numberOfStudent);
	}
}

void initStateOfStudent() {
	for (int i = 1; i <= MAX_NUMBER_OF_STUDENT; i++) {
		stateOfStudent[i] = UNDETERMINED;
		isCheckedStudent[i] = false;
	}
}

void checkStateOfStudent(int currentStudentNumber) {
	int nextStudentNumber = student[currentStudentNumber];

	if (stateOfStudent[currentStudentNumber] == UNDETERMINED && isCheckedStudent[nextStudentNumber] == false) {
		stateOfStudent[currentStudentNumber] = HAVE_NO_TEAM;
		checkStateOfStudent(nextStudentNumber);
	}
	else if (stateOfStudent[currentStudentNumber] == HAVE_NO_TEAM && isCheckedStudent[nextStudentNumber] == false) {
		stateOfStudent[currentStudentNumber] = HAVE_TEAM;
		checkStateOfStudent(nextStudentNumber);
	}

	isCheckedStudent[currentStudentNumber] = true;
}

void printCountOfNoTeamStudent(int numberOfStudent) {
	int currentNoTeamStudent = 0;
	for (int i = 1; i <= numberOfStudent; i++) {
		if (stateOfStudent[i] == HAVE_TEAM) {
			continue;
		}

		currentNoTeamStudent += 1;
	}

	cout << currentNoTeamStudent << '\n';
}