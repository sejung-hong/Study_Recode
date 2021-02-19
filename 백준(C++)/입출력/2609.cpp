//2609 최대공약수와 최소공배수
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int small = 0;
	int min, max;

	if (a < b)
		small = a;
	else
		small = b;

	for (int i = small; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			max = i;
			cout << max << endl;
			break;
		}
	}//최대공약수

	min = max * (a / max) * (b / max);
	cout << min << endl;
	//최소공배수

	return 0;
}