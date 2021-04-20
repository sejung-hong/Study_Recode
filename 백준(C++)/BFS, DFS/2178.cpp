//2178 ¹Ì·ÎÅ½»ö
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char miro[101][101];
bool visited[101][101] = { false, };
int num[101][101] = { 0, };
int N, M;
int dir_x[4] = { 1, 0, -1, 0 }, dir_y[4] = { 0, 1, 0, -1 };

void BFS(int x, int y) {
	visited[x][y] = true;
	num[x][y] ++;

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx < 0 || ny <0 || nx >= N || ny >= M)
				continue;
			if (visited[nx][ny] == false && miro[nx][ny] == '1') {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				num[nx][ny] = num[x][y] + 1;

			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> miro[i][j];
		}
	}

	BFS(0, 0);

	cout << num[N-1][M-1] << endl;


	return 0;
}