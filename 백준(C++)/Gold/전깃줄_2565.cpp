//น้มุ ภüฑ๊มู 2565
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		v.push_back({ A,B });
	}

	sort(v.begin(), v.end());

	int dp[500];
	int maxDp = 0;
	for (int i = 0; i < v.size(); i++ ) {
		int maxNum = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + 1;
		maxDp = max(maxDp, dp[i]);
	}

	cout << N - maxDp << "\n";

	return 0;
}