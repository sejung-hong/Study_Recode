//2745 진법 변환
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int B;

	cin >> N >> B;

	int decimal = 0;
	int b = 1;

	for (int i = N.size() - 1; i >= 0; i--) {
		if (N[i] < 58) {
			decimal += b * (N[i]-48);
		}
		else {
			decimal += b * (N[i] - 55);
		}
		b *= B;
	}

	cout << decimal << "\n";

	return 0;
}