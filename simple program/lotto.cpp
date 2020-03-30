/*
	간단 lotto number 프로그램
*/

#include <iostream>
#include <ctime>
using namespace std;

const int MAX_NUMBER_OF_LOTTO = 45;
const int COUNT_OF_LOTTO_NUMBER = 6;

bool isCheckedLottoNumber[MAX_NUMBER_OF_LOTTO + 1];

void initLottoNumber();

int main() {
	cout << "몇매를 구매하시겠습니까 ? ";

	int numberOfLottoPaper;
	cin >> numberOfLottoPaper;

	cout << endl;

	cout << "로또 번호를 출력합니다.\n";

	srand((unsigned int)time(0));
	int startLottoPaper = 1;
	while (numberOfLottoPaper--) {
		initLottoNumber();
		
		cout << startLottoPaper << " 번째 로또 번호입니다. \n";

		for (int i = 1; i <= COUNT_OF_LOTTO_NUMBER; i++) {
			int lottoNumber = rand() % (44 + 1) + 1;
			
			while (isCheckedLottoNumber[lottoNumber]) {
				lottoNumber = rand() % (44 + 1) + 1;
			}
			
			isCheckedLottoNumber[lottoNumber] = true;

			cout << lottoNumber << '\t';
		}

		startLottoPaper += 1;

		cout << endl;
	}
}

void initLottoNumber() {
	for (int i = 1; i <= MAX_NUMBER_OF_LOTTO; i++) {
		isCheckedLottoNumber[i] = false;
	}
}