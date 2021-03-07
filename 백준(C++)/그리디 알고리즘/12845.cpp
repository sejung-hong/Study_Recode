//12845 모두의 마블
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector <int> L;

	cin >> n;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		L.push_back(num);
	}

	sort(L.begin(), L.end(), greater<>());
	
	int gold = 0;
	int max_level = L[0];
	for (int i = 1; i < L.size(); i++) {
		gold += max_level + L[i];
	}
	cout << gold << endl;

	return 0;
}