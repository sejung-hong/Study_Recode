//1934 최소공배수
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int A, B;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		int min = 0;
		if (A >= B)
			min = B;
		else
			min = A;

		for (int j = min; j > 0; j--) {
			if (A%j == 0 && B%j==0) {
				cout << A * (B / j) << "\n";
				break;
			}
		}
	}

	return 0;
}