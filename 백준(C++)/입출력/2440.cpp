//2440 º°Âï±â-3
#include <iostream>
using namespace std;

int main() {
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = N; j > i; j--) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}