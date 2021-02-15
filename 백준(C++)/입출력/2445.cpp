//2445 º°Âï±â-8
#include <iostream>
using namespace std;

int main() {
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		for (int k = N; k > i + 1; k--) {
			cout << "  ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; j > i; j--)
			cout << "*";
		for (int k = 0; k < i + 1; k++)
			cout << "  ";
		for (int j = N - 1; j > i; j--)
			cout << "*";
		cout << endl;
	}

	return 0;
}