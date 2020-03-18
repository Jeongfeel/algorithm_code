//Baekjoon #13460
//algorithm : brute force

#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

const int MAX_NUMBER = 10;
const int MAX_MOVE_NUMBER = 10;
char squareBoard[MAX_NUMBER][MAX_NUMBER];

queue<tuple<pair<int, int>, pair<int, int>, int>> coordinateOfBeadAndMoveCount; //red bead, blue bead, move count
bool isSucceedGame;

void leanSquareBoadToLeft(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount);
void leanSquareBoadToRight(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount);
void leanSquareBoadToUp(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount);
void leanSquareBoadToDown(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount);

int N, M;
int main() {
	cin >> N >> M;

	pair<int, int> coordinateOfRedBead;
	pair<int, int> coordinateOfBlueBead;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> squareBoard[i][j];

			if (squareBoard[i][j] == 'R') {
				coordinateOfRedBead.first = i;
				coordinateOfRedBead.second = j;
				squareBoard[i][j] = '.';
			} else if (squareBoard[i][j] == 'B') {
				coordinateOfBlueBead.first = i;
				coordinateOfBlueBead.second = j;
				squareBoard[i][j] = '.';
			}
		}
	}
	
	int numberOfMoveCount = -1;

	coordinateOfBeadAndMoveCount.push(make_tuple(coordinateOfRedBead, coordinateOfBlueBead, 0));
	while (!coordinateOfBeadAndMoveCount.empty()) {
		tuple<pair<int, int>, pair<int, int>, int> currentCoordinateOfBeadAndCount = coordinateOfBeadAndMoveCount.front();
		
		pair<int, int> coordinateOfRedBead = get<0>(currentCoordinateOfBeadAndCount);
		pair<int, int> coordinateOfBlueBead = get<1>(currentCoordinateOfBeadAndCount);
		int currentMoveCount = get<2>(currentCoordinateOfBeadAndCount);

		coordinateOfBeadAndMoveCount.pop();
		
		leanSquareBoadToLeft(coordinateOfRedBead, coordinateOfBlueBead, currentMoveCount);
		leanSquareBoadToRight(coordinateOfRedBead, coordinateOfBlueBead, currentMoveCount);
		leanSquareBoadToUp(coordinateOfRedBead, coordinateOfBlueBead, currentMoveCount);
		leanSquareBoadToDown(coordinateOfRedBead, coordinateOfBlueBead, currentMoveCount);

		if (isSucceedGame == true) {
			numberOfMoveCount = currentMoveCount + 1;
			break;
		}
	}

	cout << numberOfMoveCount << '\n';
}

void leanSquareBoadToLeft(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount) {
	int xCoordinateOfRedBead = coordinateOfRedBead.first;
	int yCoordinateOfRedBead = coordinateOfRedBead.second;
	int xCoordinateOfBlueBead = coordinateOfBlueBead.first;
	int yCoordinateOfBlueBead = coordinateOfBlueBead.second;

	currentMoveCount += 1;

	bool isRedBeadArrivedAtHole = false;
	bool isBlueBeadArrivedAtHole = false;

	while (squareBoard[xCoordinateOfRedBead][--yCoordinateOfRedBead] != '#') {
		if (squareBoard[xCoordinateOfRedBead][yCoordinateOfRedBead] == 'O') {
			isRedBeadArrivedAtHole = true;
		}
	}
	while (squareBoard[xCoordinateOfBlueBead][--yCoordinateOfBlueBead] != '#') {
		if (squareBoard[xCoordinateOfBlueBead][yCoordinateOfBlueBead] == 'O') {
			isBlueBeadArrivedAtHole = true;
		}
	}

	yCoordinateOfRedBead += 1;
	yCoordinateOfBlueBead += 1;

	if (xCoordinateOfRedBead == xCoordinateOfBlueBead && yCoordinateOfRedBead == yCoordinateOfBlueBead) {
		if (coordinateOfRedBead.second > coordinateOfBlueBead.second) {
			yCoordinateOfRedBead += 1;
		}
		else if (coordinateOfRedBead.second < coordinateOfBlueBead.second) {
			yCoordinateOfBlueBead += 1;
		}
	}

	if (xCoordinateOfRedBead == coordinateOfRedBead.first && yCoordinateOfRedBead == coordinateOfRedBead.second && xCoordinateOfBlueBead == coordinateOfBlueBead.first &&yCoordinateOfBlueBead == coordinateOfBlueBead.second){
		return;
	}

	if (isRedBeadArrivedAtHole == true && isBlueBeadArrivedAtHole == false) {
		isSucceedGame = true;
	}
	else if (isRedBeadArrivedAtHole == false && isBlueBeadArrivedAtHole == false && currentMoveCount < MAX_MOVE_NUMBER) {
		pair<int, int> newCoordinateOfRedBead = make_pair(xCoordinateOfRedBead, yCoordinateOfRedBead);
		pair<int, int> newCoordinateOfBlueBead = make_pair(xCoordinateOfBlueBead, yCoordinateOfBlueBead);
		coordinateOfBeadAndMoveCount.push(make_tuple(newCoordinateOfRedBead, newCoordinateOfBlueBead, currentMoveCount));
	}
}

