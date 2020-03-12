//baekjoon #2156
//algorithm : dynamic programming

#include <iostream>
using namespace std;

const int MAX_NUMBER = 10000 + 1;
int quantityOfWine[MAX_NUMBER];
int maxQuantityOfDrinkWine[2][MAX_NUMBER];	//[0][currentWineGlass] : 지금 마시는 와인이 첫번째 잔인 경우
											//[1][currentWineGlass] : 지금 마시는 와인이 두번째 잔인 경우

int numberOfWineGlass;
int maxQuantityOfDrinkableWine;

void findMaxQuantityOfDrinkableWine();
void initMaxQuantityOfDrinkWine();
int getMaxQuantityOfPreviousDrinkWine(int currentWineGlass);

int main() {
	cin >> numberOfWineGlass;

	for (int i = 1; i <= numberOfWineGlass; i++) {
		cin >> quantityOfWine[i];
	}

	if (numberOfWineGlass == 1) {
		cout << quantityOfWine[1] << '\n';
	}
	else if (numberOfWineGlass == 2) {
		cout << quantityOfWine[1] + quantityOfWine[2] << '\n';
	}
	else {
		findMaxQuantityOfDrinkableWine();
		cout << maxQuantityOfDrinkableWine << '\n';
	}
}

void findMaxQuantityOfDrinkableWine() {
	initMaxQuantityOfDrinkWine();

	for (int i = 3; i <= numberOfWineGlass; i++) {
		maxQuantityOfDrinkWine[0][i] = getMaxQuantityOfPreviousDrinkWine(i) + quantityOfWine[i];
		maxQuantityOfDrinkWine[1][i] = maxQuantityOfDrinkWine[0][i - 1] + quantityOfWine[i];
	}

	for (int i = 1; i <= numberOfWineGlass; i++) {
		if (maxQuantityOfDrinkWine[0][i] > maxQuantityOfDrinkableWine) {
			maxQuantityOfDrinkableWine = maxQuantityOfDrinkWine[0][i];
		}

		if (maxQuantityOfDrinkWine[1][i] > maxQuantityOfDrinkableWine) {
			maxQuantityOfDrinkableWine = maxQuantityOfDrinkWine[1][i];
		}
	}
}

void initMaxQuantityOfDrinkWine() {
	maxQuantityOfDrinkWine[0][1] = quantityOfWine[1];
	maxQuantityOfDrinkWine[1][1] = quantityOfWine[1];
	maxQuantityOfDrinkWine[0][2] = quantityOfWine[2];
	maxQuantityOfDrinkWine[1][2] = quantityOfWine[1] + quantityOfWine[2];
}

int getMaxQuantityOfPreviousDrinkWine(int currentWineGlass) {
	if (maxQuantityOfDrinkWine[1][currentWineGlass - 3] > maxQuantityOfDrinkWine[0][currentWineGlass - 2] && maxQuantityOfDrinkWine[1][currentWineGlass - 3] > maxQuantityOfDrinkWine[1][currentWineGlass - 2]) {
		return maxQuantityOfDrinkWine[1][currentWineGlass - 3];
	}
	else if (maxQuantityOfDrinkWine[0][currentWineGlass - 2] > maxQuantityOfDrinkWine[1][currentWineGlass - 2]) {
		return maxQuantityOfDrinkWine[0][currentWineGlass - 2];
	}
	else {
		return maxQuantityOfDrinkWine[1][currentWineGlass - 2];
	}
}