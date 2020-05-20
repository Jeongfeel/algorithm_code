/*
	problem site	:	baekjoon
	problem number	:	1976
	problem name	:	여행 가자
	algorithm	:	bfs
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NUMBER_OF_CITY = 200;

bool adjacentCity[MAX_NUMBER_OF_CITY + 1][MAX_NUMBER_OF_CITY + 1];
bool isVisitedCity[MAX_NUMBER_OF_CITY];

void printPossibleJourney(vector<int> visitCity);

int N, M;
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adjacentCity[i][j];
		}
	}

	vector<int> visitCity;
	for (int i = 0; i < M; i++) {
		int city;
		cin >> city;

		visitCity.push_back(city);
	}

	printPossibleJourney(visitCity);
}

void printPossibleJourney(vector<int> visitCity) {
	queue<int> moveableCity;
	moveableCity.push(visitCity[0]);

	while (!moveableCity.empty()) {
		int currentCity = moveableCity.front();
		moveableCity.pop();
	
		isVisitedCity[currentCity] = true;

		for (int i = 1; i <= N; i++) {
			if (adjacentCity[currentCity][i] == 0) {
				continue;
			}
			if (isVisitedCity[i] == true) {
				continue;
			}

			moveableCity.push(i);
		}
	}

	for (int i = 0; i < M; i++) {
		if (isVisitedCity[visitCity[i]] == false) {
			cout << "NO" << '\n';
			return;
		}
	}

	cout << "YES" << '\n';
}