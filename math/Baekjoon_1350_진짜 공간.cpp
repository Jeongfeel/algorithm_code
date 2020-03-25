/*
	problem site	:	baekjoon
	problem number	:	1350
	problem name	:	진짜 공간
	algorithm	:	math
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> sizeOfFileVector;

	while (N--) {
		int sizeOfFile;
		cin >> sizeOfFile;

		sizeOfFileVector.push_back(sizeOfFile);
	}

	int sizeOfCluster;
	cin >> sizeOfCluster;

	long long countOfNecessaryCluster = 0;
	for (int i = 0; i < sizeOfFileVector.size(); i++) {
		if (sizeOfFileVector[i] % sizeOfCluster != 0) {
			int necessaryCluster = sizeOfFileVector[i] / sizeOfCluster + 1;
			countOfNecessaryCluster += necessaryCluster;
		}
		else if (sizeOfFileVector[i] % sizeOfCluster == 0) {
			int necessaryCluster = sizeOfFileVector[i] / sizeOfCluster;
			countOfNecessaryCluster += necessaryCluster;
		}
	}

	long long necessaryDiskSpace = sizeOfCluster * countOfNecessaryCluster;
	cout << necessaryDiskSpace << '\n';
}