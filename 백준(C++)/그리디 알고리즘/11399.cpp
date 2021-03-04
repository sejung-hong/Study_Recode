//11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;

	vector <int> P;

	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		P.push_back(num);
	}
	
	int sum = 0;
	sort(P.begin(), P.end());

	int a = 0;
	for (int i = 0; i < N; i++) {
		sum += a + P[i];
		a += P[i];
	}

	cout << sum << endl;

	return 0;
}