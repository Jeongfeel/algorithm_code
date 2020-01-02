//Baekjoon #2309
//algorithm : brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> answer;
	vector<int> height;
	vector<int> permu_vector;

	for (int i = 0; i < 9; i++) {
		int number;
		cin >> number;

		height.push_back(number);

		if (i < 2)
			permu_vector.push_back(0);
		else
			permu_vector.push_back(1);
	}
	sort(height.begin(), height.end());

	do {
		int height_sum = 0;
		for (int i = 0; i < 9; i++) {
			if (permu_vector[i] == 1)
				height_sum += height[i];
		}

		if (height_sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (permu_vector[i] == 1)
					answer.push_back(height[i]);
			}
			
			break;
		}
	} while (next_permutation(permu_vector.begin(), permu_vector.end()));

	for (int i = 0; i < 7; i++)
		cout << answer[i] << "\n";
}