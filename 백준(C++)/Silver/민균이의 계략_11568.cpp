//πÈ¡ÿ 11568 πŒ±’¿Ã¿« ∞Ë∑´
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> card;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		card.push_back(num);
	}

	vector<int> dp(N, 1);

	int maxNum = 1;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (card[i] > card[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxNum = max(maxNum, dp[i]);
	}

	cout << maxNum << "\n";


	return 0;
}