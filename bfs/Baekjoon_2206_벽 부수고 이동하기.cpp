//Baekjoon #2206
//algorithm : bfs

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_NUMBER = 1000 + 1;
const int MAX_NUMBER_OF_INT = 1024 * 1024 * 1024 * 2 - 1;

char map[MAX_NUMBER][MAX_NUMBER];
int countOfCourseNoBreakWall[MAX_NUMBER][MAX_NUMBER];
int countOfCourseBreakWall[MAX_NUMBER][MAX_NUMBER];

int moveXCoordinate[] = { 1,-1,0,0 };
int moveYCoordinate[] = { 0,0,1,-1 };

void checkNotBrokenWallCase(queue <pair<pair<int, int>, int>> &notBreakWallCoordinateAndCountOfCourseQueue, queue <pair<pair<int, int>, int>> &breakWallCoordinateAndCountOfCourseQueue);
void checkBrokenWallCase(queue <pair<pair<int, int>, int>> &breakWallCoordinateAndCountOfCourseQueue);
void printShortestPath();

int N, M;
int main() {
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	
	queue <pair<pair<int, int>, int>> notBreakWallCoordinateAndCountOfCourseQueue;
	queue <pair<pair<int, int>, int>> breakWallCoordinateAndCountOfCourseQueue;

	pair<int, int> currentCoordinate = make_pair(0, 1);
	int countOfCourse = 0;

	pair<pair<int, int>, int> coordinateAndcountOfCourse = make_pair(currentCoordinate, countOfCourse);
	notBreakWallCoordinateAndCountOfCourseQueue.push(coordinateAndcountOfCourse);

	checkNotBrokenWallCase(notBreakWallCoordinateAndCountOfCourseQueue, breakWallCoordinateAndCountOfCourseQueue);
	checkBrokenWallCase(breakWallCoordinateAndCountOfCourseQueue);

	printShortestPath();
}

void checkNotBrokenWallCase(queue <pair<pair<int, int>, int>> &notBreakWallCoordinateAndCountOfCourseQueue, queue <pair<pair<int, int>, int>> &breakWallCoordinateAndCountOfCourseQueue) {
	while (!notBreakWallCoordinateAndCountOfCourseQueue.empty()) {
		pair<pair<int, int>, int> currentCoordinateAndCountOfCourse = notBreakWallCoordinateAndCountOfCourseQueue.front();
		notBreakWallCoordinateAndCountOfCourseQueue.pop();

		int currentXCoordinate = currentCoordinateAndCountOfCourse.first.first;
		int currentYCoordinate = currentCoordinateAndCountOfCourse.first.second;
		int currentCountOfCourse = currentCoordinateAndCountOfCourse.second;

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 1 || nextXCoordinate > N || nextYCoordinate<1 || nextYCoordinate>M) {
				continue;
			}

			if (map[nextXCoordinate][nextYCoordinate] == '0') {
				if (countOfCourseNoBreakWall[nextXCoordinate][nextYCoordinate] == 0) {
					countOfCourseNoBreakWall[nextXCoordinate][nextYCoordinate] = currentCountOfCourse + 1;

					pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
					int nextCountOfCourse = currentCountOfCourse + 1;
					pair<pair<int, int>, int> nextCoordinateAndCountOfCourse = make_pair(nextCoordinate, nextCountOfCourse);
					notBreakWallCoordinateAndCountOfCourseQueue.push(nextCoordinateAndCountOfCourse);
				}
				else if (countOfCourseNoBreakWall[nextXCoordinate][nextYCoordinate] > currentCountOfCourse + 1) {
					countOfCourseNoBreakWall[nextXCoordinate][nextYCoordinate] = currentCountOfCourse + 1;

					pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
					int nextCountOfCourse = currentCountOfCourse + 1;
					pair<pair<int, int>, int> nextCoordinateAndCountOfCourse = make_pair(nextCoordinate, nextCountOfCourse);
					notBreakWallCoordinateAndCountOfCourseQueue.push(nextCoordinateAndCountOfCourse);
				}
			}
			else if (map[nextXCoordinate][nextYCoordinate] == '1') {
				countOfCourseBreakWall[nextXCoordinate][nextYCoordinate] = currentCountOfCourse + 1;

				pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
				int nextCountOfCourse = currentCountOfCourse + 1;
				pair<pair<int, int>, int> nextCoordinateAndCountOfCourse = make_pair(nextCoordinate, nextCountOfCourse);
				breakWallCoordinateAndCountOfCourseQueue.push(nextCoordinateAndCountOfCourse);
			}
		}
	}
}

