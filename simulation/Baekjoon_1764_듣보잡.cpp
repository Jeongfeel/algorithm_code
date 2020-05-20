/*
	problem site	:	baekjoon
	problem number	:	1764
	problem name	:	듣보잡
	algorithm	:	simulation
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	map<string, bool> notListen;
	map<string, bool> notSee;

	for (int i = 0; i < N; i++) {
		string notListenName;
		cin >> notListenName;

		notListen[notListenName] = true;
	}

	for (int i = 0; i < M; i++) {
		string notSeeName;
		cin >> notSeeName;

		notSee[notSeeName] = true;
	}

	vector<string> notListenAndSee;

	for (auto &notListenName : notListen) {
		if (notSee[notListenName.first] == true) {
			notListenAndSee.push_back(notListenName.first);
		}
	}

	cout << notListenAndSee.size() << '\n';
	for (int i = 0; i < notListenAndSee.size(); i++) {
		cout << notListenAndSee[i] << '\n';
	}
}