//2581 ¼Ò¼ö
#include <iostream>
using namespace std;

int main() {
	int M, N;
	int sum = 0, min;

	cin >> M >> N;

	int check_prime;
	int check_min = 0;
	for (int i = M; i <= N; i++) {
		if (i == 1)
			continue;
		check_prime = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check_prime = 1;
				break;
			}
		}
		if (check_prime == 0) {
			sum += i;
			check_min++;
		}
		if (check_min == 1) {
			min = i;
			check_min++;
		}
	}

	if (sum == 0)
		cout << "-1" << endl;
	else
		cout << sum << endl << min << endl;

	return 0;
}