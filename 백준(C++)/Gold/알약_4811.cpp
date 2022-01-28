//백준 4811 알약
#include <iostream>

using namespace std;

long long pill[31][31] = { 0, };

long long DP(int w, int h) {
	//잘못된 입력
	if (w < 0) {
		return 0;
	}
	if (w == 1 && h == 0) {
		return 1;
	}
	//이미 구해진 n
	if (pill[w][h] > 0) {
		return pill[w][h];
	}

	if (w == 0 && h == 0){
		return 1;
	}
	if (w > 0) {
		pill[w][h] += DP(w - 1, h + 1);
	}
	if (h > 0) {
		pill[w][h] += DP(w, h - 1);
	}
	return pill[w][h];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		cout << DP(n, 0) << "\n";
	}

	return 0;
}