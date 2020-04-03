/*
	problem site	:	baekjoon
	problem number	:	15686
	problem name	:	치킨 배달
	algorithm	:	brute force
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAX_NUMBER_OF_CITY = 50;
const int MAX_CHICKEN_RESTAURANT = 13;
const int BLANK = 0;
const int HOUSE = 1;
const int CHICKEN_RESTAURANT = 2;

int city[MAX_NUMBER_OF_CITY][MAX_NUMBER_OF_CITY];

void closedChickenRestaurant(int countOfCurrentClosedChickenRestaurant, int currentChickenRestauranttNumber, vector<pair<int,int>> chickenRestaurantCoordinateVector);
void checkChickenDistance(vector<pair<int, int>> chickenRestaurantCoordinateVector);

int resultOfChickenDistance = 1024 * 1024 * 1024 * 2 - 1;

int N, M;
int main() {
	cin >> N >> M;

	vector<pair<int, int>> chickenRestaurantCoordinateVector;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == CHICKEN_RESTAURANT) {
				pair<int, int> chickenRestaurantCoordinate = make_pair(i, j);
				chickenRestaurantCoordinateVector.push_back(chickenRestaurantCoordinate);
			}
		}
	}

	int numberOfClosedChickenRestaurant = chickenRestaurantCoordinateVector.size() - M + 1;
	closedChickenRestaurant(numberOfClosedChickenRestaurant, 0, chickenRestaurantCoordinateVector);

	cout << resultOfChickenDistance << '\n';
}

void closedChickenRestaurant(int countOfCurrentClosedChickenRestaurant, int currentChickenRestauranttNumber, vector<pair<int, int>> chickenRestaurantCoordinateVector) {
	countOfCurrentClosedChickenRestaurant -= 1;
	
	if (countOfCurrentClosedChickenRestaurant == 0) {
		checkChickenDistance(chickenRestaurantCoordinateVector);
	}
	else {
		for (int i = currentChickenRestauranttNumber; i < chickenRestaurantCoordinateVector.size(); i++) {
			int currentChickenRestaurantXCoordinate = chickenRestaurantCoordinateVector[i].first;
			int currentChickenRestaurantYCoordinate = chickenRestaurantCoordinateVector[i].second;

			if (city[currentChickenRestaurantXCoordinate][currentChickenRestaurantYCoordinate] == BLANK) {
				continue;
			}

			city[currentChickenRestaurantXCoordinate][currentChickenRestaurantYCoordinate] = BLANK;
			closedChickenRestaurant(countOfCurrentClosedChickenRestaurant, i + 1, chickenRestaurantCoordinateVector);
			city[currentChickenRestaurantXCoordinate][currentChickenRestaurantYCoordinate] = CHICKEN_RESTAURANT;
		}
	}
}

void checkChickenDistance(vector<pair<int, int>> chickenRestaurantCoordinateVector) {
	int sumOfChickenDistance = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (city[i][j] == HOUSE) {
				int minimumChickenDistance = 1024 * 1024 * 1024 * 2 - 1;
				for (int k = 0; k < chickenRestaurantCoordinateVector.size(); k++) {
					int currentChickenRestaurantXCoordinate = chickenRestaurantCoordinateVector[k].first;
					int currentChickenRestaurantYCoordinate = chickenRestaurantCoordinateVector[k].second;

					if (city[currentChickenRestaurantXCoordinate][currentChickenRestaurantYCoordinate] == BLANK) {
						continue;
					}

					int currentChickenDistance = abs(i - currentChickenRestaurantXCoordinate) + abs(j - currentChickenRestaurantYCoordinate);

					if (minimumChickenDistance > currentChickenDistance) {
						minimumChickenDistance = currentChickenDistance;
					}
				}

				sumOfChickenDistance += minimumChickenDistance;
			}
		}
	}

	if (resultOfChickenDistance > sumOfChickenDistance) {
		resultOfChickenDistance = sumOfChickenDistance;
	}
}