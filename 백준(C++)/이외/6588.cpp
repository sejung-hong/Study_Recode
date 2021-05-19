//6588 °ñµå¹ÙÈåÀÇ ÃßÃø
#include <iostream>
#include <cmath>
using namespace std;

bool Prime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}

		int check = 0;

		for (int i = 3; i < n; i+=2) {
			if (Prime(i) && Prime(n-i)) {
				cout << n << " = " << i << " + " << n-i << "\n";
				check = 1;
				break;
			}
		}

		if (check == 0) {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}

	}

	return 0;
}