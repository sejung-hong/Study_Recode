//백준 16948 데스 나이트
#include <iostream>
#include <queue>

using namespace std;

int N;
int r1, c1, r2, c2;
int visit[201][201] = { 0, };
int minMove = -1;
int dis[6][2] = { {-2, -1}, {-2, 1}, {0,-2}, {0,2}, {2, -1}, {2, 1} };

bool isMove(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N) {
		return false;
	}

	return true;
}

void BFS() {
	queue<pair<pair<int, int>, int>> q; // r, c, move;
	q.push({ {r1, c1}, 0 });
	visit[r1][c1] = 1;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int move = q.front().second;
		q.pop();

		if (r == r2 && c == c2) {
			minMove = move;
			break;
		}

		for (int i = 0; i < 6; i++) {
			int nextr = r + dis[i][0];
			int nextc = c + dis[i][1];
			if (isMove(nextr, nextc) && visit[nextr][nextc] == 0) {
				visit[nextr][nextc] = 1;
				q.push({ { nextr, nextc }, move + 1 });
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> r1 >> c1 >> r2 >> c2;

	BFS();

	cout << minMove << "\n";

	return 0;
}