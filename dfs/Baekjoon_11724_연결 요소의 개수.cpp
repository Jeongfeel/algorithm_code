/*
	problem site	:	baekjoon
	problem number	:	11724
	problem name	:	연결 요소의 개수
	algorithm	:	dfs
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUMBER_OF_NODE = 1000;

vector<int>	adjacentNode[MAX_NUMBER_OF_NODE + 1];
bool isVisitedNode[MAX_NUMBER_OF_NODE + 1];

void checkLinkedNode(int currentIndex);

int N, M;
int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int firstNode, secondNode;
		cin >> firstNode >> secondNode;

		adjacentNode[firstNode].push_back(secondNode);
		adjacentNode[secondNode].push_back(firstNode);
	}

	int countOfLinkedNode = 0;

	for (int i = 1; i <= N; i++) {
		if (isVisitedNode[i] == false) {
			countOfLinkedNode += 1;
			checkLinkedNode(i);
		}
	}

	cout << countOfLinkedNode << '\n';
}

void checkLinkedNode(int currentIndex) {
	isVisitedNode[currentIndex] = true;

	for (int i = 0; i < adjacentNode[currentIndex].size(); i++) {
		if (isVisitedNode[adjacentNode[currentIndex][i]] == false) {
			checkLinkedNode(adjacentNode[currentIndex][i]);
		}
	}
}