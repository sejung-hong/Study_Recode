//1850 최대공약수
#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;

	cin >> A >> B;

	long long result = GCD(A, B);

	for (int i = 0; i < result; i++) {
		cout << "1";
	}
	cout << "\n";

	return 0;
}