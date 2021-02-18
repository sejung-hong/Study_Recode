//2309 일곱 난쟁이
#include <iostream>
#include <algorithm> //sort 정렬 사용
#include <vector>
using namespace std;

int main() {
	int dwarf[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	sum -= 100;

	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (i == j)
				break;
			if (sum == dwarf[i] + dwarf[j]) {
				dwarf[i] = 100;
				dwarf[j] = 100;
				sort(dwarf, dwarf + 9);
				for (int i = 0; i < 7; i++) {
					cout << dwarf[i] << endl;
				}
				return 0;
			}
		}
	}

	return 0;
}
/*
int main() {
	vector<int> dwarf;
	int sum = 0;

	int a = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		dwarf.push_back(a);
		sum += a;
	}

	sum -= 100;

	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (i == j)
				break;
			if (sum == dwarf[i] + dwarf[j]) {
				dwarf[i] = 100;
				dwarf[j] = 100;
				sort(dwarf.begin(), dwarf.end());
				for (int i = 0; i < 7; i++) {
					cout << dwarf[i] << endl;
				}
				return 0;
			}
		}
	}

	return 0;
}*/