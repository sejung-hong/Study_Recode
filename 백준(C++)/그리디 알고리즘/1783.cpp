//1783 병든 나이트
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	if (N == 1) {
		cout << "1" << endl;
	}
	else if (N == 2) {
		if ((M + 1) / 2 <= 4)
			cout << (M + 1) / 2 << endl;
		else
			cout << "4" << endl;
	}
	else {
		if (M < 7) {
			cout << min(4, M) << endl;
		}
		else
			cout << M - 2 << endl;
	}
	return 0;
}