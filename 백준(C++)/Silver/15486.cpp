//น้มุ 15486 ล๐ป็2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum;
int N;
long long dp[500001];

void DP(vector<vector<int>>& v, int num, int day) {
	int check = 0;
	for (int i = day; i < v.size(); i++) {
		if (i + v[i][0] > N)
			continue;
		DP(v, num + v[i][1], i + v[i][0]);
		check = 1;
	}
	if (check == 0) {
		sum = max(sum, num);
		return;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<vector<int>> v(N);
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		v[i].push_back(T);
		v[i].push_back(P);
	}

	DP(v, 0, 0);

	cout << sum << "\n";

	return 0;
}