void leanSquareBoadToRight(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount) {
	int xCoordinateOfRedBead = coordinateOfRedBead.first;
	int yCoordinateOfRedBead = coordinateOfRedBead.second;
	int xCoordinateOfBlueBead = coordinateOfBlueBead.first;
	int yCoordinateOfBlueBead = coordinateOfBlueBead.second;

	currentMoveCount += 1;

	bool isRedBeadArrivedAtHole = false;
	bool isBlueBeadArrivedAtHole = false;

	while (squareBoard[xCoordinateOfRedBead][++yCoordinateOfRedBead] != '#') {
		if (squareBoard[xCoordinateOfRedBead][yCoordinateOfRedBead] == 'O') {
			isRedBeadArrivedAtHole = true;
		}
	}
	while (squareBoard[xCoordinateOfBlueBead][++yCoordinateOfBlueBead] != '#') {
		if (squareBoard[xCoordinateOfBlueBead][yCoordinateOfBlueBead] == 'O') {
			isBlueBeadArrivedAtHole = true;
		}
	}

	yCoordinateOfRedBead -= 1;
	yCoordinateOfBlueBead -= 1;

	if (xCoordinateOfRedBead == xCoordinateOfBlueBead && yCoordinateOfRedBead == yCoordinateOfBlueBead) {
		if (coordinateOfRedBead.second > coordinateOfBlueBead.second) {
			yCoordinateOfBlueBead -= 1;
		}
		else if (coordinateOfRedBead.second < coordinateOfBlueBead.second) {
			yCoordinateOfRedBead -= 1;
		}
	}

	if (xCoordinateOfRedBead == coordinateOfRedBead.first && yCoordinateOfRedBead == coordinateOfRedBead.second && xCoordinateOfBlueBead == coordinateOfBlueBead.first &&yCoordinateOfBlueBead == coordinateOfBlueBead.second) {
		return;
	}

	if (isRedBeadArrivedAtHole == true && isBlueBeadArrivedAtHole == false) {
		isSucceedGame = true;
	}
	else if (isRedBeadArrivedAtHole == false && isBlueBeadArrivedAtHole == false && currentMoveCount < MAX_MOVE_NUMBER) {
		pair<int, int> newCoordinateOfRedBead = make_pair(xCoordinateOfRedBead, yCoordinateOfRedBead);
		pair<int, int> newCoordinateOfBlueBead = make_pair(xCoordinateOfBlueBead, yCoordinateOfBlueBead);
		coordinateOfBeadAndMoveCount.push(make_tuple(newCoordinateOfRedBead, newCoordinateOfBlueBead, currentMoveCount));
	}
}

