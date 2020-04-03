/*
	problem site	:	baekjoon
	problem number	:	1707
	problem name	:	이분 그래프
	algorithm		:	dfs
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NODE_NUMBER = 20000 + 1;

vector<int> adjacentNodeArray[MAX_NODE_NUMBER];

bool firstAdjacentNode[MAX_NODE_NUMBER];
bool secondAdjacentNode[MAX_NODE_NUMBER];
bool isVisitedNode[MAX_NODE_NUMBER];

void initAdjacentArray();
void pushStartNodeOfGraph(int numberOfNode, queue<int> &firstAdjacentNodeQueue);
void createSingleGraph(queue<int> &adjacentNodeNumberQueue);

int testCase;
int V, E;

int main() {
	cin >> testCase;

	while (testCase--) {
		cin >> V >> E;

		initAdjacentArray();

		for (int i = 0; i < E; i++) {
			int firstNode, secondNode;
			cin >> firstNode >> secondNode;

			adjacentNodeArray[firstNode].push_back(secondNode);
			adjacentNodeArray[secondNode].push_back(firstNode);
		}

		queue<int> firstAdjacentNodeQueue;
		queue<int> secondAdjacentNodeQueue;

		pushStartNodeOfGraph(V, firstAdjacentNodeQueue);

		while (!firstAdjacentNodeQueue.empty() || !secondAdjacentNodeQueue.empty()) {
			while (!firstAdjacentNodeQueue.empty()) {
				int currentNode = firstAdjacentNodeQueue.front();
				firstAdjacentNodeQueue.pop();

				firstAdjacentNode[currentNode] = 1;

				for (int i = 0; i < adjacentNodeArray[currentNode].size(); i++) {
					if (secondAdjacentNode[adjacentNodeArray[currentNode][i]] == 1) {
						continue;
					}

					secondAdjacentNode[adjacentNodeArray[currentNode][i]] = 1;
					secondAdjacentNodeQueue.push(adjacentNodeArray[currentNode][i]);
				}
			}

			while (!secondAdjacentNodeQueue.empty()) {
				int currentNode = secondAdjacentNodeQueue.front();
				secondAdjacentNodeQueue.pop();

				secondAdjacentNode[currentNode] = 1;

				for (int i = 0; i < adjacentNodeArray[currentNode].size(); i++) {
					if (firstAdjacentNode[adjacentNodeArray[currentNode][i]] == 1) {
						continue;
					}

					firstAdjacentNode[adjacentNodeArray[currentNode][i]] = 1;
					firstAdjacentNodeQueue.push(adjacentNodeArray[currentNode][i]);
				}
			}
		}

		bool isImpossibleBipartitegraph = false;

		for (int i = 1; i <= V; i++) {
			if (firstAdjacentNode[i] == secondAdjacentNode[i]) {
				isImpossibleBipartitegraph = true;
			}
		}

		if (isImpossibleBipartitegraph == true) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
}

void initAdjacentArray() {
	for (int i = 1; i <= V; i++) {
		adjacentNodeArray[i].erase(adjacentNodeArray[i].begin(), adjacentNodeArray[i].end());

		firstAdjacentNode[i] = 0;
		secondAdjacentNode[i] = 0;
		isVisitedNode[i] = false;
	}
}

void pushStartNodeOfGraph(int numberOfNode, queue<int> &firstAdjacentNodeQueue) {
	for (int i = 1; i <= numberOfNode; i++) {
		if (isVisitedNode[i] == true) {
			continue;
		}

		firstAdjacentNodeQueue.push(i);

		queue<int> adjacentNodeNumberQueue;
		adjacentNodeNumberQueue.push(i);
		createSingleGraph(adjacentNodeNumberQueue);
	}
}

void createSingleGraph(queue<int> &adjacentNodeNumberQueue) {
	while (!adjacentNodeNumberQueue.empty()) {
		int currentNodeNumber = adjacentNodeNumberQueue.front();
		adjacentNodeNumberQueue.pop();

		isVisitedNode[currentNodeNumber] = true;

		for (int i = 0; i < adjacentNodeArray[currentNodeNumber].size(); i++) {
			int nextNodeNumber = adjacentNodeArray[currentNodeNumber][i];

			if (isVisitedNode[nextNodeNumber] == true) {
				continue;
			}

			adjacentNodeNumberQueue.push(nextNodeNumber);
		}
	}
}