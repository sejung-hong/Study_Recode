//next_permutation 순열구하기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4 }; //무조건 오름차순
	do {
		for (int i = 0; i < 4; i++) {
			cout << v[i] << " ";
		}
		cout << endl;

	} while (next_permutation(v.begin(), v.end()));

	cout << endl;
	v = { 4,3,2,1 };
	do {
		for (int i = 0; i < 4; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}