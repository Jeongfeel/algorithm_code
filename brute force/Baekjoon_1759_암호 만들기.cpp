/*
	problem site	:	baekjoon
	problem number	:	1759
	problem name	:	암호 만들기
	algorithm	:	brute force
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void checkPossiblePassword(int count, int currentIndex, string currentPassword);
bool isAbleCurrentPassword(string currentPassword);

vector<string> possiblePasswordVector;

int L, C;
vector<char> alphabetVector;
int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char alphabet;
		cin >> alphabet;

		alphabetVector.push_back(alphabet);
	}

	sort(alphabetVector.begin(), alphabetVector.end());
	checkPossiblePassword(0, 0, "");

	for (int i = 0; i < possiblePasswordVector.size(); i++) {
		cout << possiblePasswordVector[i] << '\n';
	}
}

void checkPossiblePassword(int count, int currentIndex, string currentPassword) {
	if (count == L) {
		if (isAbleCurrentPassword(currentPassword) == true) {
			possiblePasswordVector.push_back(currentPassword);
		}
	}
	else {
		for (int i = currentIndex; i < C; i++) {
			string nextPassword = currentPassword + alphabetVector[i];
			checkPossiblePassword(count + 1, i + 1, nextPassword);
		}
	}
}

bool isAbleCurrentPassword(string currentPassword) {
	int countOfConsonant = 0;
	int countOfVowel = 0;

	for (int i = 0; i < currentPassword.length(); i++) {
		if (currentPassword[i] == 'a' || currentPassword[i] == 'e' || currentPassword[i] == 'i' || currentPassword[i] == 'o' || currentPassword[i] == 'u') {
			countOfVowel += 1;
		}
		else {
			countOfConsonant += 1;
		}
	}

	if (countOfConsonant >= 2 && countOfVowel >= 1) {
		return true;
	}

	return false;
}