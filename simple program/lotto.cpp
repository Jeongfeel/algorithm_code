/*
	���� lotto number ���α׷�
*/

#include <iostream>
#include <ctime>
using namespace std;

const int MAX_NUMBER_OF_LOTTO = 45;
const int COUNT_OF_LOTTO_NUMBER = 6;

bool isCheckedLottoNumber[MAX_NUMBER_OF_LOTTO + 1];

void initLottoNumber();

int main() {
	cout << "��Ÿ� �����Ͻðڽ��ϱ� ? ";

	int numberOfLottoPaper;
	cin >> numberOfLottoPaper;

	cout << endl;

	cout << "�ζ� ��ȣ�� ����մϴ�.\n";

	srand((unsigned int)time(0));
	int startLottoPaper = 1;
	while (numberOfLottoPaper--) {
		initLottoNumber();
		
		cout << startLottoPaper << " ��° �ζ� ��ȣ�Դϴ�. \n";

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