//next_permutation �������ϱ�
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4 }; //������ ��������
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