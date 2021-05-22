//1676 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int num_zero = 0;
	while (N) {
		N /= 5;
		num_zero += N;
	}

	cout << num_zero << "\n";


	return 0;
}