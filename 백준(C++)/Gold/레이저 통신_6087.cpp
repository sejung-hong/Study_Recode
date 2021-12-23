//백준 6087 레이저 통신
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


#define INF 100001

int W, H;
vector<string> board;
vector<pair<int, int>> cLocation;
int nexti[4] = { 0,0,1,-1 }, nextj[4] = { 1,-1,0,0 }; // 동,서,북,남
int mirror[101][101] = { 0, };

struct location {
	int i;
	int j;
	int preDirection; //이전 방향
	int mirrorNum;
};

void BFS(int i, int j) {
	queue<location> q;
	q.push({ i,j,-1,0 });
	mirror[i][j] = 0;

	while (!q.empty()) {
		int ci = q.front().i;
		int cj = q.front().j;
		int cDirection = q.front().preDirection;
		int cNum = q.front().mirrorNum;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = ci + nexti[k];
			int nj = cj + nextj[k];

			if (ni < 0 || nj < 0 || ni >= H || nj >= W) {
				continue;
			}
			if (board[ni][nj] == '*') {
				continue;
			}

			//처음 방향 없음
			if (cDirection == -1) {
				mirror[ni][nj] = mirror[ci][cj];
				q.push({ ni,nj, k, mirror[ni][nj]});
			}
			// 같은 방향
			else if (cDirection == k) {
				if ( mirror[ni][nj] >= cNum) {
					mirror[ni][nj] = cNum;
					q.push({ ni,nj, k, mirror[ni][nj]});
				}
			}
			// 다른 방향
			else if (cDirection != k) {
				if (mirror[ni][nj] >= cNum + 1) {
					mirror[ni][nj] = cNum + 1;
					q.push({ ni,nj, k, mirror[ni][nj]});
				}
			}
		}
	}
}

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		string s = "";
		for (int j = 0; j < W; j++) {
			char c;
			cin >> c;
			s += c;
			if (c == 'C') {
				cLocation.push_back({ i,j });
			}
			mirror[i][j] = INF;
		}
		board.push_back(s);
	}

	BFS(cLocation[0].first, cLocation[0].second);
	cout << mirror[cLocation[1].first][cLocation[1].second] << "\n";

	return 0;
}