/*
	problem site	:	baekjoon
	problem number	:	13023
	problem name	:	ABCDE
	algorithm	:	dfs
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUMBER = 2000;

vector<int> friendList[MAX_NUMBER];
bool isVisitedFriend[MAX_NUMBER];
bool isMakeableFriendList;
void checkFriendList(int index, int count);

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int first, second;
		cin >> first >> second;

		friendList[first].push_back(second);
		friendList[second].push_back(first);
	}

	for (int i = 0; i < N; i++) {
		checkFriendList(i, 1);
	}

	cout << isMakeableFriendList << '\n';
}

void checkFriendList(int index, int count) {
	if (isMakeableFriendList == true || count == 5) {
		isMakeableFriendList = true;
		return;
	}
	isVisitedFriend[index] = true;

	for (int i = 0; i < friendList[index].size(); i++) {
		if (isVisitedFriend[friendList[index][i]] == false) {
			checkFriendList(friendList[index][i], count + 1);
		}
	}

	isVisitedFriend[index] = false;
}