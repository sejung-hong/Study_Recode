//백준 14226 이모티콘
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dp[2001][2001];

int BFS(int S) {

	dp[1][0] = 0;
	queue<pair<int, int>> q;
	q.push({ 1,0 });

	int res = 987654321;
	while (!q.empty()) {
		int x = q.front().first;
		int clip = q.front().second;
		int time = dp[x][clip];
		q.pop();
		if (x == S) {
			return time;
		}
		//복사
		if (dp[x][x] == -1) {
			dp[x][x] = time + 1;
			q.push({ x,x });
		}
		//붙여넣기
		if (x + clip <= S && dp[x + clip][clip] == -1) {
			q.push({ x + clip, clip });
			dp[x + clip][clip] = time + 1;
		}
		//삭제
		if (x - 1 >= 0 && dp[x - 1][clip] == -1) {
			dp[x - 1][clip] = time + 1;
			q.push({ x - 1, clip });
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S;
	cin >> S;

	memset(dp, -1, sizeof(dp));

	cout << BFS(S) << "\n";

	return 0;
}