void leanSquareBoadToUp(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount) {
	int xCoordinateOfRedBead = coordinateOfRedBead.first;
	int yCoordinateOfRedBead = coordinateOfRedBead.second;
	int xCoordinateOfBlueBead = coordinateOfBlueBead.first;
	int yCoordinateOfBlueBead = coordinateOfBlueBead.second;

	currentMoveCount += 1;

	bool isRedBeadArrivedAtHole = false;
	bool isBlueBeadArrivedAtHole = false;

	while (squareBoard[--xCoordinateOfRedBead][yCoordinateOfRedBead] != '#') {
		if (squareBoard[xCoordinateOfRedBead][yCoordinateOfRedBead] == 'O') {
			isRedBeadArrivedAtHole = true;
		}
	}
	while (squareBoard[--xCoordinateOfBlueBead][yCoordinateOfBlueBead] != '#') {
		if (squareBoard[xCoordinateOfBlueBead][yCoordinateOfBlueBead] == 'O') {
			isBlueBeadArrivedAtHole = true;
		}
	}

	xCoordinateOfRedBead += 1;
	xCoordinateOfBlueBead += 1;

	if (xCoordinateOfRedBead == xCoordinateOfBlueBead && yCoordinateOfRedBead == yCoordinateOfBlueBead) {
		if (coordinateOfRedBead.first > coordinateOfBlueBead.first) {
			xCoordinateOfRedBead += 1;
		}
		else if (coordinateOfRedBead.first < coordinateOfBlueBead.first) {
			xCoordinateOfBlueBead += 1;
		}
	}

	if (xCoordinateOfRedBead == coordinateOfRedBead.first && yCoordinateOfRedBead == coordinateOfRedBead.second && xCoordinateOfBlueBead == coordinateOfBlueBead.first &&yCoordinateOfBlueBead == coordinateOfBlueBead.second) {
		return;
	}

	if (isRedBeadArrivedAtHole == true && isBlueBeadArrivedAtHole == false) {
		isSucceedGame = true;
	}
	else if (isRedBeadArrivedAtHole == false && isBlueBeadArrivedAtHole == false && currentMoveCount < MAX_MOVE_NUMBER) {
		pair<int, int> newCoordinateOfRedBead = make_pair(xCoordinateOfRedBead, yCoordinateOfRedBead);
		pair<int, int> newCoordinateOfBlueBead = make_pair(xCoordinateOfBlueBead, yCoordinateOfBlueBead);
		coordinateOfBeadAndMoveCount.push(make_tuple(newCoordinateOfRedBead, newCoordinateOfBlueBead, currentMoveCount));
	}
}

void leanSquareBoadToDown(pair<int, int> coordinateOfRedBead, pair<int, int> coordinateOfBlueBead, int currentMoveCount) {
	int xCoordinateOfRedBead = coordinateOfRedBead.first;
	int yCoordinateOfRedBead = coordinateOfRedBead.second;
	int xCoordinateOfBlueBead = coordinateOfBlueBead.first;
	int yCoordinateOfBlueBead = coordinateOfBlueBead.second;

	currentMoveCount += 1;

	bool isRedBeadArrivedAtHole = false;
	bool isBlueBeadArrivedAtHole = false;

	while (squareBoard[++xCoordinateOfRedBead][yCoordinateOfRedBead] != '#') {
		if (squareBoard[xCoordinateOfRedBead][yCoordinateOfRedBead] == 'O') {
			isRedBeadArrivedAtHole = true;
		}
	}
	while (squareBoard[++xCoordinateOfBlueBead][yCoordinateOfBlueBead] != '#') {
		if (squareBoard[xCoordinateOfBlueBead][yCoordinateOfBlueBead] == 'O') {
			isBlueBeadArrivedAtHole = true;
		}
	}

	xCoordinateOfRedBead -= 1;
	xCoordinateOfBlueBead -= 1;

	if (xCoordinateOfRedBead == xCoordinateOfBlueBead && yCoordinateOfRedBead == yCoordinateOfBlueBead) {
		if (coordinateOfRedBead.first > coordinateOfBlueBead.first) {
			xCoordinateOfBlueBead -= 1;
		}
		else if (coordinateOfRedBead.first < coordinateOfBlueBead.first) {
			xCoordinateOfRedBead -= 1;
		}
	}

	if (xCoordinateOfRedBead == coordinateOfRedBead.first && yCoordinateOfRedBead == coordinateOfRedBead.second && xCoordinateOfBlueBead == coordinateOfBlueBead.first &&yCoordinateOfBlueBead == coordinateOfBlueBead.second) {
		return;
	}

	if (isRedBeadArrivedAtHole == true && isBlueBeadArrivedAtHole == false) {
		isSucceedGame = true;
	}
	else if (isRedBeadArrivedAtHole == false && isBlueBeadArrivedAtHole == false && currentMoveCount < MAX_MOVE_NUMBER) {
		pair<int, int> newCoordinateOfRedBead = make_pair(xCoordinateOfRedBead, yCoordinateOfRedBead);
		pair<int, int> newCoordinateOfBlueBead = make_pair(xCoordinateOfBlueBead, yCoordinateOfBlueBead);
		coordinateOfBeadAndMoveCount.push(make_tuple(newCoordinateOfRedBead, newCoordinateOfBlueBead, currentMoveCount));
	}
}