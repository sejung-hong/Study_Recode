//백준 12865 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[101][100001] = { 0, };
int weight[101] = { 0, };
int value[101] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for(int j = 1; j <= K; j++) {
			if (j >= weight[i]) {
				DP[i][j] = max(DP[i-1][j], DP[i - 1][j - weight[i]] + value[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}

		}
	}
	
	cout << DP[N][K] << "\n";

	return 0;
}