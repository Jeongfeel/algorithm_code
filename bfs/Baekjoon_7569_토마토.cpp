//baekjoon #7569
//algorithm : bfs

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX_NUMBER = 100;

int tomatoBox[MAX_NUMBER][MAX_NUMBER][MAX_NUMBER]; //높이, 세로, 가로

int x[] = { 1, -1, 0, 0, 0, 0 };
int y[] = { 0, 0, 1, -1, 0, 0 };
int z[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	int M, N, H;
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomatoBox[i][j][k];
			}
		}
	}
	
	queue<tuple<int, int, int>> ripenTomatoPlaceQueue;

	int allTomatoCount = M * N * H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomatoBox[i][j][k] == 1) {
					tuple<int, int, int> ripenTomatoPlace = make_tuple(i, j, k);
					ripenTomatoPlaceQueue.push(ripenTomatoPlace);
				}
				else if (tomatoBox[i][j][k] == -1) {
					allTomatoCount -= 1;
				}
			}
		}
	}

	int numberOfTomatoByDate = ripenTomatoPlaceQueue.size();
	int dateUntilAllTomamtRipe = -1;
	int ripenTomatoCount = 0;

	while (!ripenTomatoPlaceQueue.empty()) {
		tuple<int, int, int> currentRipenTomatoPlace = ripenTomatoPlaceQueue.front();
		ripenTomatoPlaceQueue.pop();

		ripenTomatoCount += 1;

		int currentDepth = get<0>(currentRipenTomatoPlace);
		int currentHeight = get<1>(currentRipenTomatoPlace);
		int currentWidth = get<2>(currentRipenTomatoPlace);

		for (int i = 0; i < 6; i++) {
			int nextDepth = currentDepth + z[i];
			int nextHeight = currentHeight + y[i];
			int nextWidth = currentWidth + x[i];

			if (nextDepth < 0 || nextDepth == H || nextHeight < 0 || nextHeight == N || nextWidth < 0 || nextWidth == M) {
				continue;
			}

			if (tomatoBox[nextDepth][nextHeight][nextWidth] == 0) {
				tomatoBox[nextDepth][nextHeight][nextWidth] = 1;
				tuple<int, int, int> newRipenTomatoPlace = make_tuple(nextDepth, nextHeight, nextWidth);
				ripenTomatoPlaceQueue.push(newRipenTomatoPlace);
			}
		}

		numberOfTomatoByDate -= 1;
		if (numberOfTomatoByDate == 0) {
			numberOfTomatoByDate = ripenTomatoPlaceQueue.size();
			dateUntilAllTomamtRipe += 1;
		}
	}

	if (allTomatoCount == ripenTomatoCount) {
		cout << dateUntilAllTomamtRipe << '\n';
	}
	else {
		cout << "-1" << '\n';
	}
}