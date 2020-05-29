/*
	problem site	:	baekjoon
	problem number	:	14889
	problem name	:	스타트와 링크
	algorithm	:	brute force
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NUMBER = 20;

int ability[MAX_NUMBER][MAX_NUMBER];
int abilityOfSecondTeam[MAX_NUMBER][MAX_NUMBER];

void checkMinimumAbility(int startIndex, int currentCount, vector<int> memberIndex);
void checkSumOfTeamMemberAbility(vector<int> memberIndex);
void initAbilityOfSecondTeam(vector<int> memberIndex);

int minimumAbilityDifference = 1024 * 1024 * 1024 * 2 - 1;

int N;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ability[i][j];
		}
	}

	vector<int> memberIndex;
	checkMinimumAbility(0, 0, memberIndex);

	cout << minimumAbilityDifference << '\n';
}

void checkMinimumAbility(int startIndex, int currentCount, vector<int> memberIndex) {
	if (currentCount == N / 2) {
		checkSumOfTeamMemberAbility(memberIndex);
	}
	else {
		for (int i = startIndex; i < N; i++) {
			vector<int> newMemberIndex = memberIndex;
			newMemberIndex.push_back(i);
			checkMinimumAbility(i + 1, currentCount + 1, newMemberIndex);
		}
	}
}

void checkSumOfTeamMemberAbility(vector<int> memberIndex) {
	int firstTeamAbilitiy = 0;
	vector<int> permutationVector;
	for (int i = 0; i < memberIndex.size() - 2; i++) {
		permutationVector.push_back(0);
	}
	for (int i = 0; i < 2; i++) {
		permutationVector.push_back(1);
	}
	do {
		vector<int> friendIndex;
		for (int i = 0; i < permutationVector.size(); i++) {
			if (permutationVector[i] == 1) {
				friendIndex.push_back(memberIndex[i]);
			}
		}

		firstTeamAbilitiy += ability[friendIndex[0]][friendIndex[1]];
		firstTeamAbilitiy += ability[friendIndex[1]][friendIndex[0]];
	} while (next_permutation(permutationVector.begin(), permutationVector.end()));

	initAbilityOfSecondTeam(memberIndex);

	int secondTeamAbility = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (abilityOfSecondTeam[i][j] == -1) {
				continue;
			}
			
			secondTeamAbility += abilityOfSecondTeam[i][j];
		}
	}

	int teamDifference = abs(firstTeamAbilitiy - secondTeamAbility);
	if (minimumAbilityDifference > teamDifference) {
		minimumAbilityDifference = teamDifference;
	}
}

void initAbilityOfSecondTeam(vector<int> memberIndex) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			abilityOfSecondTeam[i][j] = ability[i][j];
		}
	}

	for (int i = 0; i < memberIndex.size(); i++) {
		int currentMemberIndex = memberIndex[i];

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (j == currentMemberIndex || k == currentMemberIndex) {
					abilityOfSecondTeam[j][k] = 0;
					abilityOfSecondTeam[k][j] = 0;
					continue;
				}
			}
		}
	}
}