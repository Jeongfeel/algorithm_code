/*
	problem site	:	baekjoon
	problem number	:	1062
	problem name	:	가르침
	algorithm	:	brute force
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int COUNT_OF_ALPHABET = 26;

bool isReadableAlphabet[COUNT_OF_ALPHABET];

void initIsReadableAlphabet();
void checkMaximumReadableWord(int index, int count);
int getReadableWordCount();

int maximumReadableWord = 0;

int N, K;
vector<string> wordVector;
int main() {
	cin >> N >> K;

	if (K < 5) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		wordVector.push_back(word);
	}

	initIsReadableAlphabet();

	checkMaximumReadableWord(0, 0);
	cout << maximumReadableWord << '\n';
}

void initIsReadableAlphabet() {
	isReadableAlphabet['a' - 'a'] = true;
	isReadableAlphabet['n' - 'a'] = true;
	isReadableAlphabet['t' - 'a'] = true;
	isReadableAlphabet['i' - 'a'] = true;
	isReadableAlphabet['c' - 'a'] = true;
}

void checkMaximumReadableWord(int index, int count) {
	if (count == K - 5) {
		int count = getReadableWordCount();

		if (maximumReadableWord < count) {
			maximumReadableWord = count;
		}
	}
	else {
		for (int i = index; i < COUNT_OF_ALPHABET; i++) {
			if (isReadableAlphabet[i] == true) {
				continue;
			}

			isReadableAlphabet[i] = true;
			checkMaximumReadableWord(i + 1, count + 1);
			isReadableAlphabet[i] = false;
		}
	}
}

int getReadableWordCount() {
	int count = 0;

	for (int i = 0; i < wordVector.size(); i++) {
		bool isReadable = true;
		for (int j = 0; j < wordVector[i].size(); j++) {
			char alphabet = wordVector[i][j];			
			if (isReadableAlphabet[alphabet - 'a'] != true) {
				isReadable = false;
				break;
			}
		}

		if (isReadable == false) {
			continue;
		}

		count += 1;
	}

	return count;
}