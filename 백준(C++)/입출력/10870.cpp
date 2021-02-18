//10870 피보나치 수 5
#include <iostream>
using namespace std;

int pivo(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	return pivo(num - 2) + pivo(num - 1);
}

int main() {
	int n;
	int sum;

	cin >> n;

	sum = pivo(n);

	cout << sum << endl;

	return 0;
}