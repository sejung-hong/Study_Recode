//9613 GCD гу
#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return GCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, num;
	long long sum;
	int arr[101];

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			for (int k = 0; k < j; k++) {
				sum += GCD(arr[k], arr[j]);
			}
		}

		cout << sum << "\n";
	}
	return 0;
}