void checkBrokenWallCase(queue <pair<pair<int, int>, int>> &breakWallCoordinateAndCountOfCourseQueue) {
	while (!breakWallCoordinateAndCountOfCourseQueue.empty()) {
		pair<pair<int, int>, int> currentCoordinateAndCountOfCourse = breakWallCoordinateAndCountOfCourseQueue.front();
		breakWallCoordinateAndCountOfCourseQueue.pop();

		int currentXCoordinate = currentCoordinateAndCountOfCourse.first.first;
		int currentYCoordinate = currentCoordinateAndCountOfCourse.first.second;
		int currentCountOfCourse = currentCoordinateAndCountOfCourse.second;

		for (int i = 0; i < 4; i++) {
			int nextXCoordinate = currentXCoordinate + moveXCoordinate[i];
			int nextYCoordinate = currentYCoordinate + moveYCoordinate[i];

			if (nextXCoordinate < 1 || nextXCoordinate > N || nextYCoordinate<1 || nextYCoordinate>M) {
				continue;
			}

			if (map[nextXCoordinate][nextYCoordinate] == '1') {
				continue;
			}

			if (countOfCourseBreakWall[nextXCoordinate][nextYCoordinate] == 0) {
				countOfCourseBreakWall[nextXCoordinate][nextYCoordinate] = currentCountOfCourse + 1;

				pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
				int nextCountOfCourse = currentCountOfCourse + 1;
				pair<pair<int, int>, int> nextCoordinateAndCountOfCourse = make_pair(nextCoordinate, nextCountOfCourse);
				breakWallCoordinateAndCountOfCourseQueue.push(nextCoordinateAndCountOfCourse);
			}
			else if (countOfCourseBreakWall[nextXCoordinate][nextYCoordinate] > currentCountOfCourse + 1) {
				countOfCourseBreakWall[nextXCoordinate][nextYCoordinate] = currentCountOfCourse + 1;

				pair<int, int> nextCoordinate = make_pair(nextXCoordinate, nextYCoordinate);
				int nextCountOfCourse = currentCountOfCourse + 1;
				pair<pair<int, int>, int> nextCoordinateAndCountOfCourse = make_pair(nextCoordinate, nextCountOfCourse);
				breakWallCoordinateAndCountOfCourseQueue.push(nextCoordinateAndCountOfCourse);
			}
		}
	}
}

void printShortestPath() {
	if (countOfCourseBreakWall[N][M] == 0) {
		countOfCourseBreakWall[N][M] = MAX_NUMBER_OF_INT;
	}
	if (countOfCourseNoBreakWall[N][M] == 0) {
		countOfCourseNoBreakWall[N][M] = MAX_NUMBER_OF_INT;
	}

	if (countOfCourseNoBreakWall[N][M] == MAX_NUMBER_OF_INT && countOfCourseBreakWall[N][M] == MAX_NUMBER_OF_INT) {
		cout << "-1" << '\n';
	}
	else if (countOfCourseNoBreakWall[N][M] < countOfCourseBreakWall[N][M]) {
		cout << countOfCourseNoBreakWall[N][M] << '\n';
	}
	else {
		cout << countOfCourseBreakWall[N][M] << '\n';
	}
}