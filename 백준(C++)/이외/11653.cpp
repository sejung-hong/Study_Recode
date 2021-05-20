//11653 소인수분해
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	cin >> N;

	while (N != 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				cout << i << "\n";
				N /= i;
				break;
			}
		}
	}

	return 0;
}